void dataIncoming()
{
    String INCOMING_JSON = "";

    INCOMING_JSON = Serial.readStringUntil('\n');
    Serial.println("data: " + INCOMING_JSON);

    JsonDocument JSON_DOC;
    deserializeJson(JSON_DOC, INCOMING_JSON);

    CONTROL_RPM = JSON_DOC["speed"];
    CONTROL_LIGHT = JSON_DOC["lights"];

    Serial2.println("Input data :: " + CONTROL_RPM + " RPM. and " + CONTROL_LIGHT + " LEDs.");
}

void dataOutgoing(int rpm, float coreTemp)
{
    JsonDocument JSON_DOC;

    JSON_DOC["speed"] = rpm;
    JSON_DOC["temp"] = coreTemp;

    serializeJson(JSON_DOC, Serial);
    Serial.println();

    Serial2.print("Send : ");
    Serial2.println(JSON_DOC);
}