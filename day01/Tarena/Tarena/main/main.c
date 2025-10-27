#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

void app_main(void)
{
    while (1)
    {
        ESP_LOGI("main", "hello,world\n");
        ESP_LOGE("main", "hello,world\n");
        printf("hello,world\n");
        vTaskDelay(1000);
    }
    
}