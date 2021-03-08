cmake_minimum_required (VERSION 3.12)


add_subdirectory(lib/VL53L0X)

project (RegulatedBall)




add_executable(RegulatedBall
	RegulatedBall.c)

#pico_generate_pio_header(RegulatedBall ${CMAKE_CURRENT_LIST_DIR}/RegulatedBall.pio)




target_link_libraries(RegulatedBall
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
