#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/gpio.h"
#include "led.h"
#include "beep.h"
#include "btn.h"

void led_task(void* param)
{
     unsigned char key_num = 0 ;
     while(1)
     {
         key_num = key_scan();
          if(key_num == 1)
          {
               led_toggle(GPIO_NUM_3);
          } 
          vTaskDelay(5);
     }
}

void key_task(void *param)
{
     while (1)
     {
          beep_toggle(GPIO_NUM_15);
          vTaskDelay(1);
     }
}

void app_main(void)
{
    led_init();
    beep_init();
    key_init();

    xTaskCreatePinnedToCore(led_task,"led_task",1024,NULL,1,NULL,0);
    xTaskCreatePinnedToCore(key_task,"key_task",1024,NULL,2,NULL,0);
}