#include "stepper.h"

volatile cmd_t ButtonState = CMD_STOP;

/* 디바운스 설정 */
static const uint32_t DEBOUNCE_MS = 20;

/* 내부 상태 저장용 */
static GPIO_PinState prev_up = GPIO_PIN_SET;
static GPIO_PinState prev_down = GPIO_PIN_SET;
static GPIO_PinState prev_stop = GPIO_PIN_SET;

static uint32_t last_up_ms = 0;
static uint32_t last_down_ms = 0;
static uint32_t last_stop_ms = 0;

/* 헬퍼: 눌림(하강엣지) 판정 (풀업 입력 기준: 눌림=LOW) */
static inline uint8_t pressed_falling(GPIO_PinState now, GPIO_PinState *prev,
                                      uint32_t *tstamp)
{
    uint32_t now_ms = HAL_GetTick();
    uint8_t fired = 0;

    if ((*prev == GPIO_PIN_SET) && (now == GPIO_PIN_RESET)) { // High -> Low
        if ((now_ms - *tstamp) >= DEBOUNCE_MS) {
            fired = 1;
            *tstamp = now_ms;
        }
    }
    *prev = now;
    return fired;
}

void controller(void)
{
    /* 현재 레벨 읽기 (풀업: 안눌림=SET, 눌림=RESET) */
    GPIO_PinState up_now   = HAL_GPIO_ReadPin(BTN_UP_PORT,   BTN_UP_PIN);
    GPIO_PinState dn_now   = HAL_GPIO_ReadPin(BTN_DOWN_PORT, BTN_DOWN_PIN);
    GPIO_PinState stop_now = HAL_GPIO_ReadPin(BTN_STOP_PORT, BTN_STOP_PIN);

    /* 각각 하강엣지(눌리는 순간)만 트리거 */
    if (pressed_falling(up_now, &prev_up, &last_up_ms)) {
        ButtonState = CMD_UP;
        rotateDegrees(360, DIR_CW);
        return; // 한 번에 하나만 처리
    }

    if (pressed_falling(dn_now, &prev_down, &last_down_ms)) {
        ButtonState = CMD_DOWN;
        rotateDegrees(360, DIR_CCW);
        return;
    }

    if (pressed_falling(stop_now, &prev_stop, &last_stop_ms)) {
        ButtonState = CMD_STOP;
        stepper_stop();
        return;
    }

    /* 추가 정책이 필요하면 여기서 ButtonState 기반으로 보완 가능 */
}
