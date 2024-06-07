void fanControl(int rpm)
{
    int FAN_OUTPUT = map(rpm, MIN_RPM, MAX_RPM, 0, 255);
    ledcWrite(CHANNEL, FAN_OUTPUT);
}

void lightControl(int numLight)
{
    int blinkLED;

    for (int i = 0; i < 10; i++)
    {
        pinMode(LED_PIN[i], OUTPUT);
        digitalWrite(LED_PIN[i], LOW);
    }

    for (blinkLED = 0; blinkLED < numLight; blinkLED++)
    {
        pinMode(LED_PIN[blinkLED], OUTPUT);
        digitalWrite(LED_PIN[blinkLED], LOW);
    }
}