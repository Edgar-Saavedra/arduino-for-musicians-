

void playMIDINote(byte channel, byte note, byte velocity) {
    byte noteOnStatus = 0x90 + (channel - 1); //MIDI channels 1-16 are really 0 - 15
    // send notes to MIDI output;
    Serial.write(noteOnStatus);
    Serial.write(note);
    Serial.write(velocity);
}

void setup() {
    Serial.begin(31250);
    // use analog 0 to seed the random number negertor
    randomSeed(analogRead(0));
}

void loop() {
    // select random param
    byte note = random(20, 100);
    int duration = random(10, 100);
    byte velocity = random(40, 127);
    // play the note with the given params
    playMIDINote(1, note, velocity);
    delay(duration);

    // turn note off
    playMIDINote(1, note, 0);
    delay(10);
}
