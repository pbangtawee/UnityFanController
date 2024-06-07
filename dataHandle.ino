void dataIncoming()
{
    String INCOMING_JSON = "";

    INCOMING_JSON = Serial.readStringUntil('\n');
    Serial.println("data: " + INCOMING_JSON);

    JsonDocument JSON_DOC;
    deserializeJson(JSON_DOC, INCOMING_JSON);

    CONTROL_RPM = JSON_DOC["speed"];
    CONTROL_LIGHT = JSON_DOC["lights"];
}

void dataOutgoing(int rpm, float coreTemp)
{
    JsonDocument JSON_DOC;

    JSON_DOC["speed"] = rpm;
    JSON_DOC["temp"] = coreTemp;

    serializeJson(JSON_DOC, Serial);
    Serial.println();
}