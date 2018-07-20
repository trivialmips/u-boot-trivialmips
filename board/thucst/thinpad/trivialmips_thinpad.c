
#include <common.h>
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
