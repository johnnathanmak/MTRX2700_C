#ifndef SCI1_HEADER
#define SCI1_HEADER

typedef struct SerialPort {
  byte *BaudHigh;
  byte *BaudLow;
  byte *ControlRegister1;
  byte *ControlRegister2;
  byte *DataRegister;
  byte *StatusRegister;
} SerialPort;

extern SerialPort SCI0, SCI1;

enum {
  BAUD_9600,
  BAUD_19200,
  BAUD_38400,
  BAUD_57600,
  BAUD_115200
};


void SerialInitialise(int baudRate, SerialPort *serial_port);

void SerialRead (SerialPort *serial_port, char* buffer);

#endif