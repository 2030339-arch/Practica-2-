#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"

#define LOG_LOCAL_LEVEL ESP_LOG_DEBUG
#include "esp_log.h"
#include "esp_err.h"

#define LED 2

#define CURRENT_LOG_LEVEL ESP_LOG_DEBUG   
static uint8_t led_level = 0;
static uint8_t count = 0;
static const char *TAG = "hernan";

static TimerHandle_t led_timer = NULL;



esp_err_t init_led(void)
{
    gpio_reset_pin(LED);
    esp_err_t err = gpio_set_direction(LED, GPIO_MODE_OUTPUT);

    if (err == ESP_OK) {
        ESP_LOGI(TAG, "El led se inicializo correctamente en GPIO %d", LED);
        ESP_LOGD(TAG, "Debug: init_led() regreso ESP_OK");
    } else {
        ESP_LOGE(TAG, "Fallo la inicializacion del led");
    }

    return err;
}


esp_err_t blink_led(void)
{
    led_level = !led_level;

    esp_err_t err = gpio_set_level(LED, led_level);

    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Error al cambiar el estado del LED");
        return err;
    }

    ESP_LOGD(TAG, "Debug: siguiente estado=%u", led_level);
    ESP_LOGI(TAG, "Estado del LED cambio correctamente");

    return ESP_OK;
}



void timer_callback(TimerHandle_t xTimer)
{
    if (blink_led() != ESP_OK) {
        ESP_LOGE(TAG, "Error en blink_led()");
    }

    ESP_LOGI(TAG, "Estado actual del LED: %u", led_level);

    count++;

    if (count > 30) count = 0;

    if (count < 10) {
        ESP_LOGI(TAG, "LOG DE INFO");
    }
    else if (count < 20) {
        ESP_LOGW(TAG, "LOG DE WARNING");
    }
    else {
        ESP_LOGE(TAG, "LOG DE ERROR");
    }
}



void app_main(void)
{
    
    esp_log_level_set(TAG, CURRENT_LOG_LEVEL);

    ESP_ERROR_CHECK(init_led());


    led_timer = xTimerCreate(
        "LedTimer",                   
        pdMS_TO_TICKS(1000),           
        pdTRUE,                       
        NULL,                          
        timer_callback                 
    );

    if (led_timer == NULL) {
        ESP_LOGE(TAG, "No se pudo crear el Timer");
        return;
    }

    if (xTimerStart(led_timer, 0) != pdPASS) {
        ESP_LOGE(TAG, "No se pudo iniciar el Timer");
        return;
    }

    ESP_LOGI(TAG, "Sistema iniciado correctamente con Timer");

    
}