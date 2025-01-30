idf_component_register(SRCS "main.cpp" "gpio_control.cpp"
                       INCLUDE_DIRS "."
                       REQUIRES driver
                       REQUIRES esp_timer
                       REQUIRES esp_wifi
                       REQUIRES nvs_flash
                       )
