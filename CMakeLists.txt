# For more information about build system see
# https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html
# The following five lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.10)

if(DEFINED ENV{WIFI_SSID})
  add_compile_options(-DWIFI_SSID=\"$ENV{WIFI_SSID}\" )
else()
  message(FATAL_ERROR "WiFi SSID is needed")
endif()

if(DEFINED ENV{WIFI_PASSWORD})
  add_compile_options(-DWIFI_PASSWORD=\"$ENV{WIFI_PASSWORD}\" )
else()
  message(FATAL_ERROR "WiFi password is needed")
endif()

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(freenove)
