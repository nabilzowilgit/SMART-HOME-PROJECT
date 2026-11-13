#ifndef HAL_HAL_ADC_ADC_INIT_H_
#define HAL_HAL_ADC_ADC_INIT_H_

void (*ADC_ISR_FUN)(void);

typedef enum
{
	CH0,
    CH1,
    CH2,
    CH3,
    CH4,
    CH5,
    CH6,
    CH7,

	CH0_0_10x,
	CH1_0_10x,

	CH0_0_200x,
	CH1_0_200x,

	CH2_2_10x,
	CH3_2_10x,

	CH2_2_200x,
	CH3_2_200x,

	CH0_1_1x,
	CH1_1_1x,
	CH2_1_1x,
	CH3_1_1x,
	CH4_1_1x,
	CH5_1_1x,
	CH6_1_1x,
	CH7_1_1x,

	CH0_2_1x,
	CH1_2_1x,
	CH2_2_1x,
	CH3_2_1x,
	CH4_2_1x,
	CH5_2_1x,

	Vbg1_22,
	GND

}channel_sel;

void ADC_voidInit();

void ADC_voidSwitchOn();
void ADC_voidSwitchOff();

void ADC_voidChannelSel(u8 u8copy_channel);

void ADC_voidInterruptOn();
void ADC_voidInterruptOff();

void ADC_voidStartConversion(u8 u8copy_channel);//ACTION HAPPENS WHEN INTERRUPT OCCURS
u16  ADC_u16RetrunResult(u8 u8copy_channel);//POOLING TILL INTERUPT FLAG

void ADC_voidAutoTrigerOn();
void ADC_voidAutoTrigerOff();

#endif
