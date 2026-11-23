#include "../../SERV/std_types.h"
#include "../../SERV/bit_math.h"
#include "../../MCAL/UART/UART_reg.h"
#include "UART_Confg.h"
#include "UART_Init.h"





//void HUART_vidInit(){
//
//	UBRRL = BAUDRATE_16MH_SELECT ;  /* Set baud rate */
//	SET_BIT(UCSRB,UCSRB_TXEN);
//	SET_BIT(UCSRB,UCSRB_RXEN);
//	UCSRC = 0x86;
//}


void MUART_vidInit(){

#if    (Mode_Select == Synchronous_Operation)
	UCSRC |= 0xC0;
#elif  (Mode_Select == Asynchronous_Operation)
	UCSRC |= 0x80;
#endif

#if   (Parity_Mode==Even_Parity)
	UCSRC |= 0xA0;
#elif (Parity_Mode==Odd_Parity )
	UCSRC |= 0xB0;
#endif

#if   (STOP_BIT_SELECT ==STOP_2_BIT)
	UCSRC |= 0x88;
#elif  (STOP_BIT_SELECT ==STOP_1_BIT)
	UCSRC |= 0x80;
#endif

#if (DATA_BITS== Data_5BIT)             //number of data bits
	UCSRC |= 0x80;
#elif 	(DATA_BITS==Data_6BIT)
	UCSRC |= 0x82;
#elif 	(DATA_BITS==Data_7BIT)
	UCSRC |= 0x84;
#elif 	(DATA_BITS==Data_8BIT)
	UCSRC |= 0x86;
#elif 	(DATA_BITS==Data_9BIT)
	UCSRC |= 0x84;
	SET_BIT(UCSRB,UCSRB_UCSZ2);
#endif

	UBRRL = BAUDRATE_16MH_SELECT ;                   /* Set baud rate */
	SET_BIT(UCSRB,UCSRB_TXEN);
	SET_BIT(UCSRB,UCSRB_RXEN);

 }




//void UART_vidInit(){
//	UBRRL = BAUDRATE_16MH_SELECT ;                   /* Set baud rate */
//	SET_BIT(UBRRH,UCSRC_URSEL);
//#if    (Mode_Select == Synchronous_Operation)
//	SET_BIT(UCSRC,UCSRC_UMSEL);
//#elif  (Mode_Select == Asynchronous_Operation)
//	CLR_BIT(UCSRC,UCSRC_UMSEL);
//#endif
//
//#if   (Parity_Mode==Even_Parity)
//	SET_BIT(UCSRC,UCSRC_UPM1);
//#elif (Parity_Mode==Odd_Parity )
//	SET_BIT(UCSRC,UCSRC_UPM1);
//	SET_BIT(UCSRC,UCSRC_UPM0);
//#endif
//
//#if   (STOP_BIT_SELECT ==STOP_2_BIT)
//	SET_BIT(UCSRC,UCSRC_USBS);
//#elif  (STOP_BIT_SELECT ==STOP_1_BIT)
//	CLR_BIT(UCSRC,UCSRC_USBS);
//#endif
//
//#if (DATA_BITS== Data_5BIT)             //number of data bits
//	CLR_BIT(UCSRC,UCSRC_UCSZ0);
//	CLR_BIT(UCSRC,UCSRC_UCSZ1);
//	CLR_BIT(UCSRB,UCSRB_UCSZ2);
//#elif 	(DATA_BITS==Data_6BIT)
//	SET_BIT(UCSRC,UCSRC_UCSZ0);
//	CLR_BIT(UCSRC,UCSRC_UCSZ1);
//	CLR_BIT(UCSRB,UCSRB_UCSZ2);
//#elif 	(DATA_BITS==Data_7BIT)
//	CLR_BIT(UCSRC,UCSRC_UCSZ0);
//	SET_BIT(UCSRC,UCSRC_UCSZ1);
//	CLR_BIT(UCSRB,UCSRB_UCSZ2);
//#elif 	(DATA_BITS==Data_8BIT)
//	SET_BIT(UCSRC,UCSRC_UCSZ0);
//	SET_BIT(UCSRC,UCSRC_UCSZ1);
//	CLR_BIT(UCSRB,UCSRB_UCSZ2);
//#elif 	(DATA_BITS==Data_9BIT)
//	SET_BIT(UCSRC,UCSRC_UCSZ0);
//	SET_BIT(UCSRC,UCSRC_UCSZ1);
//	SET_BIT(UCSRB,UCSRB_UCSZ2);
//#endif
//
//	SET_BIT(UCSRB,UCSRB_TXEN);
//	SET_BIT(UCSRB,UCSRB_RXEN);
//
// }
 uint8 UART_u8RecevieData(){
	 while(GET_BIT(UCSRA,UCSRA_RXC) == 0);	    /* Wait for data to be received */
	 return UDR;                      // why ?? /* Get and return received data from buffer */
 }
 void UART_vidSendData(uint8 u8DataCopy){
	 while(GET_BIT(UCSRA,UCSRA_UDRE) == 0);  /* Wait for empty transmit buffer */
	 UDR = u8DataCopy;       /* Put data into buffer, sends the data */
 }
