#include <ArduinoJson.h>

#ifdef __cplusplus
extern "C" {
  #endif
  uint8_t temprature_sens_read();
  #ifdef __cplusplus
}
#endif

uint8_t temprature_sens_read();

const int FAN_PWM = 20;
const int FAN_PIN = 21;
const int LED_PIN[] = {22, 23, 24, 25, 26, 27, 28, 29, 30, 31};

// constant value
const int MIN_RPM = 0;
const int MAX_RPM = 6000;

int FAN_RPM;       // output fan speed
float CORE_TEMP;   // output core temp
int CONTROL_RPM;   // input fan speed
int CONTROL_LIGHT; // input light

// PWM Setting
const int CHANNEL = 0;
const int FREQUENCY = 5000;
const int RESOLUTION = 8;

// timer
const int INTERVAL = 1; // in second
unsigned long LAST_SEND;

void setup()
{
    Serial.begin(115200);

    pinMode(FAN_PIN, OUTPUT);
    for (int i = 0; i < 10; i++)
    {
        pinMode(LED_PIN[i], OUTPUT);
        digitalWrite(LED_PIN[i], LOW);
    }

    ledcSetup(CHANNEL, FREQUENCY, RESOLUTION);
    ledcAttachPin(FAN_PIN, CHANNEL);
}

void loop()
{
    if (Serial.available() > 0)
    {
        dataIncoming();
        fanControl(CONTROL_RPM);
        lightControl(CONTROL_LIGHT);
    }

    if (millis() - LAST_SEND >= INTERVAL * 1000)
    {
        FAN_RPM = fanSpeed();
        CORE_TEMP = coreTemp();

        dataOutgoing(FAN_RPM, CORE_TEMP);
        LAST_SEND = millis();
    }
}