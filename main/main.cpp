#include <cinttypes>
#include <iostream>
#include "freertos/FreeRTOS.h"
#include "esp_log.h"
#include "gpio_control.hpp"
#include "AppWifi.hpp"

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
    configure_gpio_pins_as_output(); 
    setup_periodic_timer();        

    app_wifi.init(connected, disconnected);
    app_wifi.connect();
}

bool tick = true;

void loop() {
    std::cout << (tick ? "tick\n" : "       tock\n");
    tick = !tick;
    vTaskDelay(1000 / portTICK_PERIOD_MS); // Delay for 1 second
}

extern "C" void app_main(void) {
    setup(); // Call the setup function once

    while (1) {
        loop(); // Call the loop function repeatedly
    }
}