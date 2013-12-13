/*
 * sensor.c
 *
 *  Created on: Dec 9, 2013
 *      Author: C15Craig.ODaniel
 */

#include <msp430g2553.h>

void initSensors()
{
	  ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled
	  ADC10AE0 |= BIT4;                         // PA.1 ADC option select
	  ADC10AE0 |= BIT5|BIT3;                         // PA.1 ADC option select
	  ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;                // Select SMCLK
}

unsigned int left_Sensor(void)
{
	ADC10CTL0 &= ~ENC;
	ADC10CTL1 = INCH_4;                       // input A4
    ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
    __bis_SR_register(CPUOFF + GIE);        // LPM0, ADC10_ISR will force exit

    return ADC10MEM;
}

unsigned int right_Sensor(void)
{	ADC10CTL0 &= ~ENC;
	ADC10CTL1 = INCH_5;                       // input A5
    ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
    __bis_SR_register(CPUOFF + GIE);        // LPM0, ADC10_ISR will force exit
    return ADC10MEM;
}

unsigned int center_Sensor(void)
{	ADC10CTL0 &= ~ENC;
	ADC10CTL1 = INCH_3;                       // input A3
	ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
	__bis_SR_register(CPUOFF + GIE);        // LPM0, ADC10_ISR will force exit
	return ADC10MEM;

}


unsigned int checkLeft(void)
{

}


// ADC10 interrupt service routine
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void)
{
  __bic_SR_register_on_exit(CPUOFF);        // Clear CPUOFF bit from 0(SR)
}
