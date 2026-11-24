#include "../../SERV/std_types.h"

#include "LOG_Init.h"
#include "../../MCAL/EEPROM/EEPROM_init.h"

void LOG_voidInit()
{
	uint8 admin_user_name[LETTERS_LIMIT] = "admin";
	uint8 admin_password[LETTERS_LIMIT] = "12345678";

	LOG_voidStoreAdmin(admin_user_name, admin_password);

	curent_users_count = EEPROM_u8ReadChar(CURRENT_USERS_COUNT_ADDRESS);

	if(curent_users_count == EMPTY)
	{
		empty_user_address = USERS_START_ADDRESS;
		curent_users_count = 0; //THERE WAS NO USERS
		EEPROM_voidStoreChar(CURRENT_USERS_COUNT_ADDRESS, curent_users_count);
	}
}

uint8 LOG_u8StoreUser (uint8 *user_name, uint8 *password)
{
	 // WE CAN PREVENT REPEATITOIN LATER
	if(curent_users_count != USERS_LIMIT) // USERS NOT FULL STILL
	{
		EEPROM_voidStoreStr(empty_user_address, user_name);
		EEPROM_voidStoreStr(empty_user_address + LETTERS_LIMIT, password);
		EEPROM_voidStoreChar(CURRENT_USERS_COUNT_ADDRESS, ++curent_users_count);

		return VALID;
	}

	return NOT_VALID;
}

uint8 LOG_u8CheckUser (uint8 *user_name, uint8 *password)
{
	if(curent_users_count) //CHECKING IF THERE ARE USERS OR NOT
	{
		for(uint8 users = 0; users < USERS_LIMIT; users++) // CHECKING ON THE 3 USERS
		{
			for(uint8 letters = 0; letters < LETTERS_LIMIT; letters++)	//CHECKING ON THE USER NAMES AND PASSWORDS OF THE USERS
			{
				if((user_name[letters] != EEPROM_u8ReadChar(USERS_START_ADDRESS * users))
				&& (password [letters] != EEPROM_u8ReadChar(USERS_START_ADDRESS * users + LETTERS_LIMIT)))
				{
					if((users == USERS_LIMIT - 1) && (letters == LETTERS_LIMIT - 1))
					{
						/* THAT MEANS THAT WE SEARCHED ALL THE DATABASE
						 * AND STILL THE DATA GIVEN DOES NOT MATCH
						 */
						return NOT_VALID;
					}

					break;
				}
			}
		}

		return VALID;
	}
	return NOT_VALID;
}

void LOG_voidStoreAdmin(uint8 *user_name, uint8 *password)
{
	EEPROM_voidStoreStr(ADMIN_START_ADDRESS, user_name);
	EEPROM_voidStoreStr(ADMIN_START_ADDRESS + LETTERS_LIMIT, password);
}

uint8 LOG_u8CheckAdmin (uint8 *user_name, uint8 *password)
{
	for(uint8 letters = 0; letters < LETTERS_LIMIT; letters++)	//CHECKING ON THE USER NAMES AND PASSWORDS OF THE USERS
	{
		if((user_name[letters] != EEPROM_u8ReadChar(ADMIN_START_ADDRESS))
		&& (password [letters] != EEPROM_u8ReadChar(ADMIN_START_ADDRESS + LETTERS_LIMIT)))
		{
			return NOT_VALID; // WRONG USER NAME OR PASSWORD
		}
	}

	return VALID;
}

uint8 LOG_u8DeleteUser(uint8 *user_name, uint8 *password)
{
	if(LOG_u8CheckUser(user_name, password))
	{
		EEPROM_voidStoreChar(CURRENT_USERS_COUNT_ADDRESS, --curent_users_count);
		return VALID;
	}

	return NOT_VALID;
}

//uint8 LOG_StoreData(uint8 *name, uint8 *pass){
//	uint8 block=0;
//	for (block=0; block<64; block++){
//		if (EEPROM_u8ReadData(block*16)==0xFF){
//			uint16 add=block*16;
//			for(uint8 i=0;name[i] != '\0';i++){
//				EEPROM_voidWriteData(add,name[i]);
//				add++;
//			}
//			for(uint8 i=0;pass[i] != '\0';i++){
//				EEPROM_voidWriteData(add,pass[i]);
//				add++;
//			}
//		}
//	}
//	return block;
//}
//
//void LOG_MoveData(uint8 from, uint8 to){
//	for(uint8 i=0;i<16;i++){
//		EEPROM_voidWriteData((to*16)+i,EEPROM_u8ReadData((from*16)+i));
//	}
//}
//
//uint8 LOG_BlockNum(uint8 start){
//	uint8 num=0;
//	while (EEPROM_u8ReadData(start*16)!=0xFF){
//		num++;
//		start++;
//	}
//	return num;
//}
//
//void LOG_DELdata(uint8 *name, uint8 *pass){
//	uint16 add=LOG_CheckData(name,pass);
//
//	if(add==0){
//		return;
//	}
//	else {
//		uint8 num=LOG_BlockNum(add-1);
//		add=(add-1);
//		num+=add;
//		for(uint8 i=add;i<num;i++){
//			LOG_MoveData(i+1,i);
//		}
//		num*=16;
//			for(uint16 i=num;num<(i+16);num++){
//				EEPROM_voidWriteData(num,0xFF);
//			}
//	}
//
//
//}
//
//uint8 LOG_CheckData(uint8 *name, uint8 *pass){
//	uint8 data[16];
//	for (uint8 i=0;i<8;i++){
//		data[i]=name[i];
//	}
//	for (uint8 i=0;i<8;i++){
//		data[i+8]=pass[i];
//	}
//	uint8 count=0,block=0;
//	uint16 add=0;
//	while(EEPROM_u8ReadData(add)!=0xFF && block < 64){
//		for (uint8 i=0;i<16;i++){
//			if (EEPROM_u8ReadData(add)==data[i]){
//				count++;
//				add++;
//			}
//			else{
//				add-=count;
//				count=0;
//				add+=16;
//				block++;
//				break;
//			}
//		}
//		if(count==16){
//			return block+1;
//		}
//	}
//	return NON;
//}
//
