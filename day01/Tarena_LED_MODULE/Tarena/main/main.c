#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/gpio.h"
#include "led.h"

void app_main(void)
{
    led_init();

    while(1) {
        led_toggle(GPIO_NUM_3);
        vTaskDelay(1000);
    }
}