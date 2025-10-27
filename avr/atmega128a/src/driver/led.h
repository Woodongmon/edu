#include "../common/def.h"

#define LED_DDR     DDRD
#define LED_PORT    PORTD

typedef struct
{
    volatile uint8_t    *port;      //volatile : 컴파일시, 최적화하지 않는것.
    uint8_t             pinNumber;
}LED;

void ledInit(LED *led);
void ledOn(LED *led);
void ledOff(LED *led);