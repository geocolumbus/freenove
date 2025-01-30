#include "driver/gpio.h"
#include "esp_timer.h"

extern const gpio_num_t gpio_pins[];

void configure_gpio_pins_as_output();
void turn_on_all_gpio_outputs();
void turn_off_all_gpio_outputs();
void setup_periodic_timer();
