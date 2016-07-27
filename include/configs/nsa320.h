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

/* version number information */
#define CONFIG_IDENT_STRING	"\nZyXEL NSA320 2-Bay Power Media Server"

/* high level configuration options (easy to change) */
#define CONFIG_FEROCEON_88FR131	1	/* CPU Core subversion */
#define CONFIG_KW88F6281	1	/* SOC Name */
#define CONFIG_MACH_NSA320		/* Machine type */
#define CONFIG_MACH_TYPE	MACH_TYPE_NSA320
#define CONFIG_SKIP_LOWLEVEL_INIT	/* disable board lowlevel_init */

/* add target to build it automatically upon "make" */
#define CONFIG_BUILD_TARGET             "u-boot.kwb"

/* misc configuration options */
#define CONFIG_SHOW_BOOT_PROGRESS 1	/* boot progess display (LED's) */

/* commands configuration */
#include <config_distro_defaults.h>
#define CONFIG_SYS_NO_FLASH		/* Declare no flash (NOR/SPI) */
#define CONFIG_CMD_ENV
#define CONFIG_CMD_IDE

/*
 * mv-common.h should be defined after CMD configs since it used them
 * to enable certain macros
 */
#include "mv-common.h"

/* environment variables configurations */
#ifdef CONFIG_CMD_NAND
#define CONFIG_ENV_IS_IN_NAND		1
#define CONFIG_ENV_SECT_SIZE		0x20000		/* 128K */
#else
#define CONFIG_ENV_IS_NOWHERE		1		/* if env in SDRAM */
#endif
/*
 * max 4k env size is enough, but in case of nand
 * it has to be rounded to sector size
 */
#define CONFIG_ENV_SIZE			0x20000		/* 128k */
#define CONFIG_ENV_ADDR			0x120000
#define CONFIG_ENV_OFFSET		0x120000	/* env starts here */

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

/* ethernet driver configuration */
#ifdef CONFIG_CMD_NET
#define CONFIG_MVGBE_PORTS		{1, 0}	/* enable port 0 only */
#define CONFIG_PHY_BASE_ADR		0x1
#define CONFIG_PHY_GIGE
#define CONFIG_NETCONSOLE
#endif /* CONFIG_CMD_NET */

/* SATA driver configuration */
#ifdef CONFIG_MVSATA_IDE
#define CONFIG_SYS_ATA_IDE0_OFFSET      MV_SATA_PORT0_OFFSET
#define CONFIG_SYS_ATA_IDE1_OFFSET      MV_SATA_PORT1_OFFSET
#endif /* CONFIG_MVSATA_IDE */

/* file system */

#define CONFIG_MTD_DEVICE               /* needed for mtdparts commands */
#define CONFIG_MTD_PARTITIONS
#define CONFIG_CMD_MTDPARTS
#define CONFIG_LZO

#endif /* _CONFIG_NSA320_H */
