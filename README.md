# ESP32 LED Control con FreeRTOS Timers

Este proyecto implementa un sistema de control de parpadeo para un LED utilizando el framework **ESP-IDF**. La lógica principal se basa en un **Software Timer** de FreeRTOS, lo que permite una ejecución precisa sin bloquear el hilo principal de la aplicación.

---

## Ubicación del Código Principal

Si deseas revisar o modificar la lógica del parpadeo y los timers, el archivo principal se encuentra en:
**`main/blink_timer_led.c`** *(Nota: En proyectos ESP-IDF, la carpeta `main` es donde reside toda la lógica de la aplicación).*

---

## Estructura del Proyecto

Para entender cómo está organizado este repositorio, aquí tienes los archivos clave:

* **`main/`**: Carpeta que contiene el código fuente.
    * `blink_timer_led.c`: **Código principal** (configuración de GPIO, Timer y Logs).
    * `CMakeLists.txt`: Archivo de configuración para la compilación del módulo main.
* **`CMakeLists.txt`**: Archivo de configuración global del proyecto.
* **`README.md`**: Este archivo con las instrucciones.

---

## Funcionamiento del Código

El flujo de ejecución se divide en tres componentes principales dentro de `blink_timer_led.c`:

1.  **`init_led()`**: Inicializa el pin de salida (GPIO 2) y valida la configuración.
2.  **`blink_led()`**: Cambia el estado lógico del pin (0 o 1) y reporta el éxito o fallo a la consola.
3.  **`timer_callback()`**: Función que el Timer de FreeRTOS llama cada **1000ms** para ejecutar el parpadeo y rotar los niveles de logs.

---

## Niveles de Log Visibles en Consola

El sistema alterna mensajes automáticamente según el contador interno:
* **Verde (INFO)**: Ciclos 0-9.
* **Amarillo (WARN)**: Ciclos 10-19.
* **Rojo (ERROR)**: Ciclos 20-30.


