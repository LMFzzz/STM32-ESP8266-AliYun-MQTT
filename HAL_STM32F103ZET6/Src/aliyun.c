//
// Created by LMF on 2024/1/28.
//
#include <stdlib.h>
#include "aliyun.h"
#include "esp8266.h"
#include "stdio.h"
#include "string.h"
#include "main.h"
extern uint8_t EspBuff[ESPBUFF_MAX_SIZE];
extern uint16_t EspCnt;

void Ali_Yun_Init(void ){
    //设置用户名，密码
    while(ESP8266_SendCmd("AT+MQTTUSERCFG=0,1,\"NULL\",\""ALI_USERNAME"\",\""ALI_PASSWD"\",0,0,\"\"\r\n","OK")){}
    HAL_Delay(10);
    // 设置客服id
    while(ESP8266_SendCmd("AT+MQTTCLIENTID=0,\""ALI_CLIENTID"\"\r\n","OK")){}

    // 连接阿里云  AT+MQTTCONN=0,"iot-06z00b28nanp9ew.mqtt.iothub.aliyuncs.com",1883,1
    while(ESP8266_SendCmd("AT+MQTTCONN=0,\""ALI_MQTT_HOSTURL"\",1883,1\r\n","OK")){}

    Ali_Yun_Topic();
}
void Ali_Yun_Topic(void ){
    while (ESP8266_SendCmd("AT+MQTTSUB=0,\""ALI_TOPIC_SET"\",0\r\n","OK")){}
    while (ESP8266_SendCmd("AT+MQTTSUB=0,\""ALI_TOPIC_POST"\",0\r\n","OK")){}

}
void Ali_Yun_Send(uint8_t *msgBuf,uint8_t str){

}
