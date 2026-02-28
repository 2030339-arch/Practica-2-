# ESP32 LED Control con FreeRTOS Timers

Este proyecto implementa un sistema de control de parpadeo para un LED utilizando el framework **ESP-IDF**. La lógica principal se basa en un **Software Timer** de FreeRTOS, lo que permite una ejecución precisa sin bloquear el hilo principal de la aplicación.

---

## Descripción del Proyecto

El código configura el **GPIO 2** (comúnmente el LED integrado en placas DevKit) y utiliza un temporizador que se dispara cada **1000ms**. Además, demuestra el uso avanzado de los niveles de log de ESP32 para monitorear el estado del sistema.

### Funcionalidades Clave

* **Inicialización Segura:** Uso de `esp_err_t` para verificar que el hardware se configure correctamente.
* **Temporización no Bloqueante:** Implementación de `xTimerCreate` para manejar el parpadeo.
* **Ciclo de Logs Dinámico:** El sistema alterna mensajes de `INFO`, `WARNING` y `ERROR` basándose en un contador interno (`count`).

---

## Estructura del Código

El flujo de ejecución se divide en tres componentes principales:

1. **`init_led()`**: Inicializa el pin de salida y valida la configuración con `ESP_ERROR_CHECK`.
2. **`blink_led()`**: Cambia el estado lógico del pin (0 o 1) y reporta el éxito o fallo a la consola.
3. **`timer_callback()`**: Es el corazón del programa. Se ejecuta automáticamente cada segundo para llamar a la función de parpadeo y gestionar la lógica de los logs.



