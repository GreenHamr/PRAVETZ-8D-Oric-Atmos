# Generated Cmake Pico project file
set(TARGET_NAME 8D-FDD-Logic)
#set(WIZNET_CHIP W5100S)
#set(WIZNET_CHIP W5500)

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# initalize pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "/home/pico/pico/pico-sdk")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)
#include(pico_extras_import.cmake)

#include(rp2040_hat_c_sdk_version.cmake)
#include(rp2040_hat_c-patch.cmake)


project(${TARGET_NAME} C CXX ASM)

set(PICO_CXX_ENABLE_EXCEPTIONS 1)  #green

#set(PICO_CXX_ENABLE_RTTI 1)   #green

#add_compile_options(--CFG_TUSB_CONFIG_FILE=${CMAKE_CURRENT_LIST_DIR}/tusb_config.h)



# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

#add_subdirectory(pico-ssd1306)
#add_subdirectory(/home/pico/pico-arduino-compat/libs/mfrc522 build_pac-mfrc522)
#add_subdirectory(/home/pico/pico-arduino-compat/libs/adafruit-mfrc630-rfid build_pac-adafruit-mfrc630-rfid)

# Add executable. Default name is the project name, version 0.1
add_executable(${TARGET_NAME} ${TARGET_NAME}.cpp
#                usb_descriptors.c
#                MyButtonClass.cpp
#                WS2812.cpp
        )

     
#pico_generate_pio_header(${TARGET_NAME} ${CMAKE_CURRENT_LIST_DIR}/WS2812.pio)
# Create C header file with the name <pio program>.pio.h
pico_generate_pio_header(${TARGET_NAME} ${CMAKE_CURRENT_LIST_DIR}/pio/extra16kRAM.pio)


pico_set_program_name(${TARGET_NAME} ${TARGET_NAME})
pico_set_program_version(${TARGET_NAME} "0.0.1")

pico_enable_stdio_uart(${TARGET_NAME} 0)
pico_enable_stdio_usb(${TARGET_NAME} 0) # usb to rs virtual com port console

#target_include_directories(${TARGET_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/fonts)
#target_include_directories(${TARGET_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})
#target_include_directories(LEDBoardGreen INTERFACE ${CMAKE_CURRENT_LIST_DIR}/fonts)

#include(wizNet.cmake)

# Add the standard library to the build
target_link_libraries(${TARGET_NAME} PUBLIC 
                            pico_stdlib 
#                            arduino-compat
#                            pac-mfrc522
#                            pac-adafruit-mfrc630-rfid
#                            hardware_i2c 
                            hardware_pio
                            pico_multicore
#                            pico_ssd1306 
#                            pico_unique_id
                            #irq
#                            tinyusb_device tinyusb_board
#                            hardware_spi
#                            hardware_dma
 #                           ETHERNET_FILES
 #                           IOLIBRARY_FILES
                    #        TIMER_FILES
                    #        W5100S_FILES 
                    #        W5500_FILES 
#                            LOOPBACK_FILES 
                    #        DHCP_FILES 
                    #        DNS_FILES 
                    #        FTPCLIENT_FILES 
                    #        FTPSERVER_FILES 
                    #        HTTPSERVER_FILES 
                    #        MQTT_FILES 
                    #        SNTP_FILES 
                    
                    )


pico_add_extra_outputs(${TARGET_NAME})


