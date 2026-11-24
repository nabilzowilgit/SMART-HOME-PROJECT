#ifndef APP_LOGIN_SYSTEM_LOG_INIT_H_
#define APP_LOGIN_SYSTEM_LOG_INIT_H_

#include "../../SERV/std_types.h"

#define NON 			0
#define VALID			1
#define NOT_VALID		0
#define EMPTY			0xFF // DEFAULT VALUE FOR AN EMPTY ADDRESS

#define USERS_LIMIT			3
#define LETTERS_LIMIT		8

#define ADMIN_START_ADDRESS		0x00
#define USERS_START_ADDRESS		0x10	//TO 0x03 AS THE LIMIT IS ONLY 3 USERS

uint8 	curent_users_count;	//STORED AT THE EEPROM IN ADDRESS 0x40
#define CURRENT_USERS_COUNT_ADDRESS		0x40

uint8 	empty_user_address;

void  LOG_voidInit();
uint8 LOG_u8StoreUser (uint8 *user_name, uint8 *password);
uint8 LOG_u8CheckUser (uint8 *user_name, uint8 *password);

void  LOG_voidStoreAdmin(uint8 *user_name, uint8 *password);
uint8 LOG_u8CheckAdmin(uint8 *user_name, uint8 *password);
uint8 LOG_u8DeleteUser(uint8 *user_name, uint8 *password);

//uint8 LOG_StoreData(uint8 *name, uint8 *pass);// if given 64 then it's full
//void  LOG_MoveData(uint8 from, uint8 to);
//uint8 LOG_BlockNum(uint8 start);//give a number of block starting with a given block
//void  LOG_DELdata(uint8 *name, uint8 *pass);
//uint8 LOG_CheckData(uint8 *name, uint8 *pass);// give the block of the given data +1 and 0 mean NOT FOUND

#endif /* APP_LOGIN_SYSTEM_LOG_INIT_H_ */
