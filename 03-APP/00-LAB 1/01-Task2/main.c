/******************************************************************************
* LAB: ONE
* Project Name: task2
* Project info: 8 LEDS and one PUSH button
* Modules used: DIO
* File Name: task2.c
* Author: karim salah
*
*****************************************************************************/

#include "../../../01-MCAL/DIO/DIO.h"
#define F_CPU 8000000UL
int main(void)
{    /*Configuration and intialisation*/
	DIO_enumSetPortConfig(DIO_enumPortA,DIO_enumOutput); /*setting port A as output*/
	DIO_enumWritePortValue(DIO_enumPortA,0x00); /*write 0 volt on the whole port as intial value*/
	DIO_enumSetPinConfig(DIO_enumPortB,DIO_enumPin0,DIO_enumInputInternalPU); /*setting pin 0 at port b as a input*/
	
	uint8 DIO_pushButtonStatus=1,DIO_counter=0;
	
	
    while(1)
    {
        DIO_enumReadState(DIO_enumPortB, DIO_enumPin0, &DIO_pushButtonStatus);
        if (DIO_pushButtonStatus == 0)
        {

	        //DIO_enumReadState(DIO_enumPortB, DIO_enumPin0, &DIO_pushButtonStatus);

	        if (DIO_pushButtonStatus == 0)
	        {
		        // Increment the counter
		        ++DIO_counter;

		        // Display the counter on LEDs
		        DIO_enumWritePortValue(DIO_enumPortA, DIO_counter);

		        // Wait for button release to avoid multiple increments
		        while (DIO_pushButtonStatus == 0)
		        {
			        DIO_enumReadState(DIO_enumPortB, DIO_enumPin0, &DIO_pushButtonStatus);
		        }
	        }
        }
	}
}