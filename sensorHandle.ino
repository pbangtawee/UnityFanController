int fanSpeed()
{
    int rawSpeed = 0;

    for (int i = 0; i < 5; i++)
    {
        rawSpeed += analogRead(FAN_PWM);
    }

    rawSpeed = rawSpeed / 5;
    return rawSpeed;
}

float coreTemp()
{
    float temp = (temprature_sens_read() - 32) / 1.8;

    return temp;
}