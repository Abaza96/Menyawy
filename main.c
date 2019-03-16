/*
 * main.c
 *
 *  Created on: Mar 17, 2019
 *      Author: Mahmoud Abaza
 */
#include "std_Types.h"
#include "Registers.h"

#include "DIO.h"
#include <util/delay.h>

#include "LCD.h"
#include "Seg.h"

int main(void)
{
	u8 SegmentA = {uSegmentsInv} , SegmentB = {uSegmentsInv} , i , j;

	DIO_vidSetPortDirection(A , FullyCharged);
	DIO_vidSetPortDirection(B , FullyCharged);
	DIO_vidSetPortDirection(C , SemiChargedRight);

	LCD_vidInitialization();
	LCD_vidWriteSentence("Dr Kamal");
	LCD_vidsetPosition(LCD_Row2,LCD_Column1);
	LCD_vidWriteSentence("Eng Mohamed");

	DIO_vidSetPortValue(A , Six);

	DIO_vidSetPortValue(B , Zero);

	while (true)
	{
		//Red LED Count (Red LED is Connected to The 8th PIN in PORTC)
		for(i = false ; i < Segment_FullCount ; i++)
		{
			PORTA = SegmentA[i];

			DIO_vidWritePinValue(C , PIN7 , HIGH);

			for(j = false ; i < Segment_FullCount ; i++)
			{
				PORTB = SegmentB[j];
				_delay_ms(mSec);
			}
		}


		//Yellow LED Count (Yellow LED is Connected to The 7th PIN in PORTC)
		DIO_vidSetPortValue(A , Zero);

		for(i = false ; i < Segment_FullCount ; i++)
		{
			PORTB = SegmentB[i];

			DIO_vidWritePinValue(C , PIN6 , HIGH);

			_delay_ms(mSec);
		}

		//Green LED Count (Green LED is Connected to The 6th PIN in PORTC)
		for(i = false ; i < Segment_FullCount ; i++)
		{
			PORTA = SegmentA[i];

			DIO_vidWritePinValue(C , PIN5 , HIGH);

			for(j = false ; i < Segment_FullCount ; i++)
			{
				PORTB = SegmentB[j];
				_delay_ms(mSec);
			}
		}
	}
	return True;
}
