int fanSpeed()
{
  int fanSpeed;
  fanSpeed = map(CONTROL_RPM, 0, 100, 800, 3000);

  return fanSpeed;
}

float coreTemp()
{
  float temp = (temprature_sens_read() - 32) / 1.8;

  return temp;
}
