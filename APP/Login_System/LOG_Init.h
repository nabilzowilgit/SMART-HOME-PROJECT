/*
 * LOG_Init.h
 *
 *  Created on: Nov 23, 2026
 *      Author: peter
 */

#ifndef APP_LOGIN_SYSTEM_LOG_INIT_H_
#define APP_LOGIN_SYSTEM_LOG_INIT_H_
#include "../../SERV/std_types.h"
#define NON 0


uint8 LOG_StoreData(uint8 *name, uint8 *pass);// if given 64 then it's full
void LOG_MoveData(uint8 from, uint8 to);
uint8 LOG_BlockNum(uint8 start);//give a number of block starting with a given block
void LOG_DELdata(uint8 *name, uint8 *pass);

uint8 LOG_CheckData(uint8 *name, uint8 *pass);// give the block of the given data +1 and 0 mean NOT FOUND


#endif /* APP_LOGIN_SYSTEM_LOG_INIT_H_ */
