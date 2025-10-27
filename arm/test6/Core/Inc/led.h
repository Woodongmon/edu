typedef enum
{
  LED_OFF,
  LED_ON
}LED_STATE;

typedef struct
{
  GPIO_TypeDef  *port;     //resister 이므로 포인터로 가져와야함
  uint16_t      pinNumber;
  uint32_t      interval; //delay time
  LED_STATE     state;
  uint32_t      lastTick; //time
}LED_CONTROL;
