void checkPushButton(int pushButtonPin, int &pushButtonStatus, boolean &on) {
    // check digital pin 2 for button press
    int button_state = digitalRead(pushButtonPin);
    if (button_state == LOW && button_state != pushButtonStatus) {
        // swap on/off state
        on =! on;
        // update buttonstatus
        pushButtonStatus = button_state;
        // use delay for kludgy form of debouncing
        delay(20);
    }
    // check for release
    if (button_state == HIGH && button_state != pushButtonStatus) {
        // update the push button status to off
        pushButtonStatus = button_state;
        delay(20);
    }
}

void checkPot(int potPin, unsigned int &beats_per_minute, int &potValue, unsigned int &MS_per_beat, int speakerPin, int frequency, int duration) {
    int value = analogRead(potPin);
    if (value != potValue) {
        beats_per_minute = map(value, 0, 1023, 30, 350);

        unsigned int milliseconds_per_minute = 1000 * 60;
        MS_per_beat = milliseconds_per_minute / beats_per_minute;
        potValue = value;
    }
    Serial.println("frequency");
    Serial.println(frequency);
    Serial.println("MS_per_beat");
    Serial.println(MS_per_beat);
    Serial.println("potValue");
    Serial.println(potValue);
    Serial.println("beats_per_minute");
    Serial.println(beats_per_minute);
    tone(speakerPin, frequency, duration);
    delay(MS_per_beat);
}