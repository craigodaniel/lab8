#include <msp430.h> 
#include "motor.h"
#include "sensor.h"

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	initPins();
	createPulses();
	initSensors();

	while(1){
		 if (center_Sensor() > 0x300){				//Check Center

				  turnRight();						//Something Center and Left? Yes. Turn Right
					__delay_cycles(100000);

			}

		 else if (left_Sensor() > 0x2CC){


				turnRight();						//Something Left? Yes. Turn Right
				__delay_cycles(100000);
		 	 	 moveForward();
		 	 	 __delay_cycles(10000);}


			else if (right_Sensor() > 0x2FF){		//Something Center or Left? No. Check Right
					turnLeft();						//Something Right? Yes. Turn Left
					__delay_cycles(10000);
			    }


			else {	moveForward();					//Something Center or Left or Right? No. Move Forward.
				__delay_cycles(10000);
					}



	}




	
	return 0;
}
