// filepath: /Users/georgecampbell/esp/freenove/main/AppWifi.hpp
#pragma once

#include <cstring>
#include <functional>
#include <string>
#include "esp_wifi.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "nvs_flash.h"

namespace app {
    using OnWifiConnected_f = std::function<void(esp_ip4_addr_t *)>;
    using OnWifiDisconnected_f = std::function<void(void)>;

    class AppWifi {
    private:
        OnWifiConnected_f m_connected;
        OnWifiDisconnected_f m_disconnected;
        static void handleWifiEvent(void *arg, esp_event_base_t event_base, int32_t event_id, void *event_data);

    public:
        void init(OnWifiConnected_f conn, OnWifiDisconnected_f disc);
        void connect(void);
    };
}