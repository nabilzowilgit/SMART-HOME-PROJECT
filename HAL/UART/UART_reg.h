#ifndef MCAL_UART_UART_REG_H_
#define MCAL_UART_UART_REG_H_




#define UDR        *((volatile uint8 *) 0x2C)
#define UCSRA      *((volatile uint8 *) 0x2B)
#define UCSRB      *((volatile uint8 *) 0x2A)
#define UCSRC      *((volatile uint8 *) 0x40)
#define UBRRH      *((volatile uint8 *) 0x40)
#define UBRRL      *((volatile uint8 *) 0x29)


/*------ UCSRA -------*/
#define UCSRA_UDRE     (uint8)5
#define UCSRA_TXC      (uint8)6
#define UCSRA_RXC      (uint8)7

/*------ UCSRB --------*/

#define UCSRB_RXEN  (uint8)4
#define UCSRB_TXEN  (uint8)3
#define UCSRB_UCSZ2 (uint8)2

/*------ UCSRC --------*/
#define UCSRC_URSEL  (uint8)7
#define UCSRC_UMSEL  (uint8)6
#define UCSRC_UPM1   (uint8)5
#define UCSRC_UPM0   (uint8)4
#define UCSRC_USBS   (uint8)3
#define UCSRC_UCSZ1  (uint8)2
#define UCSRC_UCSZ0  (uint8)1
#define UCSRC_UCPOL  (uint8)0



#endif /* MCAL_MUART_MUART_REG_H_ */
