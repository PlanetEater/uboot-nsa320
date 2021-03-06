/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2012  Peter Schildmann <linux@schildmann.info>
 *
 * Based on guruplug.h originally written by
 * Siddarth Gore <gores@marvell.com>
 * (C) Copyright 2009
 * Marvell Semiconductor <www.marvell.com>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 */

#ifndef _CONFIG_NSA320_H
#define _CONFIG_NSA320_H

/* high level configuration options */
#define CONFIG_FEROCEON_88FR131	1	/* CPU Core subversion */
#define CONFIG_KW88F6281		1	/* SOC Name */
#define CONFIG_SKIP_LOWLEVEL_INIT	/* disable board lowlevel_init */

/* misc configuration options */
#define CONFIG_SHOW_BOOT_PROGRESS 1	/* boot progess display (LED's) */

/* compression configuration */
#define CONFIG_BZIP2

/* commands configuration */

/*
 * mv-common.h should be defined after CMD configs since it used them
 * to enable certain macros
 */
#include "mv-common.h"

/* environment variables configuration */

/* default environment variables */

/* Ethernet driver configuration */
#ifdef CONFIG_CMD_NET
#define CONFIG_NETCONSOLE
#define CONFIG_MVGBE_PORTS	{1, 0}	/* enable port 0 only */
#define CONFIG_PHY_BASE_ADR	1
#define CONFIG_RESET_PHY_R
#endif /* CONFIG_CMD_NET */

/* SATA driver configuration */
#ifdef CONFIG_IDE
#define __io
#define CONFIG_IDE_PREINIT
#define CONFIG_MVSATA_IDE_USE_PORT0
#define CONFIG_MVSATA_IDE_USE_PORT1
#define CONFIG_SYS_ATA_IDE0_OFFSET	MV_SATA_PORT0_OFFSET
#define CONFIG_SYS_ATA_IDE1_OFFSET	MV_SATA_PORT1_OFFSET
#endif /* CONFIG_IDE */

/* RTC driver configuration */
#ifdef CONFIG_CMD_DATE
#define CONFIG_RTC_MV
#endif /* CONFIG_CMD_DATE */

#endif /* _CONFIG_NSA320_H */
