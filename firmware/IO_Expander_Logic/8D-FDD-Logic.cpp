#define VERSION_BASE 0
#define VERSION_MINOR 0
#define VERSION_BUILD 1


#include <stdio.h>
#include "pico/stdlib.h"
#include <stdlib.h>
#include <pico/time.h>
#include <math.h>
#include "pico.h"
#include <time.h>
#include "hardware/watchdog.h"
#include "pico/multicore.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "extra16kRAM.pio.h"
#include "HardwareDefines.hpp"
#include "pio_init.hpp"
#include "eprom_floppy_content.hpp"


bool Trig_MAP;
bool Trig_EPROM;

bool PORT_io = false;
bool PORT_rw = false;
bool PORT_a4 = false;
bool PORT_a7 = false;
bool PORT_a0 = false;
bool PORT_a1 = false;
bool PORT_a14 = false;
bool PORT_a15 = false;


void core1_procedure() {
    uint p = 1;
    while (1) {
#ifdef WDT_ENABLE             
        watchdog_update();
#endif
        uint16_t dd = pio_sm_get_blocking(pio0, 0);
        PORT_io = dd & 0b000100000000;
        PORT_rw = dd & 0b001000000000;
        PORT_a4 = dd & 0b000000010000;
        PORT_a7 = dd & 0b000010000000;
        PORT_a0 = dd & 0b000000000001;
        PORT_a1 = dd & 0b000000000010;
        if (!PORT_io && !PORT_rw && !PORT_a4 && PORT_a7) {
            Trig_MAP = PORT_a0;
            Trig_EPROM = PORT_a1;
            pio_sm_exec(pio1, 0, pio_encode_set(pio_x, Trig_MAP));
        }
        if (!PORT_io && !PORT_rw && PORT_a4 && PORT_a7) {
            gpio_put(EPROM_PAGE_SELECT_0,PORT_a0);    
            gpio_put(EPROM_PAGE_SELECT_1,PORT_a1);    
        }
        gpio_put(PRAV8D_MAP_TRIG_LED,Trig_MAP);
        gpio_put(PRAV8D_EPROM_TRIG_LED,Trig_EPROM);



        uint8_t floppy_eprom_address = pio_sm_get_blocking(pio1, 1);
        pio_sm_put(pio1,1,FLOPPY_ROM_MEMORY[floppy_eprom_address | (Trig_EPROM << 9)]);

    }
}



//======================================================================================
//===    main program
//======================================================================================
int main() {
    Trig_MAP = false;
    Trig_EPROM = false;

    SetupHardware();
    initPio();
    multicore_launch_core1(core1_procedure);
    P8D_Reset();

#ifdef WDT_ENABLE     
    if (watchdog_caused_reboot()) {
    }
    watchdog_enable(WD_TIME, 1);
#endif    

    while (1) {
        // do something else

    }


}
