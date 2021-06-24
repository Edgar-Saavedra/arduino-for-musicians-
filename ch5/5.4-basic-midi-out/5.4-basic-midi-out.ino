// Basic MIDI output
void setup() {
    Serial.begin(31250); //serial output with standard midi baud rate
}

void playMIDINote(byte channel, byte note, byte velocity) {
    byte noteOnStatus = 0x90 + (channel - 1); //MIDI channels 1-16 are really 0 - 15
    // send notes to MIDI output;
    Serial.write(noteOnStatus);
    Serial.write(note);
    Serial.write(velocity);
}

void loop() {
    // play a chromatic scale starting on middle c (60)
    for (int note = 60; note < 60 + 12; note++)
    {
        // play note
        playMIDINote(1, note, 100);
        // pause
        delay(60);
        // turn note off (velocity =0)
        playMIDINote(1, note, 0);
        // pause
        delay(60);
    }
    
}
