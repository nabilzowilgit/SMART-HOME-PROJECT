#include "../../SERV/std_types.h"
#include "../../SERV/bit_math.h"

#include "../../MCAL/DIO/dio_init.h"

#include "UART_registers.h"

#include "UART_config.h"
#include "UART_init.h"

/********************** NOT FOR USER **********************/
static void USART_voidTransmitterOn();
static void USART_voidTransmitterOff();
static void USART_voidTxInterruptOn();
static void USART_voidTxInterruptOff();//Disable if using the pooling in writing

static void USART_voidReceiverOn();
static void USART_voidReceiverOff();
static void USART_voidRxInterruptOn();
static void USART_voidRxInterruptOff();//Disable if using the pooling in reading
/**********************************************************/

#if USART_MODE == MODE_SYNCH	//Excluding code

void USRT_voidInitMaster()//SENDING AND RECEIVNING
{
	BAUD_RATE_SEL(USRT_BAUD_RATE_9600);//FOR xck pin

	CHAR_SIZE_SEL(CHAR_SIZE);
	USART_MODE_SEL(MODE_SYNCH);
	PARITY_BIT_SEL(PARITY_BIT);
	STOP_BIT_SEL(STOP_BIT);

	XCK_POLARITY_SEL(XCK_POLARITY);
	SYNCH_MODE_SEL(SYNCH_MODE_MASTER);

	UCSRC_R = UCSRC_reg_data;

	USART_voidTransmitterOn();
	USART_voidTxInterruptOn();

//	USART_voidReceiverOn();
//	USART_voidRxInterruptOn();

	SET_BIT(SREG_R, SREG_GIE);//GLOBAL INTERRUPT
}

void USRT_voidInitSlave()//RECEIVNING ONLY
{
//	BAUD_RATE_SEL(USRT_BAUD_RATE_9600);//FOR MASTER ONLY

	CHAR_SIZE_SEL(CHAR_SIZE);
	USART_MODE_SEL(MODE_SYNCH);
	PARITY_BIT_SEL(PARITY_BIT);
	STOP_BIT_SEL(STOP_BIT);

	XCK_POLARITY_SEL(XCK_TX_RISING);
	SYNCH_MODE_SEL(SYNCH_MODE_SLAVE);

	UCSRC_R = UCSRC_reg_data;

	USART_voidReceiverOn();
	USART_voidRxInterruptOn();

	SET_BIT(SREG_R, SREG_GIE);//GLOBAL INTERRUPT
}

#elif USART_MODE == MODE_ASYNCH

void USART_voidInitMaster()//SENDING AND RECEIVNING
{
	BAUD_RATE_SEL(BAUD_RATE);

	CHAR_SIZE_SEL(CHAR_SIZE);
	USART_MODE_SEL(MODE_ASYNCH);
	PARITY_BIT_SEL(PARITY_BIT);
	STOP_BIT_SEL(STOP_BIT);

	UCSRC_R = UCSRC_reg_data;

	USART_voidTransmitterOn();
	USART_voidTxInterruptOn();

	USART_voidReceiverOn();
	USART_voidRxInterruptOn();

	SET_BIT(SREG_R, SREG_GIE);//GLOBAL INTERRUPT
}

void USART_voidInitSlave()//only receiving
{
	BAUD_RATE_SEL(BAUD_RATE);

	CHAR_SIZE_SEL(CHAR_SIZE);
	USART_MODE_SEL(MODE_ASYNCH);
	PARITY_BIT_SEL(PARITY_BIT);
	STOP_BIT_SEL(STOP_BIT);

	UCSRC_R = UCSRC_reg_data;

	USART_voidTransmitterOn();
	USART_voidTxInterruptOn();

	USART_voidReceiverOn();
	USART_voidRxInterruptOn();

	SET_BIT(SREG_R, SREG_GIE);//GLOBAL INTERRUPT
}

#endif

void USART_voidSendData(uint8 uint8copy_data)
{
	USART_voidTxInterruptOff();//only when using the pooling technique
	USART_voidRxInterruptOff();//only when using the pooling technique
	while(!(GET_BIT(UCSRA_R, UCSRA_UDRE))); //you must use with empty flag

	UDR_R = uint8copy_data;
}

void USART_voidSendStr(uint8 *string)//ONLY USE IT WITHOUT INTERRUPTS
{
    while (*string != '\0')
    {
    	while(!(GET_BIT(UCSRA_R, UCSRA_UDRE)));
        USART_voidSendData(*string);
        string++;
    }
}

uint8 USART_uint8ReceiveData()
{
	USART_voidTxInterruptOff();//only when using the pooling technique
	USART_voidRxInterruptOff();//only when using the pooling technique
	while(!(GET_BIT(UCSRA_R, UCSRA_RXC)));

	return UDR_R;
}

void USART_voidEmptyInterruptOn()//READY to send data to UDR
{
	USART_voidTxInterruptOff();
	USART_voidRxInterruptOff();

	SET_BIT(UCSRB_R, UCSRB_UDRIE);
	SET_BIT(SREG_R, SREG_GIE);
}

void USART_voidEmptyInterruptOff()
{
	CLEAR_BIT(UCSRB_R, UCSRB_UDRIE);
}

void USART_voidOn()
{
	USART_voidTransmitterOn();
	USART_voidTxInterruptOn();
	USART_voidReceiverOn();
	USART_voidRxInterruptOn();
}

void USART_voidOff()
{
	USART_voidTransmitterOff();
	USART_voidTxInterruptOff();
	USART_voidReceiverOff();
	USART_voidRxInterruptOff();
}

void USART_voidSendNinthBit(uint8 uint8copy_ninth_bit)//Only the ninth bit
{
	UCSRB_R |= (uint8copy_ninth_bit & 1);
}

uint8 USART_uint8ReceiveNinthBit()//Only the ninth bit
{
	return (GET_BIT(UCSRB_R, UCSRB_RXB8));
}

/********************** NOT FOR USER **********************/
static void USART_voidTransmitterOn();
static void USART_voidTransmitterOff();
static void USART_voidTxInterruptOn();
static void USART_voidTxInterruptOff();//Disable if using the pooling in writing

static void USART_voidReceiverOn();
static void USART_voidReceiverOff();
static void USART_voidRxInterruptOn();
static void USART_voidRxInterruptOff();//Disable if using the pooling in reading

static void USART_voidTransmitterOn()
{
	SET_BIT(UCSRB_R, UCSRB_TXEN);
}

static void USART_voidTransmitterOff()
{
	CLEAR_BIT(UCSRB_R, UCSRB_TXEN);
}

static void USART_voidReceiverOn()
{
	SET_BIT(UCSRB_R, UCSRB_RXEN);
}

static void USART_voidReceiverOff()
{
	CLEAR_BIT(UCSRB_R, UCSRB_RXEN);
}

static void USART_voidRxInterruptOn()
{
	SET_BIT(UCSRB_R, UCSRB_RXCIE);
}

static void USART_voidRxInterruptOff()
{
	CLEAR_BIT(UCSRB_R, UCSRB_RXCIE);
}

static void USART_voidTxInterruptOn()
{
	SET_BIT(UCSRB_R, UCSRB_TXCIE);
}

static void USART_voidTxInterruptOff()
{
	CLEAR_BIT(UCSRB_R, UCSRB_TXCIE);
}
/**********************************************************/

ISR (USART_RX_COMPLETE_VECTOR13)
{
	USART_RX_COMPLETE_FUN();
}

ISR (USART_EMPTY_REG_VECTOR14)
{
	USART_EMPTY_REG_FUN();
}

ISR (USART_TX_COMPLETE_VECTOR15)
{
	USART_TX_COMPLETE_FUN();
}
