#include <ArduinoJson.h>

#ifdef __cplusplus
extern "C"
{
#endif
  uint8_t temprature_sens_read();
#ifdef __cplusplus
}
#endif

uint8_t temprature_sens_read();

const int FAN_PULSE = 4;
const int FAN_PIN = 16;
const int LED_PIN[] = {18, 19, 13, 12, 14, 27, 26, 25, 33, 32};

// constant value
const int MIN_RPM = 0;
const int MAX_RPM = 3000;

int FAN_RPM;             // output fan speed
int CORE_TEMP;           // output core temp
int CONTROL_PERCENT = 0; // input fan speed
int CONTROL_LIGHT = 0;   // input light
volatile int PULSE_COUNT = 0;

// PWM Setting
const int CHANNEL = 0;
const int FREQUENCY = 25000;
const int RESOLUTION = 8;

// timer
const int INTERVAL = 1; // in second
unsigned long LAST_SEND;

void IRAM_ATTR isr()
{
  PULSE_COUNT++;
}

void setup()
{
  Serial.begin(115200);

  pinMode(FAN_PULSE, INPUT_PULLUP);

  attachInterrupt(FAN_PULSE, isr, FALLING);

  for (int i = 0; i < 10; i++)
  {
    pinMode(LED_PIN[i], OUTPUT);
    digitalWrite(LED_PIN[i], LOW);
  }

  ledcSetup(CHANNEL, FREQUENCY, RESOLUTION);
  ledcAttachPin(FAN_PIN, CHANNEL);

  fanControl(CONTROL_RPM);
  lightControl(CONTROL_LIGHT);

  LAST_SEND = millis();
}

void loop()
{
  if (Serial.available() > 0)
  {
    dataIncoming();
    fanControl(CONTROL_PERCENT);
    lightControl(CONTROL_LIGHT);
  }

  if (millis() - LAST_SEND >= INTERVAL * 1000)
  {
    detachInterrupt(FAN_PULSE);

    FAN_RPM = fanSpeed();
    CORE_TEMP = coreTemp();

    dataOutgoing(FAN_RPM, CORE_TEMP);
    LAST_SEND = millis();

    attachInterrupt(FAN_PULSE, isr, FALLING);
  }
}