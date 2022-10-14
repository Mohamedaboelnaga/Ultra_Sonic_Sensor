 /******************************************************************************
 *
 * Module:  ultrasonic + Lcd application
 *
 * File Name: ultrasonic_main.c
 *
 * Description: Source file for the ultrasonic + Lcd application
 *
 * Author: Mohamed Ahmed Hassan Aboelnaga
 *
 *******************************************************************************/

#include"ultrasonic.h"
#include"lcd.h"
#include <avr/io.h>
#include<util/delay.h>    /* to use delay function */

int main(void)
{
	LCD_init();
	Ultrasonic_init();/*initialize the ultrasonic */
	SREG|=(1<<7); // enable the I-Bit
	uint16 distance; // to read the value of the distance that the sensor read
	LCD_displayString("Distance=   cm");
	while(1)
	{
		distance=Ultrasonic_readDistance();//read the value from the sensor
		LCD_moveCursor(0,10);
		LCD_intgerToString(distance);//display the distance in centimeters on the lcd
		if(distance<100)
		{
			LCD_displayCharacter(' ');//so when you count down you don not overwrite between digits
		}
		_delay_ms(100);//to produce echo for every trigger
	}
}
