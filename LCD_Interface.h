/* Include libs */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* DIO layer from MCAL included */

#include "DIO_Interface.h"
#include "DIO_Private.h"

/* GUARD */

#ifndef _LCD_INTERFACE_H
#define _LCD_INTERFACE_H

/* details about the LCD to ease readability */

#define PORT_DATA PORTA
#define PORT_CTRL PORTB

#define RS PIN1
#define RW PIN2
#define EN PIN3

#define FNSET 		0x80
#define ZERO 		0
#define ONE  		0x01
#define INIT_VAL 	0x20
#define DIS_MODE 	0x0C
#define DIS_CLR 	0x10
#define ENTR_MODE 	0x60

/* function for the LCD driver

0- Init finction
1- function to write command
2- function to write data

*/

void LCD_Init(void);
void LCD_voidWriteData(u8 copy_u8Data);
void LCD_voidSendCMD (u8 Copy_u8CMD);
void LCD_voidWriteString (u8* copy_pu8String);




#endif