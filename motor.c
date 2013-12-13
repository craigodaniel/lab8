/*
 * motor.c
 *
 *  Created on: Nov 20, 2013
 *      Author: C15Craig.ODaniel
 */

#include <msp430.h>
#include "motor.h"

void createPulses()
{
	TA1CTL &= ~(MC1|MC0);            // stop timer A1
	TA0CTL &= ~(MC1|MC0);

	TA1CCR1 = 30;
	TA0CCR1 = 50;
	TA1CCR0 = 100;
	TA0CCR0 = 100;

	TA1CTL |= TACLR;                // clear timer A1
	TA0CTL |= TACLR;

	TA1CTL |= TASSEL1;           // configure for SMCLK
	TA0CTL |= TASSEL1;

	TA1CTL |= MC0;                // count up
	TA0CTL |= MC0;
}

void initPins(){
	P1DIR |= BIT1;             	  // TA0CCR0 on P1.1
	P1SEL |= BIT1;                // TA0CCR0 on P1.1

	P1DIR |= BIT2;          	  // TA0CCR1 on P1.2
	P1SEL |= BIT2;                // TA0CCR1 on P1.2

	P2DIR |= BIT0;                // TA1CCR0 on P2.0
	P2SEL |= BIT0;                // TA1CCR0 on P2.0

	P2DIR |= BIT1;                // TA1CCR1 on P2.1
	P2SEL |= BIT1;                // TA1CCR1 on P2.1
}

void moveRightWheelBackward(){
	TA0CCTL0 &= ~(OUTMOD2|OUTMOD1|OUTMOD0);
	TA0CCTL0 |= OUTMOD_4;
	TA0CCTL1 &= ~(OUTMOD2|OUTMOD1|OUTMOD0);
	TA0CCTL1 |= OUTMOD_5;
}

void moveLeftWheelBackward(){
	TA1CCTL0 &= ~(OUTMOD2|OUTMOD1|OUTMOD0);
	TA1CCTL0 |= OUTMOD_4;
	TA1CCTL1 &= ~(OUTMOD2|OUTMOD1|OUTMOD0);
	TA1CCTL1 |= OUTMOD_5;
}

void moveLeftWheelForward(){
	TA1CCTL1 &= ~(OUTMOD2|OUTMOD1|OUTMOD0);
	TA1CCTL1 |= OUTMOD_7;
	TA1CCTL0 &= ~(OUTMOD2|OUTMOD1|OUTMOD0);
	TA1CCTL0 |= OUTMOD_5;
}

void moveRightWheelForward(){
	TA0CCTL1 &= ~(OUTMOD2|OUTMOD1|OUTMOD0);
	TA0CCTL1 |= OUTMOD_7;
	TA0CCTL0 &= ~(OUTMOD2|OUTMOD1|OUTMOD0);
	TA0CCTL0 |= OUTMOD_5;
}

void moveForward(){
	moveRightWheelForward();
	moveLeftWheelForward();
}

void moveBackward(){
	moveRightWheelBackward();
	moveLeftWheelBackward();
}

void turnLeft(){
	moveRightWheelForward();
	moveLeftWheelBackward();
}

void turnRight(){
	moveRightWheelBackward();
	moveLeftWheelForward();
}

void stopRight(){
	TA0CCTL1 &= ~(OUTMOD2|OUTMOD1|OUTMOD0);
	TA0CCTL1 |= OUTMOD_5;
	TA0CCTL0 &= ~(OUTMOD2|OUTMOD1|OUTMOD0);
	TA0CCTL0 |= OUTMOD_5;
}

void stopLeft(){
	TA1CCTL1 &= ~(OUTMOD2|OUTMOD1|OUTMOD0);
	TA1CCTL1 |= OUTMOD_5;
	TA1CCTL0 &= ~(OUTMOD2|OUTMOD1|OUTMOD0);
	TA1CCTL0 |= OUTMOD_5;
}

void stopMoving(){
	stopRight();
	stopLeft();
}




