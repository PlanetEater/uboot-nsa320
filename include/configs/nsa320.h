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
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef _CONFIG_NSA320_H
#define _CONFIG_NSA320_H

/* version number information */
#define CONFIG_IDENT_STRING	"\nZyXEL NSA320 2-Bay Power Media Server"

/* high level configuration options */
#define CONFIG_FEROCEON_88FR131	1	/* CPU Core subversion */
#define CONFIG_KW88F6281		1	/* SOC Name */
#define CONFIG_MACH_NSA320			/* Machine type */
#define CONFIG_MACH_TYPE		MACH_TYPE_NSA320
#define CONFIG_SKIP_LOWLEVEL_INIT	/* disable board lowlevel_init */

/* add target to build it automatically upon "make" */
#define CONFIG_BUILD_TARGET		"u-boot.kwb"

/* misc configuration options */
#define CONFIG_SHOW_BOOT_PROGRESS 1	/* boot progess display (LED's) */

/* compression configuration */
#define CONFIG_BZIP2
#define CONFIG_LZMA

/* commands configuration */
#include <config_distro_defaults.h>
#define CONFIG_SYS_NO_FLASH		/* declare no flash (NOR/SPI) */
#define CONFIG_CMD_ENV
#define CONFIG_SYS_MVFS
#define CONFIG_CMD_IDE

/*
 * mv-common.h should be defined after CMD configs since it used them
 * to enable certain macros
 */
#include "mv-common.h"

/* environment variables configuration */
#ifdef CONFIG_CMD_NAND
#define CONFIG_ENV_IS_IN_NAND
#define CONFIG_ENV_SECT_SIZE	0x20000
#else
#define CONFIG_ENV_IS_NOWHERE
#endif
#define CONFIG_ENV_SIZE		0x20000
#define CONFIG_ENV_OFFSET	0x120000

/* default environment variables */
#define MTDIDS_DEFAULT			"nand0=kw_nand"
#define MTDPARTS_DEFAULT \
	"mtdparts=kw_nand:" \
	"1m(uboot)," \
	"512k(uboot_env)," \
	"512k(key_store)," \
	"512k(info)," \
	"10m(etc)," \
	"10m(kernel_1)," \
	"0x2fc0000(rootfs_1)," \
	"10m(kernel_2)," \
	"0x2fc0000(rootfs_2)"

/* Ethernet driver configuration */
#ifdef CONFIG_CMD_NET
#define CONFIG_NETCONSOLE
#define CONFIG_NET_MULTI
#define CONFIG_MVGBE_PORTS	{1, 0}	/* enable port 0 only */
#define CONFIG_PHY_BASE_ADR	1
#define CONFIG_PHY_GIGE
#define CONFIG_RESET_PHY_R
#endif /* CONFIG_CMD_NET */

/* SATA driver configuration */
#ifdef CONFIG_CMD_IDE
#define __io
#define CONFIG_IDE_PREINIT
#define CONFIG_DOS_PARTITION
#define CONFIG_MVSATA_IDE_USE_PORT0
#define CONFIG_MVSATA_IDE_USE_PORT1
#define CONFIG_SYS_ATA_IDE0_OFFSET	MV_SATA_PORT0_OFFSET
#define CONFIG_SYS_ATA_IDE1_OFFSET	MV_SATA_PORT1_OFFSET
#endif /* CONFIG_CMD_IDE */

#define CONFIG_LZO

/* RTC driver configuration */
#ifdef CONFIG_CMD_DATE
#define CONFIG_RTC_MV
#endif /* CONFIG_CMD_DATE */

#endif /* _CONFIG_NSA320_H */
