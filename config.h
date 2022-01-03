#ifndef config_h
#define config_h

#define MAX_CHAR 50
#define MAX_COMMANDS 10

//definimos cantidad de lineas de address y num maximo 2^20
#define ADDR_LINES 20      //definimos tamaño del bus
//uint32_t MAX_ADDR = pow(2, ADDR_LINES);   //calculamos el valor maximo del bus
#define MAX_ADDR (pow(2, ADDR_LINES)) //calculamos el valor maximo del bus

typedef enum  {DP0, DP1, DP2, DP3, DP4, DP5, DP6, DP7, UNKNOWOP, READ = 9, WRITE = 10, OUTDIS = 11, STB12, STB13, STB14, STB15} OPERATIONS;
typedef enum  {M0, M1, M2, M3, M4, M5, M6, M7} SELECTION;
typedef enum  {DISABLE_MEM= 0, ENABLE_MEM = 1} ENABLEDIS;

//Menu
void printMenu();
void SubMenu();

//TimeLib
void printDigits(int );
void digitalClockDisplay(); 
time_t getTeensy3Time();
unsigned long processSyncMessage();
void SetTimeInit();

//librsc
String readCommands();
void limpiarComandos();

//libin
void printNumberOp(uint32_t );
void printAddr(uint32_t );
uint32_t readAddr(uint8_t , uint8_t );
int address_mode();
void data_mode();
void control_mode();
void enableDisable_mem();
void selection_mem();



// INPUTS
#define ADDR0     0
#define ADDR1     1
#define ADDR2     2
#define ADDR3     3
#define ADDR4     4
#define ADDR5     5
#define ADDR6     6
#define ADDR7     7
#define ADDR8     8
#define ADDR9     9
#define ADDR10    10
#define ADDR11    11
#define ADDR12    12
#define ADDR13    13
#define ADDR14    14
#define ADDR15    15
#define ADDR16    16
#define ADDR17    17
#define ADDR18    18
#define ADDR19    19

#define RPPin     20
#define OEPin     21
#define WEPin     22

#define DATA0     24
#define DATA1     25
#define DATA2     26
#define DATA3     27
#define DATA4     28
#define DATA5     29
#define DATA6     30
#define DATA7     31

#define A138Pin   36
#define B138Pin   37
#define C138Pin   38
#define G2APin    39
#define G2BPin    40
#define G1Pin     41

#endif
