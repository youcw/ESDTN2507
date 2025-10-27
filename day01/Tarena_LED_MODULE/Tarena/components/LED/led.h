#ifndef __LED_H_
#define __LED_H_

#include "driver/gpio.h"
#include "esp_log.h"

extern void led_init(void);
extern void led_toggle(gpio_num_t);

#endif 