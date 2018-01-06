/*
 * main.c
 * This is a code which:
 *   >>displays counter from 0:99 on tow 7-segments
 * According to my wiring :
 *   >> (a b c d e g f dot) of 7-segment is connected to port from bit7:bit0 (76543210)
 *
 *  Created on: 5/1/2018
 *      Author: Asmaa
 */

/*includes*/
#include<util/delay.h>
#include"STDTYPES.h"
#include"DIO.h"
#include"set_clear_get.h"

/*functions prototyping*/
void display(u8* reg ,u8 num );

/*main function*/
int main(void)
{
	u8 i,j;                 /*counters*/

	setBit(DDRB,0);         /*make bit0 port B output for com of 1st 7-segment*/
	setBit(DDRB,1);         /*make bit1 port B output for com of 2nd 7-segment*/

	DDRC=0xFF;             /*make all of port C outputs for 1st 7-segment*/
	DDRD=0xFF;             /*make all of port D outputs for 2nd 7-segment*/

	setBit(PORTB,0);       /*output 1 to com of 1st 7-segment because it is common vcc*/
	setBit(PORTB,1);       /*output 1 to com of 2nd 7-segment because it is common vcc*/

	while(1)               /*infinite loop*/
	{
		for(i=0;i<=9;i++)            /*loop from 0:9 for 1st 7-segment on port C*/
		{
			display(&PORTC,i);       /*display current number on 1st 7-segment*/
			for(j=0;j<=9;j++)        /*loop from 0:9 for 2nd 7-segment on port D*/
			{
				display(&PORTD,j);   /*display current number on 2nd 7-segment*/
				_delay_ms(400);
			}
			_delay_ms(200);
		}
	}
	return 0;
}

/********************
 * This is a function which:
 *   >>takes address of output register and num required to be displayed
 *   >>outputs value on register according to required number and 7-segment configuration
 *******************/
void display(u8* reg,u8 num)
{
	switch(num)                   /*check on required number to choose the right case*/
	{
		case 0:
			*reg=0b00000100;      /*assign this output to the value of given register*/
			break;
		case 1:
			*reg=0b10011110;
			break;
		case 2:
			*reg=0b00100010;
			break;
		case 3:
			*reg=0b00001010;
			break;
		case 4:
			*reg=0b10011000;
			break;
		case 5:
			*reg=0b01001000;
			break;
		case 6:
			*reg=0b01000000;
			break;
		case 7:
			*reg=0b00011110;
			break;
		case 8:
			*reg=0b00000000;
			break;
		case 9:
			*reg=0b00001000;
			break;
		default:
			*reg=0b00000100;
			break;
	}
}

