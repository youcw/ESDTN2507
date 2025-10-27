#include "led.h"

void led_init(void) {
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
}

void led_toggle(gpio_num_t num) {
    gpio_set_level(num, !gpio_get_level(num));
}
