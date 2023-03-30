#include "3140_concur.h"
#include "utils.h"
#include "lock.h"


lock_t l;

void p1(void){
	int i= 0;
	while(i < 3){
		/*NCS*/
		delay();
		i++;
		/*CS*/
		l_lock(&l);
		LEDRed_Toggle();
		delay();
		LEDRed_Toggle();
		delay();
		l_unlock(&l);
	}
}

void p2(void){
	int i= 0;
	while(i < 3){
		delay();
		i++;
        l_lock(&l);
		LEDGreen_Toggle();
		delay();
		LEDGreen_Toggle();
		delay();
	}
}

/**
 * Tests a process that never unlocks.
 * p2 never unlocks. 
 * Expected behavior is that the red LED will flash
 * two times, and then the green LED will continue
 * flashing without allowing the red LED to flash anymore.
*/
int main(void){
	LED_Initialize();           /* Initialize the LEDs           */	

	l_init (&l);
	
    // tests a process that never locks

	if (process_create (p1,20) < 0) {
	 	return -1;
	}
	if (process_create (p2,20) < 0) {
	 	return -1;
	}
	
	process_start();
	LEDGreen_On();

	while(1);
	return 0;	
}
