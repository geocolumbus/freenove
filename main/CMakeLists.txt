idf_component_register(SRCS "main.cpp"
                       INCLUDE_DIRS "."
                       REQUIRES driver esp_timer esp_wifi nvs_flash
                       )
