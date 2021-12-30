#ifndef config_h
#define config_h

#define MAX_CHAR 50
#define MAX_COMMANDS 10

//definimos cantidad de lineas de address y num maximo 2^20
#define ADDR_LINES 20      //definimos tamaño del bus
//uint32_t MAX_ADDR = pow(2, ADDR_LINES);   //calculamos el valor maximo del bus
#define MAX_ADDR (pow(2, ADDR_LINES)) //calculamos el valor maximo del bus

void printMenu();
void SubMenu();

void printDigits(int );
void digitalClockDisplay(); 
time_t getTeensy3Time();
unsigned long processSyncMessage();

#endif
