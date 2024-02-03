//
// Created by LMF on 2024/1/28.
//

#ifndef HAL_STM32F103ZET6_ESP8266_H
#define HAL_STM32F103ZET6_ESP8266_H
#include "main.h"
#define ESPBUFF_MAX_SIZE 1024
void ESP8266_Init(void );
void ESP8266_Clear(void );
void ESP8266_SendString(uint8_t *str,uint8_t len);
uint8_t ESP8266_SendCmd(uint8_t *cmd,uint8_t *res);
#endif //HAL_STM32F103ZET6_ESP8266_H
