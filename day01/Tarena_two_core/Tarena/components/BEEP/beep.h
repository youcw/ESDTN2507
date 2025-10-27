#ifndef __BEEP_H
#define __BEEP_H

#include "driver/gpio.h"
#include "esp_log.h"

void beep_init(void);
void beep_toggle(gpio_num_t);

#endif 