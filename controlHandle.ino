void fanControl(int rpm)
{
    int FAN_OUTPUT = map(rpm, 0, 100, 255, 0);
    ledcWrite(CHANNEL, FAN_OUTPUT);

    // for IDE 3.0 use
    // ledcWrite(FAN_PIN, FAN_OUTPUT);
}

void lightControl(int numLight)
{
    for (int i = 0; i < 10; i++)
    {
        digitalWrite(LED_PIN[i], (i < numLight) ? HIGH : LOW);
    }
}