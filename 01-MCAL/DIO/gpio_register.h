 /******************************************************************************
 *
 * Module: DIO driver for AVR atmega 32
 *
 * File Name: gpio_register.h
 *
 * Description: dio registers mapping for atmega 32
 *
 * Author: karim salah
 *
 *****************************************************************************/
 #ifndef GPIO_REGISTER_H_
 #define GPIO_REGISTER_H_


/**DIO Registers PORT A**/
#define DDRA *(volatile unsigned char*) 0x3A
#define PORTA *(volatile unsigned char*) 0x3B
#define PINA *(volatile unsigned char*) 0x39
/**DIO Registers PORT B**/
#define DDRB *(volatile unsigned char*) 0x37
#define PORTB *(volatile unsigned char*) 0x38
#define PINB *(volatile unsigned char*) 0x36
/**DIO Registers PORT C**/
#define DDRC *(volatile unsigned char*) 0x34
#define PORTC *(volatile unsigned char*) 0x35
#define PINC *(volatile unsigned char*) 0x33
/**DIO Registers PORT D**/
#define DDRD *(volatile unsigned char*) 0x31
#define PORTD *(volatile unsigned char*) 0x32
#define PIND *(volatile unsigned char*) 0x30