int fanSpeed() {
  int fanSpeed;
  fanSpeed = map(CONTROL_RPM, 0, 100, 800, 3000);
  
  // fanSpeed = (PULSE_COUNT * 60) / 2; // (PulsePerSec * 60Sec = RPM)/2PulsePerRound
  // PULSE_COUNT = 0;

  return fanSpeed;
}

float coreTemp() {
  float temp = (temprature_sens_read() - 32) / 1.8;

  return temp;
}
