void fanControl(int rpm)
{
    int FAN_OUTPUT = map(rpm, MIN_RPM, MAX_RPM, 0, 255);
    ledcWrite(CHANNEL, FAN_OUTPUT);

    // for IDE 3.0 use
    // ledcWrite(FAN_PIN, FAN_OUTPUT);
}

void lightControl(int numLight)
{
    int blinkLED;

    for (int i = 0; i < 10; i++)
    {
        digitalWrite(LED_PIN[i], LOW);
    }

    for (blinkLED = 0; blinkLED < numLight; blinkLED++)
    {
        digitalWrite(LED_PIN[blinkLED], HIGH);
    }
}