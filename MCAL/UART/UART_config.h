#ifndef UART_UART_CONFIG_H_
#define UART_UART_CONFIG_H_

extern uint8 UCSRC_reg_data;

#define UBRRH_MASK	0x0F//ANDING WITH THIS MASK
#define UCSRC_MASK	0x80//ORING WITH THIS MASK

/********************** FOR 16MHz ON NORMAL SPEED **********************/
#define USART_BAUD_RATE_2400		416	//UBR VALUE FOR USART
#define USART_BAUD_RATE_4800		207	//UBR VALUE FOR USART
#define USART_BAUD_RATE_9600		103	//UBR VALUE FOR USART
#define USART_BAUD_RATE_115_2k		8	//FOR FTDI  FOR USART

#define USRT_BAUD_RATE_9600			832	//UBR VALUE FOR USRT

#define BAUD_RATE		USART_BAUD_RATE_9600

#define BAUD_RATE_SEL(BAUD)					\
	UBRRH_R = ((BAUD >> 8) & UBRRH_MASK);	\
	UBRRL_R = (uint8)BAUD

/********************** TRANSMITION BITS NUMBER (CHARACTER SIZE) **********************/
#define CHAR_SIZE_5			0x00
#define CHAR_SIZE_6			0x01
#define CHAR_SIZE_7			0x02
#define CHAR_SIZE_8			0x03
#define CHAR_SIZE_9			0x07

#define CHAR_SIZE		CHAR_SIZE_8

#define CHAR_SIZE_SEL(SIZE)						  						\
	UCSRC_reg_data |= (UCSRC_MASK | ((SIZE & 0x03) << UCSRC_UCSZ0));  	\
	UCSRB_R |= (SIZE & 0x04) //FOR BIT UCSZ2 IN UCSRB_R

/********************** MODES **********************/
#define MODE_ASYNCH			0
#define MODE_SYNCH			1

#define USART_MODE		MODE_ASYNCH

#define USART_MODE_SEL(MODE)	\
	((MODE)? SET_BIT(UCSRC_reg_data, UCSRC_UMSEL) : CLEAR_BIT(UCSRC_reg_data, UCSRC_UMSEL))

/********************** PARITY BITS **********************/
#define PARITY_DISABLED		0x00
#define PARITY_EVEN			0x02
#define PARITY_ODD			0x03

#define PARITY_BIT		PARITY_DISABLED

#define PARITY_BIT_MASK		0xCF

#define PARITY_BIT_SEL(PARITY)	\
	UCSRC_reg_data = (UCSRC_reg_data & PARITY_BIT_MASK) | (((PARITY) & 0x03) << UCSRC_UPM0)

/********************** STOP BIT SETTINGS **********************/
#define STOP_BIT_1			0
#define STOP_BIT_2			1

#define STOP_BIT		STOP_BIT_1

#define STOP_BIT_SEL(STOP)		\
	((STOP)? SET_BIT(UCSRC_reg_data, UCSRC_USBS) : CLEAR_BIT(UCSRC_reg_data, UCSRC_USBS))

/********************** CLOCK POLARITY FOR SYNCH ONLY **********************/
//NEEDED FOR FOR UART MODE ONLY

#define XCK_TX_RISING		0//XCK_RX_FALLING <- SLAVE
#define XCK_TX_FALLING		1//XCK_RX_RISING  <- SLAVE

#define XCK_POLARITY	XCK_TX_RISING

#define XCK_POLARITY_SEL(POLARTIY)	\
	((POLARTIY)? SET_BIT(UCSRC_reg_data, UCSRC_UCPOL) : CLEAR_BIT(UCSRC_reg_data, UCSRC_UCPOL))

/********************** MODES IN SYCHRONOUS **********************/
/* THIS CONFIGURATION ONLY NEEDED IF SENDING OR RECEVING ONLY
 * WHICH IS NOT NEEDED IF USING BOTH TX & RX					*/

#define XCK_PIN				PB0

#define SYNCH_MODE_MASTER	1
#define SYNCH_MODE_SLAVE	0

#define SYNCH_MODE		SYNCH_MODE_SLAVE // only for the XCK pin direction

#define SYNCH_MODE_SEL(MODE)	\
		DIO_vidSetPinDir(XCK_PIN, MODE) //OUTPUT FOR MASTER

#endif
