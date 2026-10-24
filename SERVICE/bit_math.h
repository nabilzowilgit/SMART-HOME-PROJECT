#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define GET_BIT(REG, bit)			(1   & 	(REG >> bit))
#define SET_BIT(REG, bit)			(REG |=  (1 << bit))
#define CLEAR_BIT(REG, bit)			(REG &= ~(1 << bit))
#define TOGGLE_BIT(REG, bit)		(REG ^=  (1 << bit))
#define TOGGLE_REG(REG)				(REG  =  ~REG)

#endif
