#include "gpio_control.h"
#include <stdio.h>

// These are the pins that can be set to outputs
const gpio_num_t gpio_pins[] = {
    GPIO_NUM_32, // PIN08_IO32
    GPIO_NUM_33, // PIN09_IO33
    GPIO_NUM_25, // PIN10_IO25
    GPIO_NUM_26, // PIN11_IO26
    GPIO_NUM_27, // PIN12_IO27
    GPIO_NUM_14, // PIN13_IO14
    GPIO_NUM_12, // PIN14_IO12
    GPIO_NUM_13, // PIN16_IO13
    GPIO_NUM_15, // PIN23_IO15
    GPIO_NUM_2,  // PIN24_IO02
    GPIO_NUM_0,  // PIN25_IO00
    GPIO_NUM_4,  // PIN26_IO04
    GPIO_NUM_16, // PIN27_IO16
    GPIO_NUM_17, // PIN28_IO17
    GPIO_NUM_5,  // PIN29_IO05
    GPIO_NUM_18, // PIN30_IO18
    GPIO_NUM_19, // PIN31_IO19
    GPIO_NUM_22, // PIN36_IO22
    GPIO_NUM_23  // PIN37_IO23
};

void configure_gpio_pins_as_output() {
    size_t num_pins = sizeof(gpio_pins) / sizeof(gpio_pins[0]);

    for (size_t i = 0; i < num_pins; i++) {
        esp_err_t ret = gpio_set_direction(gpio_pins[i], GPIO_MODE_OUTPUT);
        if (ret != ESP_OK) {
            printf("Failed to set direction for GPIO %d\n", gpio_pins[i]);
        }
    }
}

void turn_on_all_gpio_outputs() {
    size_t num_pins = sizeof(gpio_pins) / sizeof(gpio_pins[0]);

    for (size_t i = 0; i < num_pins; i++) {
        esp_err_t ret = gpio_set_level(gpio_pins[i], 1);
        if (ret != ESP_OK) {
            printf("Failed to set high level for GPIO %d\n", gpio_pins[i]);
        }
    }
}

void turn_off_all_gpio_outputs() {
    size_t num_pins = sizeof(gpio_pins) / sizeof(gpio_pins[0]);

    for (size_t i = 0; i < num_pins; i++) {
        esp_err_t ret = gpio_set_level(gpio_pins[i], 0);
        if (ret != ESP_OK) {
            printf("Failed to set low level for GPIO %d\n", gpio_pins[i]);
        }
    }
}

static bool gpio_state = false;
static esp_timer_handle_t periodic_timer;

static void timer_callback(void *arg) {
    if (gpio_state) {
        turn_off_all_gpio_outputs();
    } else {
        turn_on_all_gpio_outputs();
    }
    gpio_state = !gpio_state;
}

void setup_periodic_timer() {
    const esp_timer_create_args_t periodic_timer_args = {
        .callback = &timer_callback,
        .name = "gpio_toggle_timer"};

    esp_timer_create(&periodic_timer_args, &periodic_timer);
    esp_timer_start_periodic(periodic_timer, 250000);
}
