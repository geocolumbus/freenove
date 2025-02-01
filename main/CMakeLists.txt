idf_component_register(SRCS "main.cpp" "gpio/gpio_control.cpp" "wifi/AppWifi.cpp"
                       INCLUDE_DIRS "." "gpio" "wifi"
                       REQUIRES driver esp_timer esp_wifi nvs_flash
                       )
