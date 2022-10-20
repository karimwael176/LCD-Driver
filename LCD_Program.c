/* Include libs */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* DIO layer from MCAL included */

#include "DIO_Interface.h"
#include "DIO_Private.h"

#include <util/delay.h>
#include "LCD_Interface.h"

/* Implementation file */

void LCD_Init(void)
{
	/* init sequence for 4 bit mode LCD : Page 14 in data sheet*/
	
	/* delay for more than 30 ms*/
	_delay_ms(50);
	
	/* write function set - writing high nibble three commands */
	
	/* Function Set */
	
	LCD_voidSendCMD(INIT_VAL); 	//0b0010 0000
    LCD_voidSendCMD(INIT_VAL); 	//0b0010 0000
    LCD_voidSendCMD(FNSET); 	//0bNF00 0000
	
	/* Display ON/OFF Control */
	
	_delay_ms(1);
	
	LCD_voidSendCMD(ZERO);
	LCD_voidSendCMD(DIS_MODE);
	
	_delay_ms(1);
	
	/* Display Clear */
	
	LCD_voidSendCMD(ZERO);
	LCD_voidSendCMD(DIS_CLR);
	
	_delay_ms(5);
	
	/* Entry Mode Set */
	
	LCD_voidSendCMD(ZERO);
	LCD_voidSendCMD(ENTR_MODE);

}


void LCD_voidWriteData(u8 copy_u8Data)
{
	DIO_voidSetPinValue (PORT_CTRL ,RS ,HIGH );
	DIO_voidSetPinValue (PORT_CTRL ,RW ,LOW );
	
	/* LATCH ENABLE */
	
	DIO_voidSetPinValue (PORT_CTRL ,EN ,HIGH );
	_delay_ms(2);
	DIO_voidSetPinValue (PORT_CTRL ,EN ,LOW );
	_delay_ms(2);

	
	
	DIO_voidSetPortValue (PORT_DATA, copy_u8Data);

}


void LCD_voidSendCMD (u8 Copy_u8CMD)
{
	/* CHANGE RS TO LOW TO SEND COMMAND */
	
	DIO_voidSetPinValue (PORT_CTRL ,RS ,LOW );
	DIO_voidSetPinValue (PORT_CTRL ,RW ,LOW );	
	
		/* LATCH ENABLE */
		
	DIO_voidSetPinValue (PORT_CTRL ,EN ,HIGH );
	_delay_ms(2);
	DIO_voidSetPinValue (PORT_CTRL ,EN ,LOW );
	_delay_ms(2);
	
	
	DIO_voidSetPortValue (PORT_DATA, Copy_u8CMD);

}


/* imolement a function to write string */

void LCD_voidWriteString (u8* copy_pu8String)
{
	
	/* what could go wrong? */
	
	while (*copy_pu8String != '/0')
	{
		/* write char, inc to the next char */
		
		LCD_voidWriteData(*copy_pu8String);
		copy_pu8String++;
	}
	
}
