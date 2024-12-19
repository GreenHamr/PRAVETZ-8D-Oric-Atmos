#ifndef PIO_INIT_H_
#define PIO_INIT_H_

#include "hardware/pio.h"
#include "HardwareDefines.hpp"



/*
 adress 0xC2BD - 0x59 => 0x41

10 FOR I=#320 TO #3FF
20 PRINT PEEK(I)
30 NEXT

10 FOR I=#320 TO #3FF
20 A=PEEK(I)
30 POKE #382,0
40 B=PEEK(I)
50 POKE #380,0
60 IF A<>B THEN 
70 PRINT "ADRESS:"+I+",A="+A+",B="+B+" -- OK"
80 ELSE
70 PRINT "ADRESS:"+I+",A="+A+",B="+B+" -- DIFFERENT"
100 END
110 NEXT





*/


void set_PIO_pins(PIO pio) {
    pio_gpio_init(pio, PRAV8D_A0);
    pio_gpio_init(pio, PRAV8D_A1);
    pio_gpio_init(pio, PRAV8D_A2);
    pio_gpio_init(pio, PRAV8D_A3);
    pio_gpio_init(pio, PRAV8D_A4);
    pio_gpio_init(pio, PRAV8D_A5);
    pio_gpio_init(pio, PRAV8D_A6);
    pio_gpio_init(pio, PRAV8D_A7);
    pio_gpio_init(pio, PRAV8D_IO);
    pio_gpio_init(pio, PRAV8D_RW);
    pio_gpio_init(pio, PRAV8D_A14);
    pio_gpio_init(pio, PRAV8D_A15);
    pio_gpio_init(pio, PRAV8D_F2);


    pio_gpio_init(pio, D0_D7_OE);
    pio_gpio_init(pio, PRAV8D_IO_Contr);
    pio_gpio_init(pio, APPLE_S_DEV_SEL);

    pio_gpio_init(pio, PRAV8D_D0);
    pio_gpio_init(pio, PRAV8D_D1);
    pio_gpio_init(pio, PRAV8D_D2);
    pio_gpio_init(pio, PRAV8D_D3);
    pio_gpio_init(pio, PRAV8D_D4);
    pio_gpio_init(pio, PRAV8D_D5);
    pio_gpio_init(pio, PRAV8D_D6);
    pio_gpio_init(pio, PRAV8D_D7);


}

void set_PIO_pins2(PIO pio) {
    pio_gpio_init(pio, PRAV8D_MAP);
    pio_gpio_init(pio, PRAV8D_RW);
    pio_gpio_init(pio, PRAV8D_A14);
    pio_gpio_init(pio, PRAV8D_A15);
    pio_gpio_init(pio, PRAV8D_F2);
    
    pio_gpio_init(pio, PRAV8D_A0);
    pio_gpio_init(pio, PRAV8D_A1);
    pio_gpio_init(pio, PRAV8D_A2);
    pio_gpio_init(pio, PRAV8D_A3);
    pio_gpio_init(pio, PRAV8D_A4);
    pio_gpio_init(pio, PRAV8D_A5);
    pio_gpio_init(pio, PRAV8D_A6);
    pio_gpio_init(pio, PRAV8D_A7);

    pio_gpio_init(pio, PRAV8D_D0);
    pio_gpio_init(pio, PRAV8D_D1);
    pio_gpio_init(pio, PRAV8D_D2);
    pio_gpio_init(pio, PRAV8D_D3);
    pio_gpio_init(pio, PRAV8D_D4);
    pio_gpio_init(pio, PRAV8D_D5);
    pio_gpio_init(pio, PRAV8D_D6);
    pio_gpio_init(pio, PRAV8D_D7);

}


void set_trigger_program_init(PIO pio, uint sm, uint offset) {
    pio_sm_set_consecutive_pindirs(pio, sm, PRAV8D_A0, 12, false);
    pio_sm_config c = set_trigger_program_get_default_config(offset);
    sm_config_set_in_pins(&c, PRAV8D_A0);
    sm_config_set_in_shift(&c, false, true, 12);
    sm_config_set_out_shift(&c, false, false, 12);
    pio_sm_init(pio, sm, offset, &c);
}



void IO_Programable_logic_program_init(PIO pio, uint sm, uint offset) {
    pio_sm_set_consecutive_pindirs(pio, sm, PRAV8D_A0, 13, false);
    pio_sm_set_consecutive_pindirs(pio, sm, D0_D7_OE, 3, true);
    pio_sm_config c = IO_Programable_logic_program_get_default_config(offset);
    sm_config_set_in_pins(&c, PRAV8D_A0);
    sm_config_set_sideset_pins(&c, D0_D7_OE);
    sm_config_set_in_shift(&c, false, true, 13);
    sm_config_set_out_shift(&c, false, false, 13);
    pio_sm_init(pio, sm, offset, &c);
}


//=============================================================
void IO_Control_logic_init(PIO pio, uint sm, uint offset) {
    pio_sm_set_consecutive_pindirs(pio, sm, PRAV8D_A0, 13, false);
    pio_sm_set_consecutive_pindirs(pio, sm, PRAV8D_IO_Contr, 1, true);
    pio_sm_config c = IO_Control_logic_program_get_default_config(offset);
    sm_config_set_in_pins(&c, PRAV8D_A0);
    sm_config_set_set_pins(&c, PRAV8D_IO_Contr, 1);
    sm_config_set_in_shift(&c, false, true, 13);
    sm_config_set_out_shift(&c, false, false, 13);
    pio_sm_init(pio, sm, offset, &c);
}
//===============================================================


void EPROM_data_program_init(PIO pio, uint sm, uint offset) {
    pio_sm_set_consecutive_pindirs(pio, sm, PRAV8D_A0, 8, false);
    pio_sm_set_consecutive_pindirs(pio, sm, PRAV8D_D0, 8, true);
    pio_sm_config c = EPROM_data_program_get_default_config(offset);
    sm_config_set_in_pins(&c, PRAV8D_A0);
    sm_config_set_out_pins(&c, PRAV8D_D0, 8);
    sm_config_set_in_shift(&c, false, true, 8);
    sm_config_set_out_shift(&c, true, true, 8);
    pio_sm_init(pio, sm, offset, &c);
}


void extra16kRAM_MAP_signal_program_init(PIO pio, uint sm, uint offset) {
    pio_sm_config c = extra16kRAM_MAP_signal_program_get_default_config(offset);
    pio_sm_set_consecutive_pindirs(pio, sm, PRAV8D_MAP, 1, true);
    pio_sm_set_consecutive_pindirs(pio, sm, PRAV8D_RW, 3, false);
    sm_config_set_set_pins(&c, PRAV8D_MAP, 1);
    sm_config_set_in_pins(&c, PRAV8D_RW);
    sm_config_set_in_shift(&c, false, true, 3);
    pio_sm_init(pio, sm, offset, &c);
}


void initPio() {
    uint offset = 0;
    set_PIO_pins(pio0);
    set_PIO_pins2(pio1);

    offset = pio_add_program(pio0, &set_trigger_program);
    set_trigger_program_init(pio0, 0, offset);
    pio_sm_set_enabled(pio0, 0, true);

    offset = pio_add_program(pio0, &IO_Programable_logic_program);
    IO_Programable_logic_program_init(pio0, 1, offset);
    pio_sm_set_enabled(pio0, 1, true);

//-----------------------    
    offset = pio_add_program(pio0, &IO_Control_logic_program);
    IO_Control_logic_init(pio0, 2, offset);
    pio_sm_set_enabled(pio0, 2, true);


//-----------------------    

    offset = pio_add_program(pio1, &EPROM_data_program);
    EPROM_data_program_init(pio1, 1, offset);
    pio_sm_set_enabled(pio1, 1, true);

    offset = pio_add_program(pio1, &extra16kRAM_MAP_signal_program);
    extra16kRAM_MAP_signal_program_init(pio1, 0, offset);
    pio_sm_set_enabled(pio1, 0, true);
}




#endif