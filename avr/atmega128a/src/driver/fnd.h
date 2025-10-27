#include "../src/common/def.h"


#define FND_DATA_DDR    DDRB
#define FND_DATA_PORT   PORTB
#define FND_SELECT_DDR  DDRC
#define FND_SELECT_PORT PORTC

void FND_Display(uint16_t data);        //8bit 를 넘어가기때문에 16bit 사용함