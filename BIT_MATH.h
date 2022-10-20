/********GUARD********/

#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

/*BITEWISE OPERATION*/

#define SET_BIT(u8 PORT_REG, u8 PIN_NO) PORT_REG |= (1<<PIN_NO)
#define CLR_BIT(u8 PORT_REG, u8 PIN_NO) PORT_REG &= ~(1<<PIN_NO)
#define TGL_BIT(u8 PORT_REG, u8 PIN_NO) PORT_REG ^= (1<<PIN_NO)


#define GET_BIT(u8 PORT_REG, u8 PIN_NO) PORT_REG=(PORT_REG>>PIN_NO) & 1


#endif