// -------------------------------------------------- //
// This file is autogenerated by pioasm; do not edit! //
// -------------------------------------------------- //

#pragma once

#if !PICO_NO_HARDWARE
#include "hardware/pio.h"
#endif

// ----- //
// tone2 //
// ----- //

#define tone2_wrap_target 0
#define tone2_wrap 6
#define tone2_pio_version 0

static const uint16_t tone2_program_instructions[] = {
    //     .wrap_target
    0x8080, //  0: pull   noblock
    0xa027, //  1: mov    x, osr
    0xb847, //  2: mov    y, osr          side 1
    0x0083, //  3: jmp    y--, 3
    0xb047, //  4: mov    y, osr          side 0
    0x0085, //  5: jmp    y--, 5
    0x0000, //  6: jmp    0
    //     .wrap
};

#if !PICO_NO_HARDWARE
static const struct pio_program tone2_program = {
    .instructions = tone2_program_instructions,
    .length = 7,
    .origin = -1,
    .pio_version = 0,
#if PICO_PIO_VERSION > 0
    .used_gpio_ranges = 0x0
#endif
};

static inline pio_sm_config tone2_program_get_default_config(uint offset) {
    pio_sm_config c = pio_get_default_sm_config();
    sm_config_set_wrap(&c, offset + tone2_wrap_target, offset + tone2_wrap);
    sm_config_set_sideset(&c, 2, true, false);
    return c;
}

static inline void tone2_program_init(PIO pio, uint sm, uint offset, uint pin) {
    pio_gpio_init(pio, pin);
    pio_sm_set_consecutive_pindirs(pio, sm, pin, 1, true);
    pio_sm_config c = tone2_program_get_default_config(offset);
    sm_config_set_sideset_pins(&c, pin);
    pio_sm_init(pio, sm, offset, &c);
}

#endif
