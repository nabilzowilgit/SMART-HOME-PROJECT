#ifndef HAL_LM35_LM35_INIT_H_
#define HAL_LM35_LM35_INIT_H_

#define LM35_CHANNEL			CH0
#define LM35_CONVETION_RATIO	2.06

void LM35_voidGetTemp(void);

void LM35_voidInit(void);

void LM35_voidStart(void);
void LM35_voidStop(void);

#endif
