#include "../common/def.h"

#define LED_DDR         DDRD
#define LED_PORT        PORTD
#define BUTTON_DDR      DDRG
#define BUTTON_PIN      PING
#define BUTTON_ON       2
#define BUTTON_OFF      3
#define BUTTON_TOGGLE   4

enum {PUSHED, RELEASED}; // PUSHED=0, RELEASED=1 할당
enum {NO_ACT, ACT_PUSH, ACT_RELEASE}; // 0~2할당

typedef struct 
{
    volatile uint8_t *ddr;
    volatile uint8_t *pin;
uint8_t btnPin;
uint8_t prevState; //이전 상태

} BUTTON;

void buttonInit (BUTTON *button, 
                volatile uint8_t *ddr, 
                volatile uint8_t *pin,
                         uint8_t pinNum);
uint8_t buttonGetState(BUTTON *button);