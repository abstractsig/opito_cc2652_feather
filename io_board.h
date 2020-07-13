/*
 *
 * Opito cc2652 feather
 *
 *                        .--------------------.
 *                        |16 Reset            |
 *                        |15 3v3              |
 *                        |14                  |
 *                        |13 0v               |
 *                        |12 DIO23         12 |
 *                        |11 DIO24    EN   11 |
 *                        |10 DIO25    VIN  10 |
 *                        | 9 DIO26    DIO13 9 |  (Not available if SPI flash mounted)
 *                        | 8 PGA0     DIO12 8 |
 *                        | 7 PGA1     DIO9  7 |
 *                        | 6 DIO22    DIO8  6 |
 *                        | 5 DIO30    DIO7  5 |
 *                        | 4 DIO29    DIO6  4 |
 *                        | 3 DIO10    DIO4  3 |
 *                        | 2 DIO11    DIO1  2 |
 *                        | 1          DIO0  1 |
 *                        `--------------------'
 *
 */
#ifndef io_board_H_
#define io_board_H_
#include <io_cpu.h>

void io_board_panic (io_t*,int);

#define SPECIALISE_IO_BOARD_IMPLEMENTATION(S) \
    SPECIALISE_IO_CPU_IMPLEMENTATION(S) \
	 .panic = io_board_panic,\
    /**/

// red LED
#define LED_1_BOARD_PIN def_cc2652_io_output_pin (\
        IOID_16,\
        IO_PIN_ACTIVE_LEVEL_LOW,\
        IO_PIN_LEVEL_INACTIVE\
    )
#define LED_1   LED_1_BOARD_PIN.io

// green LED
#define LED_2_BOARD_PIN def_cc2652_io_output_pin (\
        IOID_17,\
		  IO_PIN_ACTIVE_LEVEL_LOW,\
        IO_PIN_LEVEL_INACTIVE\
    )
#define LED_2   LED_2_BOARD_PIN.io

// blue LED
#define LED_3_BOARD_PIN def_cc2652_io_output_pin (\
        IOID_18,\
		  IO_PIN_ACTIVE_LEVEL_LOW,\
        IO_PIN_LEVEL_INACTIVE\
    )
#define LED_3   LED_3_BOARD_PIN.io

// Button 1
#define BTN1_BOARD_PIN def_cc2652_io_input_pin (\
      IOID_15,\
		IO_PIN_ACTIVE_LEVEL_LOW,\
      IO_PIN_LEVEL_INACTIVE\
  )

// CH340 UART
#define USB_UART_TX_DIO      IOID_3
#define USB_UART_RX_DIO      IOID_2


#define MX25R3235_MISO def_cc2652_io_alternate_pin ( \
		IOID_9, \
		IO_PIN_DIRECTION_INPUT, \
		IO_PIN_MODE_NORMAL, \
		IO_PIN_PULL_UP, \
		IO_PIN_ACTIVE_LEVEL_LOW, \
		IOC_PORT_MCU_SSI0_RX \
	)

#define MX25R3235_MOSI def_cc2652_io_alternate_pin ( \
		IOID_8, \
		IO_PIN_DIRECTION_OUTPUT, \
		IO_PIN_MODE_NORMAL, \
		IO_PIN_NO_PULL, \
		IO_PIN_ACTIVE_LEVEL_HIGH, \
		IOC_PORT_MCU_SSI0_TX \
	)

#define MX25R3235_CLOCK def_cc2652_io_alternate_pin ( \
		IOID_12, \
		IO_PIN_DIRECTION_OUTPUT, \
		IO_PIN_MODE_NORMAL, \
		IO_PIN_NO_PULL, \
		IO_PIN_ACTIVE_LEVEL_HIGH, \
		IOC_PORT_MCU_SSI0_CLK \
	)

#define MX25R3235_SLAVE_SELECT def_cc2652_io_output_pin (\
        IOID_7,\
        IO_PIN_ACTIVE_LEVEL_LOW,\
        IO_PIN_LEVEL_INACTIVE\
    )

#define MX25R3235_MAXIMUM_SPEED	33000000

void    initialise_io_board (io_t*);

#ifdef IMPLEMENT_IO_BOARD
//-----------------------------------------------------------------------------
//
// Implementation
//
//-----------------------------------------------------------------------------

void
initialise_io_board (io_t *io) {
    initialise_io_cpu (io);
}

void
io_board_panic (io_t *io,int code) {

	// blink an LED

	DISABLE_INTERRUPTS;
	while (1);
}


#endif /* IMPLEMENT_IO_BOARD */
#endif
/*
Copyright 2020 Gregor Bruce

Permission to use, copy, modify, and/or distribute this software for any purpose
with or without fee is hereby granted, provided that the above copyright notice
and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND
FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT,
OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

