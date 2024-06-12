void fanControl(int percent)
{
    int FAN_OUTPUT = map(percent, 0, 100, 255, 0);
    ledcWrite(CHANNEL, FAN_OUTPUT);
}

void lightControl(int numLight)
{
    for (int i = 0; i < 10; i++)
    {
        digitalWrite(LED_PIN[i], (i < numLight) ? HIGH : LOW);
    }
}