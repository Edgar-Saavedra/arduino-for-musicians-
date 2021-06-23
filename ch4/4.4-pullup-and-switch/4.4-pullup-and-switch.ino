// switch internal pullup
// this elminates the need for a pullup resistor, by default 
// the pin state is HIGH
const int buttonPin = 2;
int last_state = 0;

void setup() {
    Serial.begin(9600);
    // set internal pull up resister on digital pin 2
    pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
    // check push button state
    int state = digitalRead(buttonPin);

    // print to monitor
    if (state != last_state) {
        Serial.println(state);
        last_state = state;
    }
}
