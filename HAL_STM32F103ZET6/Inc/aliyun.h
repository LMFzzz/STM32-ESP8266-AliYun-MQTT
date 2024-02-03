//
// Created by LMF on 2024/1/22.
//

#ifndef HAL_STM32F103ZET6_ALIYUN_H
#define HAL_STM32F103ZET6_ALIYUN_H
#include "main.h"

#define ALI_CLIENTID "k0osgjHSO5X.SmartAgriculture|securemode=2\\,signmethod=hmacsha256\\,timestamp=1706447105675|"
#define ALI_USERNAME "SmartAgriculture&k0osgjHSO5X"
#define ALI_PASSWD "1f518bec93fc0a4b9c0737d1e8c5aabe5e49ab1b0d8e5e184e7f60f9410a695c"
#define ALI_MQTT_HOSTURL "iot-06z00c7vytb5uy0.mqtt.iothub.aliyuncs.com"
#define ALI_PORT "1883"
#define ALI_TOPIC_SET "/sys/k0osgjHSO5X/SmartAgriculture/thing/service/property/set"
#define ALI_TOPIC_POST "/sys/k0osgjHSO5X/SmartAgriculture/thing/service/property/post"
void Ali_Yun_Init(void );
void Ali_Yun_Topic(void );
void Ali_Yun_Send(uint8_t *msgBuf,uint8_t str);
char * GenerateJson(uint8_t* temp,uint8_t* hum,uint8_t light,uint32_t CO2Data);
void Ali_Yun_GetRCV(void );
#endif //HAL_STM32F103ZET6_ALIY UN_H
