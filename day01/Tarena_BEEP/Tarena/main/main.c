#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/gpio.h"
#include "led.h"
#include "beep.h"

void app_main(void)
{
    led_init();
    beep_init();

    while(1) {
        beep_toggle(GPIO_NUM_15);
        vTaskDelay(1);
    }
}