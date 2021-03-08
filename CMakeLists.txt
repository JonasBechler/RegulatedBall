cmake_minimum_required (VERSION 3.12)
set(PICO_SDK_FETCH_FROM_GIT on)


project (RegulatedBall)

add_library(VL53L0X INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/lib/VL53L0X/VL53L0X.cpp
    ${CMAKE_CURRENT_LIST_DIR}/lib/VL53L0X/VL53L0X.h
)


target_compile_definitions(VL53L0X INTERFACE MY_DEFINE=3)

add_executable(RegulatedBall
	RegulatedBall.c)

#pico_generate_pio_header(RegulatedBall ${CMAKE_CURRENT_LIST_DIR}/RegulatedBall.pio)



target_include_directories(VL53L0X INTERFACE S{CMAKE_CURRENT_LIST_DIR}/lib/VL53L0X)

target_link_libraries(RegulatedBall PRIVATE
	pico_stdlib
	pico_multicore
	hardware_pio
	hardware_irq
	hardware_pwm
	hardware_i2c
	VL53L0X
	
)

# enable usb output, disable uart output
pico_enable_stdio_usb(RegulatedBall 1)
pico_enable_stdio_uart(RegulatedBall 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(RegulatedBall)

# add url via pico_set_program_url
example_auto_set_url(RegulatedBall)
