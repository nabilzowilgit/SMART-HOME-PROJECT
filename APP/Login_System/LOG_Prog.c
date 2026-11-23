/*
 * LOG_Prog.c
 *
 *  Created on: Nov 23, 2026
 *      Author: peter
 */
#include "../../SERV/std_types.h"
#include "LOG_Init.h"
#include "../../MCAL/EEPROM/EEPROM_init.h"

uint8 LOG_StoreData(uint8 *name, uint8 *pass){
	uint8 block=0;
	for (block=0; block<64; block++){
		if (EEPROM_u8ReadData(block*16)==0xFF){
			uint16 add=block*16;
			for(uint8 i=0;name[i] != '\0';i++){
				EEPROM_voidWriteData(add,name[i]);
				add++;
			}
			for(uint8 i=0;pass[i] != '\0';i++){
				EEPROM_voidWriteData(add,pass[i]);
				add++;
			}
		}
	}
	return block;
}

void LOG_MoveData(uint8 from, uint8 to){
	for(uint8 i=0;i<16;i++){
		EEPROM_voidWriteData((to*16)+i,EEPROM_u8ReadData((from*16)+i));
	}
}
uint8 LOG_BlockNum(uint8 start){
	uint8 num=0;
	while (EEPROM_u8ReadData(start*16)!=0xFF){
		num++;
		start++;
	}
	return num;
}

void LOG_DELdata(uint8 *name, uint8 *pass){
	uint16 add=LOG_CheckData(name,pass);

	if(add==0){
		return;
	}
	else {
		uint8 num=LOG_BlockNum(add-1);
		add=(add-1);
		num+=add;
		for(uint8 i=add;i<num;i++){
			LOG_MoveData(i+1,i);
		}
		num*=16;
			for(uint16 i=num;num<(i+16);num++){
				EEPROM_voidWriteData(num,0xFF);
			}
	}


}

uint8 LOG_CheckData(uint8 *name, uint8 *pass){
	uint8 data[16];
	for (uint8 i=0;i<8;i++){
		data[i]=name[i];
	}
	for (uint8 i=0;i<8;i++){
		data[i+8]=pass[i];
	}
	uint8 count=0,block=0;
	uint16 add=0;
	while(EEPROM_u8ReadData(add)!=0xFF && block < 64){
		for (uint8 i=0;i<16;i++){
			if (EEPROM_u8ReadData(add)==data[i]){
				count++;
				add++;
			}
			else{
				add-=count;
				count=0;
				add+=16;
				block++;
				break;
			}
		}
		if(count==16){
			return block+1;
		}
	}
	return NON;
}
