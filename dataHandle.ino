void dataIncoming()
{
    String INCOMING_JSON = "";

    INCOMING_JSON = Serial.readStringUntil('\n');

    JsonDocument JSON_IN;
    deserializeJson(JSON_IN, INCOMING_JSON);

    CONTROL_RPM = JSON_IN["speed"];
    CONTROL_LIGHT = JSON_IN["lights"];
}

void dataOutgoing(int rpm, float coreTemp)
{
    JsonDocument JSON_OUT;

    JSON_OUT["speed"] = rpm;
    JSON_OUT["temp"] = coreTemp;

    serializeJson(JSON_OUT, Serial);
    Serial.println();
}