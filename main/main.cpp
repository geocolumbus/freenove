#include "freertos/FreeRTOS.h"
#include "gpio_control.h"
#include <iostream>

#include "AppWifi.hpp"
#include "esp_log.h"
#include <cinttypes>

#define TAG "app"

namespace {
app::AppWifi app_wifi;
}

auto connected = [](esp_ip4_addr_t *ip) {
    ESP_LOGI(TAG, ">>>>>>> connected");
};

auto disconnected = []() {
    ESP_LOGW(TAG, ">>>>>>> disconnected");
};

void setup() {
    std::cout << "\nSerial port works.\n";
    configure_gpio_pins_as_output(); // Your GPIO configuration function
    setup_periodic_timer();          // Your timer setup function

    app_wifi.init(connected, disconnected);
    app_wifi.connect();
}

void loop() {
    std::cout << "Slow tick\n";
    vTaskDelay(1000 / portTICK_PERIOD_MS); // Delay for 1 second
}

extern "C" void app_main(void) {
    setup(); // Call the setup function once

    while (1) {
        loop(); // Call the loop function repeatedly
    }
}