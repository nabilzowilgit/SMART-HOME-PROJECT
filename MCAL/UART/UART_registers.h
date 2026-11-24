#ifndef UART_UART_REGISTERS_H_
#define UART_UART_REGISTERS_H_

#define ISR(vector)		\
    void vector(void)  __attribute__ ((signal, used, externally_visible)); \
    void vector(void)

#define USART_RX_COMPLETE_VECTOR13    	__vector_13
#define USART_EMPTY_REG_VECTOR14   		__vector_14
#define USART_TX_COMPLETE_VECTOR15    	__vector_15

#define UDR_R			(*((volatile uint8*)(0x2C))) // RECIVE OR SEND DATA THROUGH IT

#define UCSRA_R			(*((volatile uint8*)(0x2B))) // flags
#define UCSRA_RXC		7 //R	Receive Complete -> set when there are unread data in the receive buffer
#define UCSRA_TXC		6 //R/W Transmit Complete-> set when the entire frame in the transmit Shift Register has been shifted out
#define UCSRA_UDRE		5 //R	Transmit buffer is empty; ready to write new TX data
#define UCSRA_FE		4 //R 	Frame Error
#define UCSRA_DOR		3 //R 	Data OverRun
#define UCSRA_PE		2 //R	Parity Error
#define UCSRA_U2X		1 //R/W Double transmission speed
#define UCSRA_MPCM		0 //R/W @page 157

#define UCSRB_R			(*((volatile uint8*)(0x2A))) // interrupts
#define UCSRB_RXCIE		7 //R/W RX Complete Interrupt Enable
#define UCSRB_TXCIE     6 //R/W TX Complete Interrupt Enable
#define UCSRB_UDRIE     5 //R/W USART Data Register Empty Interrupt Enable
#define UCSRB_RXEN      4 //R/W Receiver Enable
#define UCSRB_TXEN      3 //R/W Transmitter Enable
#define UCSRB_UCSZ2     2 //R/W Bits Settings -> THE REST IN UCSRC_R
#define UCSRB_RXB8      1 /*R   RXB8 is the ninth data bit, MUST BE READ FIRST*/
#define UCSRB_TXB8      0 /*R/W TXB8 is the ninth data bit, MUST BE WRITTEN FIRST*/

#define UCSRC_R			(*((volatile uint8*)(0x40))) //interrupts
#define UCSRC_URSEL     7 // Register Select -> URSEL must be one when writing the UCSRC
#define UCSRC_UMSEL     6 // USART Mode Select -> LOW -> ASYNCHRONOUS
#define UCSRC_UPM1      5 // Parity Mode
#define UCSRC_UPM0      4 // Parity Mode
#define UCSRC_USBS      3 // Stop Bit Select -> LOW -> 1-BIT
#define UCSRC_UCSZ1     2 // Bits Settings
#define UCSRC_UCSZ0     1 // Bits Settings
#define UCSRC_UCPOL     0 // // Clock polarity in synchronous mode

#define UBRRH_R			(*((volatile uint8*)(0x40))) // Baud Rate

#define UBRRL_R			(*((volatile uint8*)(0x29))) // Baud Rate -> not used currently

#define SREG_R			(*((volatile uint8*)(0x5F)))	// Status Register
#define SREG_GIE  		7 // Global Interrupt Enable

#endif
