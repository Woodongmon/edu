#ifndef INC_PHOTO_H_
#define INC_PHOTO_H_

#include "main.h"
#include "stdbool.h"

typedef struct{
		GPIO_TypeDef *port;
		uint16_t pin;
}Photo;

bool Photo_Get(uint8_t);

#endif /* INC_PHOTO_H_ */
