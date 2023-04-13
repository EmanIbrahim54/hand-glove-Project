
#ifndef UART_CFG_H_
#define UART_CFG_H_

#include "Bit_Math.h"
#include "std.h"

//DIO
#define PORTD    (*(volatile char*)(0x32))
#define DDRD     (*(volatile char*)(0x31))
#define PIND     (*(volatile char*)(0x30))
//UART
#define UCSRA  (*(volatile char*)(0x2B))
#define UCSRB  (*(volatile char*)(0x2A))
#define UCSRC  (*(volatile char*)(0x40))
#define UBRRH  (*(volatile char*)(0x40))
#define UBRRL  (*(volatile char*)(0x29))
#define UDR    (*(volatile char*)(0x2C))


/*Parity Mode Selection*/
#define PARITY_MODE         EVEN_PARITY

/*Stop Bit Selection*/
#define STOP_BIT            _1_BIT

/*Data Size Selection*/
#define DATA_SIZE           _8_BIT

/*Baud Rate Selection*/
#define BAUD_RATE           B_38400



#endif /* UART_CFG_H_ */