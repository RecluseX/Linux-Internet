#ifndef _RTC_RX8010_H
#define	_RTC_RX8010_H

/* Includes */
#include "i2c_master.h"
#include "global.h"


/* RX8010 SLAVE ADDRESS */
#define RX8010_SLAVE_ADDR	0x32
/* RX8010 REG DEFINITION */
#define RX8010_SEC     0x10
#define RX8010_MIN     0x11
#define RX8010_HOUR    0x12
#define RX8010_WDAY    0x13
#define RX8010_MDAY    0x14
#define RX8010_MONTH   0x15
#define RX8010_YEAR    0x16
#define RX8010_RESV17  0x17
#define RX8010_ALMIN   0x18
#define RX8010_ALHOUR  0x19
#define RX8010_ALWDAY  0x1A
#define RX8010_TCOUNT0 0x1B
#define RX8010_TCOUNT1 0x1C
#define RX8010_EXT     0x1D
#define RX8010_FLAG    0x1E
#define RX8010_CTRL    0x1F
/* 0x20 to 0x2F are user registers */
#define RX8010_RESV30  0x30
#define RX8010_RESV31  0x31
#define RX8010_IRQ     0x32

`
/* BIT DEFINITION*/
#define RX8010_EXT_WADA  BIT(3)

#define RX8010_FLAG_VLF  BIT(1)
#define RX8010_FLAG_AF   BIT(3)
#define RX8010_FLAG_TF   BIT(4)
#define RX8010_FLAG_UF   BIT(5)

#define RX8010_CTRL_AIE  BIT(3)
#define RX8010_CTRL_UIE  BIT(5)
#define RX8010_CTRL_STOP BIT(6)
#define RX8010_CTRL_TEST BIT(7)

#define RX8010_ALARM_AE  BIT(7)

/* Struct */

typedef struct _rx8010_module {
	I2C_MASTER_CONFIG *i2c_client;
	int8_t (*i2c_write_byte)(uint8_t slave_address, uint8_t reg, uint8_t data);
	int8_t (*i2c_read_byte)(uint8_t slave_address, uint8_t reg);
} rx8010_module_t;

typedef struct _rtc_time {
	uint8_t sec;
	uint8_t min;
	uint8_t hour;
	uint8_t week;
	uint8_t day;
	uint8_t month;
	uint8_t year;
} rtc_time_t;


extern rx8010_module_t rx8010_dev;

int8_t rx8010_module_init(rx8010_module_t *p_module);
int8_t rx8010_get_time(rx8010_module_t *p_module, rtc_time_t *dt);
int8_t rx8010_set_time(rx8010_module_t *p_module, rtc_time_t *dt);


/* Functions */

#endif
