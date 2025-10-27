#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/gpio.h"
#include "led.h"
#include "beep.h"
#include "btn.h"

void app_main(void)
{
    led_init();
    beep_init();
    key_init();

    unsigned char key_num = 0;
    while(1) {
        key_num = key_scan();
        if(key_num == 1)
        {
            led_toggle(GPIO_NUM_3);
            ESP_LOGI("main:", "key 1.\n");
        }
        else if(key_num == 2)
        {
             led_toggle(GPIO_NUM_3);
             ESP_LOGI("main:", "key 2.\n");
        }
        vTaskDelay(5);
    }
}