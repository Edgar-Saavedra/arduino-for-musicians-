
void setup() {
    // Establish standard MIDI baud rate
    Serial.begin(31250);
    byte noteOnStatus = 144;
    byte noteNumber = 60; // MIDDLE C
    byte velocity = 100; // velocity ranges from 0 - 127
    // out put a MDID note-on message:
    Serial.write(noteOnStatus);
    Serial.write(noteNumber);
    Serial.write(velocity);
}

void loop() {
}
