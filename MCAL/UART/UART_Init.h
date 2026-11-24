#ifndef UART_UART_INIT_H_
#define UART_UART_INIT_H_

void USRT_voidInitMaster();//USRT
void USRT_voidInitSlave();//USRT

void USART_voidInitMaster();//USART
void USART_voidInitSlave();//USART

void USART_voidSendData(uint8 uint8copy_data);//8 bit or lower
void USART_voidSendStr(uint8 *string);
uint8	 USART_uint8ReceiveData();

void USART_voidEmptyInterruptOn();
void USART_voidEmptyInterruptOff();

void USART_voidSendNinthBit(uint8 uint8copy_ninth_bit); //Only the ninth bit
uint8   USART_uint8ReceiveNinthBit(); //Only the ninth bit

void USART_voidOn();
void USART_voidOff();

//void USART_voidMPCM(); // Multi-processor Communication Mode

void (*USART_RX_COMPLETE_FUN)(void);
void (*USART_EMPTY_REG_FUN)(void);//must disable rx and tx interrupts
void (*USART_TX_COMPLETE_FUN)(void);

#endif
