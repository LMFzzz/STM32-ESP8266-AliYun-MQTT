//
// Created by LMF on 2024/1/28.
//
#include "esp8266.h"
#include "string.h"
#include "main.h"
#include "usart.h"
#include "stdio.h"
//#define WIFI_NAME "Xiaomi_3251"
//#define WIFI_PASS "220020802"
//#define WIFI_NAME "OnePlus Ace 2V"
//#define WIFI_PASS "q5fhyem5"
#define WIFI_NAME "H3C_4AF69B"
#define WIFI_PASS "13502723117a"
uint8_t EspBuff[ESPBUFF_MAX_SIZE];
uint16_t EspCnt=0;
extern DMA_HandleTypeDef hdma_usart2_rx;
void ESP8266_Init(void ){
    HAL_UART_Receive_DMA(&huart2,EspBuff,ESPBUFF_MAX_SIZE);
    __HAL_UART_ENABLE_IT(&huart2,UART_IT_IDLE);
    while (ESP8266_SendCmd("AT+RST\r\n","ready"))
        while (ESP8266_SendCmd("AT\r\n","OK")){}
    while (ESP8266_SendCmd("AT+CWMODE=1\r\n","OK")){}
    while (ESP8266_SendCmd("AT+CWJAP=\""WIFI_NAME"\",\""WIFI_PASS"\"\r\n","OK")){}
    printf("success/r/n");
}
void ESP8266_Clear(void ){
    memset(EspBuff,0, sizeof(EspBuff));
    EspCnt=0;
}
void ESP8266_SendString(uint8_t *str,uint8_t len){
    uint8_t i=0;
    for (i=0;i<len;i++){
        USART2->DR=*str;
        str++;
        HAL_Delay(1);
    }
}
uint8_t ESP8266_SendCmd(uint8_t *cmd,uint8_t *res){
    uint8_t num=200;
    ESP8266_Clear();
    ESP8266_SendString(cmd, strlen((const char *)cmd));
    while (num--){
        if (strstr((const char *)EspBuff,(const char *)res)!=NULL){
            return 0;
        }
        HAL_Delay(10);
    }
    return 1;
}