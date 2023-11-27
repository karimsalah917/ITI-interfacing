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
	else 
	{
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
	return ret_enumErrorStatus;
}

/**
 *@brief  : Function to Set the Pins to be Logic HIGH  or Logic LOW.
 *@param  : Port Number,Pin Number,Logic State(HIGH/LOW).
 *@return : Error State
 */
DIO_enumError_t DIO_enumSetPin(DIO_enumPorts_t Copy_enumPortNum, DIO_enumPins_t Copy_enumPinNum, DIO_enumLogicState_t Copy_enumLogicState)
{
		/** VALIDATION **/
	    /*against wrong port entering*/
	DIO_enumError_t ret_enumErrorStatus = DIO_enumOk;
	if((Copy_enumPortNum>DIO_enumPortD)||(Copy_enumPortNum<DIO_enumPortA))
	{ ret_enumErrorStatus=DIO_enumWrongPort; }
	else if((Copy_enumPinNum>DIO_enumPin7)||(Copy_enumPinNum<DIO_enumPin0))
	{ ret_enumErrorStatus= DIO_enumWrongPin; }
	else if((Copy_enumLogicState<DIO_enumLogicLow)||(Copy_enumLogicState>DIO_enumLogicHigh))
	{ ret_enumErrorStatus = DIO_enumWrongConfig; }
	else
	{
		switch (Copy_enumPortNum)
		{
		case DIO_enumPortA:
			switch (Copy_enumLogicState)
			{
			case DIO_enumLogicLow: CLR_BIT(PINA, Copy_enumPinNum);	break;
			case DIO_enumLogicHigh:SET_BIT(PINA, Copy_enumPinNum);	break;
			default:
				break;
			}
			break;
		case DIO_enumPortB:
			switch (Copy_enumLogicState)
			{
			case DIO_enumLogicLow: CLR_BIT(PINB, Copy_enumPinNum);	break;
			case DIO_enumLogicHigh:SET_BIT(PINB, Copy_enumPinNum);	break;
			default:
				break;
			}
			break;
		case DIO_enumPortC:
			switch (Copy_enumLogicState)
			{
			case DIO_enumLogicLow: CLR_BIT(PINC, Copy_enumPinNum);	break;
			case DIO_enumLogicHigh:SET_BIT(PINC, Copy_enumPinNum);	break;
			default:
				break;
			}
			break;
		case DIO_enumPortD:
			switch (Copy_enumLogicState)
			{
			case DIO_enumLogicLow: CLR_BIT(PIND, Copy_enumPinNum);	break;
			case DIO_enumLogicHigh:SET_BIT(PIND, Copy_enumPinNum);	break;
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
 *@brief : Function to Set the whole Port(8 pins) at one time to be Logic HIGH  or Logic LOW.
 *@param : Port Number,Logic State(HIGH/LOW).
 *@return: Error State.
 */
DIO_enumError_t DIO_enumSetPort(DIO_enumPorts_t Copy_enumPortNum, DIO_enumLogicState_t Copy_enumLogicState)
{
	/** VALIDATION **/
/*against wrong port entering*/
	DIO_enumError_t ret_enumErrorStatus = DIO_enumOk;
	if ((Copy_enumPortNum > DIO_enumPortD) || (Copy_enumPortNum < DIO_enumPortA))
	{
		ret_enumErrorStatus = DIO_enumWrongPort;
	}
/*wrong logic state entering*/
	else if ((Copy_enumLogicState < DIO_enumLogicLow) || (Copy_enumLogicState > DIO_enumLogicHigh))
	{
		ret_enumErrorStatus = DIO_enumWrongConfig;
	}
/*normal module function*/
	else
	{
		switch (Copy_enumPortNum)
		{
		case DIO_enumPortA:
			switch (Copy_enumLogicState)
			{
			case DIO_enumLogicLow: CLR_PORT(PORTA);	break;
			case DIO_enumLogicHigh: SET_PORT(PORTA);	break;
			default:
				break;
			}
			break;
		case DIO_enumPortB:
			switch (Copy_enumLogicState)
			{
			case DIO_enumLogicLow: CLR_PORT(PORTB);	break;
			case DIO_enumLogicHigh: SET_PORT(PORTB);	break;
			default:
				break;
			}
			break;
		case DIO_enumPortC:
			switch (Copy_enumLogicState)
			{
			case DIO_enumLogicLow: CLR_PORT(PORTC);	break;
			case DIO_enumLogicHigh: SET_PORT(PORTC);	break;
			default:
				break;
			}
			break;
		case DIO_enumPortD:
			switch (Copy_enumLogicState)
			{
			case DIO_enumLogicLow: CLR_PORT(PORTD);	break;
			case DIO_enumLogicHigh: SET_PORT(PORTD);	break;
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
 *@brief  : Function to Read the Logic State of the Pin (Is it HIGH or LOW).
 *@param  : Port Number,Pin Number, Pointer points to unsigned char passed by address (to return the value of pin state).
 *@return : Error State
 */
DIO_enumError_t DIO_enumReadState(DIO_enumPorts_t Copy_enumPortNum, DIO_enumPins_t Copy_enumPinNum, uint8* Ptr_uint8PinValue)
{
	DIO_enumError_t ret_enumErrorStatus = DIO_enumOk;
	if ((Copy_enumPortNum > DIO_enumPortD) || (Copy_enumPortNum < DIO_enumPortA))
	{
		ret_enumErrorStatus = DIO_enumWrongPort;
	}
	else if ((Copy_enumPinNum > DIO_enumPin7) || (Copy_enumPinNum < DIO_enumPin0))
	{
		ret_enumErrorStatus = DIO_enumWrongPin;
	}
	else
	{
		switch (Copy_enumPortNum)
		{
		case DIO_enumPortA:*Ptr_uint8PinValue = GET_BIT(PINA, Copy_enumPinNum); break;
		case DIO_enumPortB:*Ptr_uint8PinValue = GET_BIT(PINB, Copy_enumPinNum); break;
		case DIO_enumPortC:*Ptr_uint8PinValue = GET_BIT(PINC, Copy_enumPinNum); break;
		case DIO_enumPortD:*Ptr_uint8PinValue = GET_BIT(PIND, Copy_enumPinNum); break;
		default:
			break;
		}
	}
	return ret_enumErrorStatus;
}
/**
 *@brief  : Function to write a uint8 value(0->255) to a port.
 *@param  : Port Number,uint8 value.
 *@return : Error State
 */
DIO_enumError_t DIO_enumWritePortValue(DIO_enumPorts_t Copy_enumPortNum,uint8 copy_uint8Value)
{
	DIO_enumError_t ret_enumErrorStatus = DIO_enumOk;
	if ((Copy_enumPortNum > DIO_enumPortD) || (Copy_enumPortNum < DIO_enumPortA))
	{
		ret_enumErrorStatus = DIO_enumWrongPort;
	}
	else if ((copy_uint8Value>255) || (copy_uint8Value < 0))
	{
		ret_enumErrorStatus = DIO_enumWrongConfig;
	}
	else
	{
		switch (Copy_enumPortNum)
		{
		case DIO_enumPortA: ASSIGN_REG(PORTA,copy_uint8Value); break;
		case DIO_enumPortB: ASSIGN_REG(PORTB, copy_uint8Value); break;
		case DIO_enumPortC: ASSIGN_REG(PORTC, copy_uint8Value); break;
		case DIO_enumPortD: ASSIGN_REG(PORTD, copy_uint8Value); break;
		default:
			break;
		}
	}
	return ret_enumErrorStatus;
}

