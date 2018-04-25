/**
* author: sergiu
* date: 11-Mar-2018 12:16:45 AM
* blinky: toggles PORTB pins on and off every 150ms
*/
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "inc/ds18b20.h"

int main()
{
	start();
	int temp;
	while(1)
	{
		ds18b20convert( &PORTB, &DDRB, &PINB, ( 1 << 2 ), NULL );

		//Delay (sensor needs time to perform conversion)
		_delay_ms(1000);

		//Read temperature (without ROM matching)
		ds18b20read( &PORTB, &DDRB, &PINB, ( 1 << 2 ), NULL, &temp );
		clearScreen();
		Send_An_Integer(temp/16);
		Send_A_String(",");
		Send_An_Integer((temp*10/16)%10);
	}
	return 0;
}

