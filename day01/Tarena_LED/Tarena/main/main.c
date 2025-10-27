#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/gpio.h"

void app_main(void)
{
    esp_err_t err;

    gpio_config_t gpio_cfg = {
        .intr_type = GPIO_INTR_DISABLE,
        .mode = GPIO_MODE_INPUT_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .pin_bit_mask = 1 << GPIO_NUM_3
    };

    err = gpio_config(&gpio_cfg);
    if(err != ESP_OK) {
        ESP_LOGE("main", "GPIO3 config failed.\n");
    }

    while(1) {
        gpio_set_level(GPIO_NUM_3, 1);
        vTaskDelay(1000);
        gpio_set_level(GPIO_NUM_3, 0);
        vTaskDelay(1000);
    }
}