#include <avr/io.h>

#include "spi/spi.h"

#define SPI_SPCR_MODE_MASK    0x0C  // CPOL = bit 3, CPHA = bit 2
#define SPI_SPCR_CLOCK_MASK   0x03  // SPR1 = bit 1, SPR0 = bit 0
#define SPI_SPCR_ORDER_MASK   0x20  // DORD = bit 5

#define SPI_SPSR_2XCLOCK_MASK 0x01  // SPI2X = bit 0

#define SPI_CLK_DDR     DDRB
#define SPI_CLK_PORT    PORTB
#define SPI_CLK_BIT     7

#define SPI_MISO_DDR    DDRB
#define SPI_MISO_PU     PORTB
#define SPI_MISO_BIT    6

#define SPI_MOSI_DDR    DDRB
#define SPI_MOSI_PORT   PORTB
#define SPI_MOSI_BIT    5

#define SPI_SS_DDR      DDRB
#define SPI_SS_PORT     PORTB
#define SPI_SS_BIT      4

void spi_enable(void)
{
    /* MOSI, SCK and SS must be output, all others input */
    SPI_CLK_DDR  |= 1 << SPI_CLK_BIT;
    SPI_CLK_PORT &= ~(1 << SPI_CLK_BIT);

    SPI_MOSI_DDR  |= 1 << SPI_MOSI_BIT;
    SPI_MOSI_PORT &= ~(1 << SPI_MOSI_BIT);

    SPI_MISO_DDR &= ~(1 << SPI_MISO_BIT);
    /* SPI_MISO_PU  |= 1 << SPI_MISO_BIT; */

    SPI_SS_DDR  |= 1 << SPI_SS_BIT;
    SPI_SS_PORT |= 1 << SPI_SS_BIT;

    SPCR |= _BV(MSTR);
    SPCR |= _BV(SPE);
}

void spi_disable(void)
{
    SPCR &= ~_BV(SPE);
}

void spi_setup(spi_mode_t mode, spi_clk_div_t clk_div, spi_bit_order_t bit_order)
{
    unsigned char spcr = SPCR & ~(SPI_SPCR_MODE_MASK | SPI_SPCR_CLOCK_MASK | SPI_SPCR_ORDER_MASK);
    unsigned char spsr = SPSR & ~SPI_SPSR_2XCLOCK_MASK;

    if (bit_order == SPI_BIT_ORDER_LSB_FIRST)
        spcr |= _BV(DORD);
    spcr |= mode;

    spcr |= clk_div&0x3;
    spsr |= clk_div>>2;

    SPCR = spcr;
    SPSR = spsr;
}

void spi_interrupt_enable(void)
{
    SPCR |= _BV(SPIE);
}

void spi_interrupt_disable(void)
{
    SPCR &= ~_BV(SPIE);
}

void spi_transfer(spi_transfer_t *xfer)
{
    unsigned char c;
    unsigned int i;

    for (i=0;i<xfer->len;++i) {
        if (xfer->out)
            SPDR = xfer->out[i];
        else
            SPDR = 0xFF;

        while (!(SPSR & _BV(SPIF)));

        if (xfer->in)
            xfer->in[i] = SPDR;
        else
            c = SPDR; // clean SPIF
        c;
    }
}

void spi_write(unsigned char out)
{
    unsigned char c;

    SPDR = out;

    while (!(SPSR & _BV(SPIF)));

    c = SPDR; // clean SPIF
    c;
}

void spi_read(unsigned char *in)
{
    SPDR = 0xFF;

    while (!(SPSR & _BV(SPIF)));

    *in = SPDR;
}