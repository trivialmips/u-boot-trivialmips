#ifndef __TRIVIALMIPS_THINPAD_CONFIG_H
#define __TRIVIALMIPS_THINPAD_CONFIG_H

/* BootROM + MIG is pretty smart. DDR and Cache initialized */
#define CONFIG_SKIP_LOWLEVEL_INIT

#define DEBUG

/*--------------------------------------------
 * CPU configuration
 */
/* CPU Timer rate */
#define CONFIG_SYS_MIPS_TIMER_FREQ	8000000

/* Cache Configuration */
#define CONFIG_SYS_MIPS_CACHE_MODE	CONF_CM_CACHABLE_NONCOHERENT

/* Time Measuring */
#define THINPAD_TIMER_USEC_ADDR		0xA4000000
#define THINPAD_TIMER_TICK_ADDR		0xA4000004

/*----------------------------------------------------------------------
 * Memory Layout
 */

/* SDRAM Configuration (for final code, data, stack, heap) */
#define CONFIG_SYS_SDRAM_BASE		0x80000000
#define CONFIG_SYS_SDRAM_SIZE		0x00800000	/* 8 Mbytes */
#define CONFIG_SYS_INIT_SP_ADDR		\
	(CONFIG_SYS_SDRAM_BASE + CONFIG_SYS_SDRAM_SIZE - 0x1000)

#define CONFIG_SYS_MEMTEST_START    0xA2000000
#define CONFIG_SYS_MEMTEST_END      0xA203A980

#define CONFIG_SYS_MALLOC_LEN		(256 << 10)
#define CONFIG_SYS_MONITOR_BASE		CONFIG_SYS_TEXT_BASE
#define CONFIG_SYS_LOAD_ADDR		0x80000000 /* default load address */

/*----------------------------------------------------------------------
 * Commands
 */
//#define CONFIG_SYS_LONGHELP		/* undef to save memory */
//#define CONFIG_CMDLINE_EDITING

/*------------------------------------------------------------
 * Console Configuration
 */
#define CONFIG_SYS_CBSIZE		1024 /* Console I/O Buffer Size   */
#define CONFIG_SYS_MAXARGS		16   /* max number of command args*/

/* -------------------------------------------------
 * Environment
 */
//Disable persistent environment variable storage
#define CONFIG_ENV_IS_NOWHERE   1 
/*
//Environment variables in Flash
#define CONFIG_ENV_IS_IN_FLASH  1
#define CONFIG_FLASH_BASE	0xA1000000
#define CONFIG_ENV_ADDR         (CONFIG_ENV_ADDR + 0x007E0000)  // last sector of 8M flash
#define CONFIG_ENV_SECT_SIZE    0x20000
*/
#define CONFIG_ENV_SIZE		0x4000
#define CONFIG_EXTRA_ENV_SETTINGS \
    "autoload=no\0" \
    "s_linux=setenv bootfile mips-linux.ub;setenv loadaddr 0x800FFFC0\0" \
    "s_ucore=setenv bootfile ucore.ub;setenv loadaddr 0x80000000\0" \
    "serverip=192.168.1.30\0" \
    "ipaddr=192.168.1.60\0" \
    "netmask=255.255.255.0\0"

/* ---------------------------------------------------------------------
 * Board boot configuration
 */
#define CONFIG_TIMESTAMP	/* Print image info with timestamp */

/* Ethernet */
#define CONFIG_DRIVER_DM9000
#define CONFIG_DM9000_BASE      0xA5000000
#define DM9000_IO           CONFIG_DM9000_BASE
#define DM9000_DATA         (CONFIG_DM9000_BASE + 4)
#define CONFIG_DM9000_USE_16BIT
#define CONFIG_DM9000_NO_SROM
#define CONFIG_NET_RETRY_COUNT      20
#define CONFIG_RESET_PHY_R

// #define CONFIG_DM9000_DEBUG

/* USB */
#define CONFIG_USB_SL811HS
#define SL811_BASE		0xA7000000
#define SL811_ADR		SL811_BASE
#define SL811_DAT		(SL811_BASE + 4)

// #define SL811_DEBUG

/* Flash */
#define CONFIG_FLASH_CFI_DRIVER
#define CONFIG_SYS_FLASH_CFI
#define CONFIG_SYS_FLASH_USE_BUFFER_WRITE
#define CONFIG_SYS_MAX_FLASH_BANKS_DETECT   1
#define CONFIG_SYS_MAX_FLASH_SECT           64

// #define DEBUG

#endif /* __TRIVIALMIPS_THINPAD_CONFIG_H */

