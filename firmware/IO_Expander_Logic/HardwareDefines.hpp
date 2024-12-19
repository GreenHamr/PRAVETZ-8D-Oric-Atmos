#ifndef HARDWARE_DEFINES_H_
#define HARDWARE_DEFINES_H_

#include "hardware/vreg.h"


#define CPU_SPEED 1

#if CPU_SPEED == 1 
    #define CPU_CLOCK_FREQ 200000
    #define CPU_VOLTAGE VREG_VOLTAGE_1_00
#elif CPU_SPEED == 2
    #define CPU_CLOCK_FREQ  250000
    #define CPU_VOLTAGE VREG_VOLTAGE_1_10
#elif CPU_SPEED == 3
    #define CPU_CLOCK_FREQ 290400
    #define CPU_VOLTAGE VREG_VOLTAGE_1_20
#elif CPU_SPEED == 4
    #define CPU_CLOCK_FREQ 350000
    #define CPU_VOLTAGE VREG_VOLTAGE_1_25
#endif

#define PRAV8D_MAP_TRIG_LED 25
#define PRAV8D_EPROM_TRIG_LED 29

#define EPROM_PAGE_SELECT_0 23
#define EPROM_PAGE_SELECT_1 24

//#define WDT_ENABLE 1
#define WD_TIME 100 // in milliseconds

#define PRAV8D_A0 0
#define PRAV8D_A1 1
#define PRAV8D_A2 2
#define PRAV8D_A3 3
#define PRAV8D_A4 4
#define PRAV8D_A5 5
#define PRAV8D_A6 6
#define PRAV8D_A7 7

#define PRAV8D_IO 8
#define PRAV8D_RW 9
#define PRAV8D_A14 10
#define PRAV8D_A15 11
#define PRAV8D_F2 12

#define PRAV8D_D0 13
#define PRAV8D_D1 14
#define PRAV8D_D2 15
#define PRAV8D_D3 16
#define PRAV8D_D4 17
#define PRAV8D_D5 18
#define PRAV8D_D6 19
#define PRAV8D_D7 20

#define PRAV8D_RESET 21
#define PRAV8D_MAP 22

#define D0_D7_OE 26
#define PRAV8D_IO_Contr 27
#define APPLE_S_DEV_SEL 28



void SetupHardware() {
#if CPU_SPEED > 0    
    // set cpu frequency and voltage
    vreg_set_voltage(CPU_VOLTAGE);
#endif
    stdio_init_all();
#if CPU_SPEED > 0    
    set_sys_clock_khz(CPU_CLOCK_FREQ,true);
#endif
    gpio_init(PRAV8D_MAP);
    gpio_set_dir(PRAV8D_MAP, GPIO_OUT);
    gpio_put(PRAV8D_MAP,1);

    gpio_init(PRAV8D_MAP_TRIG_LED);
    gpio_set_dir(PRAV8D_MAP_TRIG_LED, GPIO_OUT);
    gpio_put(PRAV8D_MAP_TRIG_LED,0);

    gpio_init(PRAV8D_EPROM_TRIG_LED);
    gpio_set_dir(PRAV8D_EPROM_TRIG_LED, GPIO_OUT);
    gpio_put(PRAV8D_EPROM_TRIG_LED,0);


    gpio_init(EPROM_PAGE_SELECT_0);
    gpio_set_dir(EPROM_PAGE_SELECT_0, GPIO_OUT);
    gpio_pull_up(EPROM_PAGE_SELECT_0);
    gpio_put(EPROM_PAGE_SELECT_0,0);

    gpio_init(EPROM_PAGE_SELECT_1);
    gpio_set_dir(EPROM_PAGE_SELECT_1, GPIO_OUT);
    gpio_pull_up(EPROM_PAGE_SELECT_1);
    gpio_put(EPROM_PAGE_SELECT_1,0);

    gpio_init(PRAV8D_IO_Contr);
    gpio_set_dir(PRAV8D_IO_Contr, GPIO_OUT);
    gpio_pull_up(PRAV8D_IO_Contr);

    gpio_init(PRAV8D_RESET);
    gpio_set_dir(PRAV8D_RESET, GPIO_OUT);
    gpio_put(PRAV8D_RESET,0);

    gpio_init(PRAV8D_F2);
    gpio_set_dir(PRAV8D_F2, GPIO_IN);
    //gpio_pull_up(PRAV8D_F2);
    gpio_init(PRAV8D_RW);
    gpio_set_dir(PRAV8D_RW, GPIO_IN);
    //gpio_pull_up(PRAV8D_RW);
    gpio_init(PRAV8D_IO);
    gpio_set_dir(PRAV8D_IO, GPIO_IN);
    //gpio_pull_up(PRAV8D_IO);
    gpio_init(PRAV8D_A14);
    gpio_set_dir(PRAV8D_A14, GPIO_IN);
    //gpio_pull_up(PRAV8D_A14);
    gpio_init(PRAV8D_A15);
    gpio_set_dir(PRAV8D_A15, GPIO_IN);
    //gpio_pull_up(PRAV8D_A15);

    gpio_init(PRAV8D_A0);
    gpio_set_dir(PRAV8D_A0, GPIO_IN);
    //gpio_pull_up(PRAV8D_A0);
    gpio_init(PRAV8D_A1);
    gpio_set_dir(PRAV8D_A1, GPIO_IN);
    //gpio_pull_up(PRAV8D_A1);
    gpio_init(PRAV8D_A2);
    gpio_set_dir(PRAV8D_A2, GPIO_IN);
    //gpio_pull_up(PRAV8D_A2);
    gpio_init(PRAV8D_A3);
    gpio_set_dir(PRAV8D_A3, GPIO_IN);
    //gpio_pull_up(PRAV8D_A3);
    gpio_init(PRAV8D_A4);
    gpio_set_dir(PRAV8D_A4, GPIO_IN);
    //gpio_pull_up(PRAV8D_A4);
    gpio_init(PRAV8D_A5);
    gpio_set_dir(PRAV8D_A5, GPIO_IN);
    //gpio_pull_up(PRAV8D_A5);
    gpio_init(PRAV8D_A6);
    gpio_set_dir(PRAV8D_A6, GPIO_IN);
    //gpio_pull_up(PRAV8D_A6);
    gpio_init(PRAV8D_A7);
    gpio_set_dir(PRAV8D_A7, GPIO_IN);
    //gpio_pull_up(PRAV8D_A7);


    gpio_init(PRAV8D_D0);
    gpio_set_dir(PRAV8D_D0, GPIO_OUT);
    gpio_pull_up(PRAV8D_D0);

    gpio_init(PRAV8D_D1);
    gpio_set_dir(PRAV8D_D1, GPIO_OUT);
    gpio_pull_up(PRAV8D_D1);

    gpio_init(PRAV8D_D2);
    gpio_set_dir(PRAV8D_D2, GPIO_OUT);
    gpio_pull_up(PRAV8D_D2);

    gpio_init(PRAV8D_D3);
    gpio_set_dir(PRAV8D_D3, GPIO_OUT);
    gpio_pull_up(PRAV8D_D3);

    gpio_init(PRAV8D_D4);
    gpio_set_dir(PRAV8D_D4, GPIO_OUT);
    gpio_pull_up(PRAV8D_D4);

    gpio_init(PRAV8D_D5);
    gpio_set_dir(PRAV8D_D5, GPIO_OUT);
    gpio_pull_up(PRAV8D_D5);

    gpio_init(PRAV8D_D6);
    gpio_set_dir(PRAV8D_D6, GPIO_OUT);
    gpio_pull_up(PRAV8D_D6);

    gpio_init(PRAV8D_D7);
    gpio_set_dir(PRAV8D_D7, GPIO_OUT);
    gpio_pull_up(PRAV8D_D7);

}

void P8D_Reset() {
    gpio_put(PRAV8D_RESET,0);
    sleep_ms(10);
    gpio_put(PRAV8D_RESET,1);

}

#endif