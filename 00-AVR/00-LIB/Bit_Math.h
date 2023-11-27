 /******************************************************************************
 *
 * Module: Common - Platform Types Abstraction
 *
 * File Name: Bit_Maths.h
 *
 * Description: macro function to used it with any 8-BIT register
 *
 * Author: Karim salah
 *
 *******************************************************************************/

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

// Set bit BIT in REG
#define SET_BIT(REG,BIT)    (REG|=(1<<BIT))
// Clear bit BIT in REG       
#define CLR_BIT(REG,BIT)    (REG&=(~(1<<BIT)))
// Toggle bit BIT in REG           
#define TGL_BIT(REG,BIT)    (REG^=(1<<BIT))
// Get bit BIT in REG           
#define GET_BIT(REG,BIT)    ((REG>>BIT)&(0x01))
          
// Set high nibble in REG
#define SET_HIGH_NIB(REG)   (REG|=0XF0)
// Clear high nibble in REG          
#define CLR_HIGH_NIB(REG)  (REG&=0X0F)
// Get high nibble in REG          
#define GET_HIGH_NIB(REG)   ((REG>>NIB*1)&(0X0F))
// Toggle high nibble in REG       
#define TGL_HIGH_NIB(REG)   (REG^=0XF0)
// Set low nibble in REG         
#define SET_LOW_NIB(REG)    (REG|=0X0F)
// Clear low nibble in REG           
#define CLR_LOW_NIB(REG)    (REG&=0XF0)
// Get low nibble in REG            
#define GET_LOW_NIB(REG)    ((REG>>NIB*1)&(0XF0))
// Toggle low nibble in REG            
#define TGL_LOW_NIB(REG)      (REG^=0X0F)              

// Assign VALUE to REG
#define ASSIGN_REG(REG,VALUE)     (REG=VALUE) 
#define SET_PORT(port) (port=0xff)
#define CLR_PORT(port) (port=0x00)
#endif    