const int speakerPin = 9;
const int frequency = 880;
const int duration = 50;

const int potPin = 0;
int potValue;
const int pushButtonPin = 2;

int pushButtonStatus = HIGH;
// trak metronome is on/off
boolean on = false;
// track tempo and time delay
unsigned int beats_per_minute = 60;
unsigned int MS_per_beat = 0;
// track time
long last_time = 0;
void setup() {
    Serial.begin(9600);
    pinMode(pushButtonPin, INPUT_PULLUP);
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

void loop() {
    checkPushButton();
    checkPot();
    // play tone if the metronome is on
    long current_time = millis();
    Serial.println(on);

    // better than having a delay we check to see if 
    // we play our tone if on and our time is more than beats per min
    if((current_time - last_time >= MS_per_beat) && on == true) {
        // output the tone
        tone(speakerPin, frequency, duration);
        last_time = current_time;
    } 
}
