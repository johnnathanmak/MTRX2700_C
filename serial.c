#include <mc9s12dp256.h> 
#include "serial.h"



// Initialise Serial Ports
SerialPort SCI1 = {&SCI1BDH, &SCI1BDL, &SCI1CR1, &SCI1CR2, &SCI1DRL, &SCI1SR1};
SerialPort SCI0 = {&SCI0BDH, &SCI0BDL, &SCI0CR1, &SCI0CR2, &SCI0DRL, &SCI0SR1};




void SerialInitialise(int baudRate, SerialPort *serial_port) {
  
  // Baud rate calculation from datasheet
  switch(baudRate){
	case BAUD_9600:
      *(serial_port->BaudHigh)=0;
      *(serial_port->BaudLow)=156;
	  break;
	/* case BAUD_19200:
      *(serial_port->BaudHigh)=0;
      *(serial_port->BaudLow)=78;
	  break;
	case BAUD_38400:
      *(serial_port->BaudHigh)=0;
      *(serial_port->BaudLow)=39;
	  break;
	case BAUD_57600:
      *(serial_port->BaudHigh)=0;
      *(serial_port->BaudLow)=26;
	  break;
	case BAUD_115200:
      *(serial_port->BaudHigh)=0;
      *(serial_port->BaudLow)=13;
	  break;  */
  }
  
  *(serial_port->ControlRegister2) = SCI1CR2_RE_MASK | SCI1CR2_TE_MASK | 0b0010000;
  *(serial_port->ControlRegister1) = 0x00;
}




void SerialRead (SerialPort *serial_port, char* buffer) {
  int j=0;
  
  // Check if data is received. The RDRF flag
  if (*(serial_port->StatusRegister) && 0x20) 
  {
    // End of sentence? Look for a carriage return
    if (*(serial_port->DataRegister) == 0x20) // #define carriage return above later
    {
      return;
    } 
    
    // Store each character of sentence in buffer
    else
    {
      buffer[j] = *(serial_port->DataRegister);
      j = j + 1;
    }
  }
}