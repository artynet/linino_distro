/*
 * Copyright (c) dog hunter AG - Zug - CH
 * General Public License version 2 (GPLv2)
 * Author Federico Vaga <federicov@linino.org>
 */

#ifndef MACH_LININO_H_
#define MACH_LININO_H_

#if defined(LININO_FREEDOG)
	#define GPIO_FUNC_SET (AR933X_GPIO_FUNC_JTAG_DISABLE | \
				AR933X_GPIO_FUNC_I2S_MCK_EN)
	#define GPIO_FUNC_CLEAR (AR933X_GPIO_FUNC_SPDIF_EN | \
				AR933X_GPIO_FUNC_I2SO_EN | \
				AR933X_GPIO_FUNC_UART_RTS_CTS_EN)
	#define GPIO_FUNC2_SET (AR933X_GPIO_FUNC2_JUMPSTART_DISABLE | \
				AR933X_GPIO_FUNC2_WPS_DISABLE | \
				AR933X_GPIO_FUNC2_DIS_MIC)
	#define GPIO_FUNC2_CLEAR (AR933X_GPIO_FUNC2_I2SD_ON_12)
#else
	#define GPIO_FUNC_SET (AR933X_GPIO_FUNC_JTAG_DISABLE | \
				AR933X_GPIO_FUNC_I2S_MCK_EN)
	#define GPIO_FUNC_CLEAR (0)
	#define GPIO_FUNC2_SET (AR933X_GPIO_FUNC2_JUMPSTART_DISABLE)
	#define GPIO_FUNC2_CLEAR (0)
#endif

#define DS_GPIO_LED_WLAN		0
#define DS_GPIO_LED_USB			1

#if defined(LININO_CHOWCHOW)
	#define DS_GPIO_OE			13
	#define DS_GPIO_MCU_RESET	0
#else
	#define DS_GPIO_OE			21
	#define DS_GPIO_MCU_RESET		18
#endif


#define DS_GPIO_UART_ENA	23
#define DS_GPIO_CONF_BTN	20

/* Configure level shifter enable GPIO */
#if defined(LININO_FREEDOG)
	#define DS_GPIO_OE2		11
#elif defined(LININO_CHOWCHOW)
	#define DS_GPIO_OE2		15
#else	/* YUN */
	#define DS_GPIO_OE2		22
#endif

#define DS_KEYS_POLL_INTERVAL		20	/* msecs */
#define DS_KEYS_DEBOUNCE_INTERVAL	(3 * DS_KEYS_POLL_INTERVAL)

#define DS_MAC0_OFFSET			0x0000
#define DS_MAC1_OFFSET			0x0006
#define DS_CALDATA_OFFSET		0x1000
#define DS_WMAC_MAC_OFFSET		0x1002


/* SPI GPIOs */

#if defined(LININO_FREEDOG)
	#define	LININO_GPIO_SPI_SCK	7
	#define	LININO_GPIO_SPI_MISO	6
#else	/* YUN */
	#define	LININO_GPIO_SPI_SCK	11
	#define	LININO_GPIO_SPI_MISO	8
#endif

#define	LININO_GPIO_SPI_MOSI		27
#define	LININO_N_SPI_CHIP_SELECT	1

#define LININO_GPIO_SPI_CS0	26

#if defined(LININO_FREEDOG)
	#define LININO_GPIO_SPI_INTERRUPT		23
#elif defined(CONFIG_ATH79_MACH_LININO_YUN)
	#define LININO_GPIO_SPI_INTERRUPT		19
#endif

#endif /* MACH_LININO_H_ */
