/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
//#include "pico/multicore.h"
//#include "hardware/irq.h"
#include "hardware/clocks.h"
//#include "hardware/pwm.h"
#include "hardware/i2c.h"
#include "lib/VL53L0X/VL53L0X.hpp"

//#include "stepper.pio.h"

void core1_main()
{
}

bool reserved_addr(uint8_t addr)
{
    return (addr & 0x78) == 0 || (addr & 0x78) == 0x78;
}

int main()
{
    stdio_init_all();
    sleep_ms(1000);
    i2c_init(i2c0, 100 * 1000);
    gpio_set_function(4, GPIO_FUNC_I2C);
    gpio_set_function(5, GPIO_FUNC_I2C);
    gpio_pull_up(4);
    gpio_pull_up(5);

    uint8_t rxdata[2];
    int i2c_resp;

    while (true)
    {

        sleep_ms(100);
        i2c_resp = i2c_read_blocking(i2c0, 0x29, &rxdata[0], 2, false);
        if (i2c_resp == PICO_ERROR_GENERIC)
        {
            printf("error \n");
        }
        else
        {
            printf("%i, %i \n", rxdata[0], rxdata[1]);
        }
    }

    printf("Done.\n");
    return 0;
}
