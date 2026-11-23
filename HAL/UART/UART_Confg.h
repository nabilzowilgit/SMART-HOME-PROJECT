#ifndef MCAL_UART_UART_CONFG_H_
#define MCAL_UART_UART_CONFG_H_



/****************************Mode_Select **********************************/

#define  Asynchronous_Operation 0U
#define  Synchronous_Operation  1U

#define MODE_SELECT   Asynchronous_Operation

/************************ Parity_Mode *************************************/
#define         Disabled         0U
#define         Even_Parity      2U
#define         Odd_Parity       3U

#define Parity_Mode      Disabled
/*****************************Stop_Bit_Select *****************************/
#define STOP_1_BIT  0U
#define STOP_2_BIT  1U

#define STOP_BIT_SELECT    STOP_1_BIT
/*********************** Data_bits ****************************************/

#define   Data_5BIT   0U
#define   Data_6BIT   1U
#define   Data_7BIT   2U
#define   Data_8BIT   3U
#define   Data_9BIT   4U

#define DATA_BITS   Data_8BIT

/************************** Boud_Rate 8MHZ************************/

#define   BaudRate_8MH_4800      103
#define   BaudRate_8MH_9600      51
#define   BaudRate_8MH_14_4k     34
#define   BaudRate_8MH_19_2k     25
#define   BaudRate_8MH_28_8k     16
#define   BaudRate_8MH_38_4k     12
#define   BaudRate_8MH_57_6k     8
#define   BaudRate_8MH_76_8k     6
#define   BaudRate_8MH_115_2k    3
#define   BaudRate_8MH_250k      1

#define BAUDRATE_8MH_SELECT    Baud_Rate_9600


/************************** Boud_Rate 16MHZ************************/

#define   BaudRate_16MH_4800      207
#define   BaudRate_16MH_9600      103
#define   BaudRate_16MH_14_4k     68
#define   BaudRate_16MH_19_2k     51
#define   BaudRate_16MH_28_8k     34
#define   BaudRate_16MH_38_4k     25
#define   BaudRate_16MH_57_6k     16
#define   BaudRate_16MH_76_8k     12
#define   BaudRate_16MH_115_2k    8
#define   BaudRate_16MH_250k      3

#define BAUDRATE_16MH_SELECT    BaudRate_16MH_9600

#endif
