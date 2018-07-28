
#include <common.h>
#include <linux/io.h>
#if defined(CONFIG_RESET_PHY_R) && defined(CONFIG_DRIVER_DM9000)
#include <net.h>
#include <netdev.h>
#endif

DECLARE_GLOBAL_DATA_PTR;

/* initialize the DDR Controller and PHY */
int dram_init(void)
{
    /* MIG IP block is smart and doesn't need SW
     * to do any init */
    gd->ram_size = CONFIG_SYS_SDRAM_SIZE;   /* in bytes */

    return 0;
}

#ifdef CONFIG_DRIVER_DM9000
int board_eth_init(bd_t *bis)
{
    return dm9000_initialize(bis);
}
#endif

#ifdef CONFIG_RESET_PHY_R
void reset_phy(void)
{
#ifdef CONFIG_DRIVER_DM9000
    /*
     * Initialize ethernet HW addr prior to starting Linux,
     * needed for nfsroot
     */
    eth_init();
#endif
}
#endif


uint64_t notrace get_ticks(void)
{
	return readl((volatile uint32_t*)THINPAD_TIMER_TICK_ADDR);
}

ulong get_timer(ulong base)
{
        return timer_get_us() / 1000 - base;
}

unsigned long notrace timer_get_us(void)
{
        return readl((volatile uint32_t*)THINPAD_TIMER_USEC_ADDR);
}

void __udelay(unsigned long usec)
{
        uint64_t tmp;

        tmp = timer_get_us() + usec; /* get current timestamp */

        while (timer_get_us() < tmp+1)     /* loop till event */
                 /*NOP*/;
}
