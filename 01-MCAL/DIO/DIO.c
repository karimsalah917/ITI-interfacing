/******************************************************************************
*
* Module: DIO driver for AVR atmega 32
*
* File Name: gpio.c
*
* Description: source file of the driver
*
* Author: karim salah
*
*****************************************************************************/

/**includes**/
#include "dio.h"
#include "gpio_register.h"
#include "Bit_Math.h"
#include "std_types.h"


/**
 *@brief  : Function to Configure the Pins to be INPUT pin or OUTPUT pin.
 *@param  : Port Number,Pin Number,Configuration type(Input/Output).
 *@return : Error State
 */
DIO_enumError_t DIO_enumSetPinConfig(DIO_enumPorts_t Copy_enumPortNum, DIO_enumPins_t Copy_enumPinNum, DIO_enumConfig_t Copy_enumConfig)
{
	/** VALIDATION **/
	    /*against wrong port entering*/
	DIO_enumError_t ret_enumErrorStatus = DIO_enumOk;
	if((Copy_enumPortNum>DIO_enumPortD)||(Copy_enumPortNum<DIO_enumPortA))
	{ ret_enumErrorStatus=DIO_enumWrongPort; }
	else if((Copy_enumPinNum>DIO_enumPin7)||(Copy_enumPinNum<DIO_enumPin0))
	{ ret_enumErrorStatus= DIO_enumWrongPin; }
	else if((Copy_enumConfig<DIO_enumOutput)||(Copy_enumConfig>DIO_enumInputExternalPD))
	{ ret_enumErrorStatus = DIO_enumWrongConfig; }
	else
	{
		ret_enumErrorStatus = DIO_enumOk;

		/** IMPLEMENTATION **/
		switch (Copy_enumPortNum)
		{
		case DIO_enumPortA:
			switch (Copy_enumConfig)
			{
			case DIO_enumOutput:SET_BIT(DDRA,Copy_enumPinNum); break;
			case DIO_enumInputInternalPU:CLR_BIT(DDRA, Copy_enumPinNum); 
				SET_BIT(PORTA,Copy_enumPinNum); break;
			case DIO_enumInputExternalPD: CLR_BIT(DDRA, Copy_enumPinNum); break;
			default:
				break;
			}
			break;

		case DIO_enumPortB:
			switch (Copy_enumConfig)
			{
			case DIO_enumOutput:SET_BIT(DDRB, Copy_enumPinNum); break;
			case DIO_enumInputInternalPU:CLR_BIT(DDRB, Copy_enumPinNum);
				SET_BIT(PORTB, Copy_enumPinNum); break;
			case DIO_enumInputExternalPD: CLR_BIT(DDRB, Copy_enumPinNum); break;
			default:
				break;
			}
			break;

		case DIO_enumPortC:
			switch (Copy_enumConfig)
			{
			case DIO_enumOutput:SET_BIT(DDRC, Copy_enumPinNum); break;
			case DIO_enumInputInternalPU:CLR_BIT(DDRC, Copy_enumPinNum);
				SET_BIT(PORTC, Copy_enumPinNum); break;
			case DIO_enumInputExternalPD: CLR_BIT(DDRC, Copy_enumPinNum); break;
			default:
				break;
			}
			break;

		case DIO_enumPortD:
			switch (Copy_enumConfig)
			{
			case DIO_enumOutput:SET_BIT(DDRD, Copy_enumPinNum); break;
			case DIO_enumInputInternalPU:CLR_BIT(DDRD, Copy_enumPinNum);
				SET_BIT(PORTD, Copy_enumPinNum); break;
			case DIO_enumInputExternalPD: CLR_BIT(DDRD, Copy_enumPinNum); break;
			default:
				break;
			}
			break;

		default:
			break;
		}
	}
	return ret_enumErrorStatus;
}

/**
 *@brief  : Function to Configure the whole Port(8 pins) at one time to be INPUT or OUTPUT port.
 *@param  : Port Number,Configuration type(Input/Output).
 *@return : Error State
 */
DIO_enumError_t DIO_enumSetPortConfig(DIO_enumPorts_t Copy_enumPortNum, DIO_enumConfig_t Copy_enumConfig)
{
	/** VALIDATION **/
	/*against wrong port entering*/
	DIO_enumError_t ret_enumErrorStatus = DIO_enumOk;
	if ((Copy_enumPortNum > DIO_enumPortD) || (Copy_enumPortNum < DIO_enumPortA))
	{
		ret_enumErrorStatus = DIO_enumWrongPort;
	}
	else if ((Copy_enumConfig < DIO_enumOutput) || (Copy_enumConfig > DIO_enumInputExternalPD))
	{
		ret_enumErrorStatus = DIO_enumWrongConfig;
	}
	else {
		switch (Copy_enumPortNum)
		{
		case DIO_enumPortA:
			switch (Copy_enumConfig)
			{
			case DIO_enumOutput: SET_PORT(DDRA);	break;
			case DIO_enumInputInternalPU: CLR_PORT(DDRA);
				SET_PORT(PORTA);	break;
			case DIO_enumInputExternalPD: CLR_PORT(DDRA);	break;
			default:
				break;
			}
				break;
		case DIO_enumPortB:
			switch (Copy_enumConfig)
			{
			case DIO_enumOutput: SET_PORT(DDRB);	break;
			case DIO_enumInputInternalPU: CLR_PORT(DDRB);
				SET_PORT(PORTB);	break;
			case DIO_enumInputExternalPD: CLR_PORT(DDRB);	break;
			default:
				break;
			}
			break;
		case DIO_enumPortC:
			switch (Copy_enumConfig)
			{
			case DIO_enumOutput: SET_PORT(DDRC);	break;
			case DIO_enumInputInternalPU: CLR_PORT(DDRC);
				SET_PORT(PORTC);	break;
			case DIO_enumInputExternalPD: CLR_PORT(DDRC);	break;
			default:
				break;
			}
			break;
		case DIO_enumPortD:
			switch (Copy_enumConfig)
			{
			case DIO_enumOutput: SET_PORT(DDRD);	break;
			case DIO_enumInputInternalPU: CLR_PORT(DDRD);
				SET_PORT(PORTD);	break;
			case DIO_enumInputExternalPD: CLR_PORT(DDRD);	break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
}

/**
 *@brief  : Function to Set the Pins to be Logic HIGH  or Logic LOW.
 *@param  : Port Number,Pin Number,Logic State(HIGH/LOW).
 *@return : Error State
 */
DIO_enumError_t DIO_enumSetPin(DIO_enumPorts_t Copy_enumPortNum, DIO_enumPins_t Copy_enumPinNum, DIO_enumLogicState_t Copy_enumLogicState){}

/**
 *@brief : Function to Set the whole Port(8 pins) at one time to be Logic HIGH  or Logic LOW.
 *@param : Port Number,Logic State(HIGH/LOW).
 *@return: Error State.
 */
DIO_enumError_t DIO_enumSetPort(DIO_enumPorts_t Copy_enumPortNum, DIO_enumLogicState_t Copy_enumLogicState){}

/**
 *@brief  : Function to Read the Logic State of the Pin (Is it HIGH or LOW).
 *@param  : Port Number,Pin Number, Pointer points to unsigned char passed by address (to return the value of pin state).
 *@return : Error State
 */
DIO_enumError_t DIO_enumReadState(DIO_enumPorts_t Copy_enumPortNum, DIO_enumPins_t Copy_enumPinNum, DIO_enumLogicState_t* Add_Pu8PinValue){}

