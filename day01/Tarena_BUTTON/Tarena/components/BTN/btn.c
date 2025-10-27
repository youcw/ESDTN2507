#include "btn.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

void key_init(void)
{
    gpio_config_t gpio_structure = {
        .intr_type = GPIO_INTR_DISABLE,
        .mode = GPIO_MODE_INPUT,
        .pin_bit_mask = (1ull<<GPIO_NUM_1)|(1ull<<GPIO_NUM_38),
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .pull_up_en = GPIO_PULLUP_ENABLE,
    };
    gpio_config(&gpio_structure);
}

unsigned char key_scan(void)
{
    unsigned char key_num = 0 ;
    if(gpio_get_level(GPIO_NUM_1) == 0)
    {
        vTaskDelay(20);
        while(gpio_get_level(GPIO_NUM_1) == 0); 
        vTaskDelay(20);
        key_num = 1;
    }
    if(gpio_get_level(GPIO_NUM_38) == 0)
    {
        vTaskDelay(20);
        while(gpio_get_level(GPIO_NUM_38) == 0); 
        vTaskDelay(20);
        key_num = 2;
    }
    return key_num;
}