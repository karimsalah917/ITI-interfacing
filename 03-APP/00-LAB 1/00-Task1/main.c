/******************************************************************************
* LAB: ONE
* Project Name: task1
* Project info: two leds with a delay 1 sec 
* Modules used: DIO
* File Name: task1.c
* Author: karim salah
*
*****************************************************************************/
#define F_CPU 8000000UL
#include "DIO.h"

#include <util/delay.h>

int main(void)
{/*Confifuration and intialisation*/
	DIO_enumSetPinConfig(DIO_enumPortA,DIO_enumPin0,DIO_enumOutput);
	DIO_enumSetPin(DIO_enumPortA,DIO_enumPin0,DIO_enumLogicLow);
	DIO_enumSetPinConfig(DIO_enumPortA,DIO_enumPin1,DIO_enumOutput);
	DIO_enumSetPin(DIO_enumPortA,DIO_enumPin1,DIO_enumLogicLow);
    while(1)
    {
        DIO_enumSetPin(DIO_enumPortA,DIO_enumPin0,DIO_enumLogicHigh); /*turning first led on*/
		 _delay_ms(1000); /*wait 1 sec*/
  DIO_enumSetPin(DIO_enumPortA,DIO_enumPin0,DIO_enumLogicLow);/*turning first led off*/
        DIO_enumSetPin(DIO_enumPortA,DIO_enumPin1,DIO_enumLogicHigh); /*turning second led on*/
		_delay_ms(1000); /*wait 1 sec*/
		DIO_enumSetPin(DIO_enumPortA,DIO_enumPin1,DIO_enumLogicLow); /*turning second led off*/
		
		
    }
}