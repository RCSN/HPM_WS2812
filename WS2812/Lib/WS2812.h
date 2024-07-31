#ifndef WS2812_H
#define WS2812_H

#include "WS2812_Conf.h"

#define CONCATENATE_DETAIL(x, y) x##y
#define CONCATENATE(x, y)        CONCATENATE_DETAIL(x, y)
#define STRINGIFY_DETAIL(x)      #x
#define STRINGIFY(x)             STRINGIFY_DETAIL(x)

#define _WS2812_DIN_PIN CONCATENATE(IOC_PAD_, WS2812_DIN)
#define _WS2812_DIN_FUNC CONCATENATE(CONCATENATE(CONCATENATE(CONCATENATE(CONCATENATE(IOC_, WS2812_DIN), _FUNC_CTL_GPTMR),WS2812_GPTMR),_COMP_),WS2812_GPTMR_CHANNLE)
#define _WS2812_GPTMR_NAME CONCATENATE(clock_gptmr, WS2812_GPTMR)
#define _WS2812_GPTMR_PTR CONCATENATE(HPM_GPTMR, WS2812_GPTMR)
#define _WS2812_DMAMUX_SRC CONCATENATE(CONCATENATE(CONCATENATE(HPM_DMA_SRC_GPTMR, WS2812_GPTMR), _), WS2812_GPTMR_CHANNLE)

#define _WS2812_TMR_IRQ CONCATENATE(IRQn_GPTMR, WS2812_GPTMR)

void WS2812_Init(void);
void WS2812_Update(void);

#if WS2812_LED_CONNECT == WS2812_CONNECT_LINE
void WS2812_SetPixel(uint32_t index, uint8_t r, uint8_t g, uint8_t b);
#endif

#endif //WS2812_H
