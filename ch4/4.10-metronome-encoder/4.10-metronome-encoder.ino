// A METRONOME CONTROLLED WITH AN ENCODER.
const int speakerPin = 9;
const int frequency = 880;
const int duration = 50;

// POT
const int potPin = 0;
int potValue;
// END: POT

// PUSH BUTTON 
const int pushButtonPin = 2;
int pushButtonStatus = HIGH;
// trak metronome is on/off
// END: PUSH BUTTON

boolean on = false;


// track tempo and time delay
unsigned int beats_per_minute = 60;
unsigned int MS_per_beat = 0;
// track time
long last_time = 0;

// ENCONDER
const int encoderPinA = 2;
const int encoderPinB = 3;
const int encoderPinSW = 4;
int encoderALast = LOW;
int encoderSWLast = LOW;
unsigned long encoderLastButtonPress = HIGH;
// END: ENCONDER

void setup() {
    Serial.begin(9600);
    // pinMode(pushButtonPin, INPUT_PULLUP);
    pinMode(encoderPinA, INPUT_PULLUP);
    pinMode(encoderPinB, INPUT_PULLUP);
    pinMode(encoderPinSW, INPUT_PULLUP);
    // calc MS_per_beat base on tempo in BPM
    unsigned int milliseconds_per_minute = 1000 * 60;
    MS_per_beat = milliseconds_per_minute / beats_per_minute;
}

// Take a potentiometer, if it values change, update our beats per minute
void checkPot() {
    // check pot status
    int value = analogRead(potPin);
    // re-calc the tempo if value has changed
    if (value != potValue) {
        // map the value t a resonable metronome range of 
        // 30 BPM to 350 BPM
        beats_per_minute = map(value, 0,1023, 30, 350);
        // recalc the delay time
        unsigned int milliseconds_per_minute = 1000 * 60;
        MS_per_beat = milliseconds_per_minute / beats_per_minute;
        // update pot val
        potValue = value;
    }
}

// Have a debounced button that will set an on boolean to play our metronome
void checkPushButton() {
    // check digital pin 2 for a button press
    int button_state =  digitalRead(pushButtonPin);
    // check for button press
    if (button_state == LOW && button_state != pushButtonStatus) {
        // swap on/off states
        on =! on;
        // update button status
        pushButtonStatus = button_state;
        // use delay for a kludgy form of debounce
        Serial.println("push btn pressed");
        delay(20);
    }
    // check button release
    if (button_state == HIGH && button_state != pushButtonStatus) {
        pushButtonStatus = button_state;
        Serial.println("push btn released");
        delay(20);
    }
}

/**
 * Read from a Rotary encoder and start metronome if button pressed.
 * Increase beats per minute when dial turned.
 */
void checkEncoder() {
    boolean encoderA = digitalRead(encoderPinA);
    if( (encoderALast == HIGH) && (encoderA == LOW) ) {
        if( digitalRead(encoderPinB) == LOW ) {
            beats_per_minute = beats_per_minute + 10.0;
        }
        else {
            beats_per_minute = beats_per_minute - 10.0;
        }
        unsigned int milliseconds_per_minute = 1000 * 60;
        MS_per_beat = milliseconds_per_minute / beats_per_minute;
    }
    encoderALast = encoderA;
    int button_state =  digitalRead(encoderPinSW);
    if (encoderSWLast == HIGH && button_state == LOW) {
        Serial.println("pressed");

        if (encoderLastButtonPress == HIGH) {
            encoderLastButtonPress = LOW;
            on = HIGH;
        }
        else if (encoderLastButtonPress == LOW) {
            encoderLastButtonPress = HIGH;
            on = LOW;
        }
    }
    encoderSWLast = button_state;
}

void loop() {
    // checkPushButton();
    // checkPot();
    checkEncoder();

    // play tone if the metronome is on
    long current_time = millis();
    // Serial.println(on);

    // better than having a delay we check to see if 
    // we play our tone if on and our time is more than beats per min
    if((current_time - last_time >= MS_per_beat) && on == true) {
        // output the tone
        tone(speakerPin, frequency, duration);
        last_time = current_time;
    } 
}
