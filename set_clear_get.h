/*
 * set_clear_get.h
 * This is a header file which:
 * - defines some general functions as macros to:
 *     >> setting given bit in given register
 *     >> clearing given bit in given register
 *     >> reading given bit in input register
 *
 *  Created on: 5/1/2018
 *      Author: Asmaa
 */

#ifndef SET_CLEAR_GET_H_
#define SET_CLEAR_GET_H_

#define setBit(reg,bit)  reg |=(1<<bit)
#define clearBit(reg,bit)  reg &=(~(1<<bit))
#define getBit(reg,bit) (reg>>bit)&1


#endif /* SET_CLEAR_GET_H_ */
