#include "/Users/esaavedra/Work/personal/projects/arduino-for-musicians/ch4/4.7-checkpushbutton/4.7-checkpushbutton.ino"
// A metronome with a pot
const int speakerPin = 9;
const int frequency  = 880;
const int duration = 50;
const int potPin = 0;
int potValue;

unsigned int beats_per_minute = 60;
unsigned int MS_per_beat = 0;
void setup() {
    Serial.begin(9600);
    unsigned int milliseconds_per_minute = 1000 * 60;
    MS_per_beat = milliseconds_per_minute / beats_per_minute;
}

void loop() {
    checkPot(potPin, beats_per_minute, potValue, MS_per_beat, speakerPin, frequency, duration);
    // int value = analogRead(potPin);
    // if (value != potValue) {
    //     beats_per_minute = map(value, 0, 1023, 30, 350);

    //     unsigned int milliseconds_per_minute = 1000 * 60;
    //     MS_per_beat = milliseconds_per_minute / beats_per_minute;
    //     potValue = value;
    // }
    // tone(speakerPin, frequency, duration);
    // delay(MS_per_beat);
}
