#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include "serial.h"

char buffer[100];
interrupt 21 void serialISR();
interrupt 20 void seria0ISR();

void main(void) {
  /* put your own code here */
  
  SerialInitialise(BAUD_9600, &SCI0);
  SerialInitialise(BAUD_9600, &SCI1);

	EnableInterrupts;


  for(;;) { 
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}


interrupt 21 void serialISR() 
{
  SerialRead(&SCI1, &buffer);
}

interrupt 20 void seria0ISR() 
{
  SerialRead(&SCI0, &buffer);
}
