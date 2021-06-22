// switch with 10k external pullup resistor
// pull up resistor keeps button off to ground till button is pressed to 5v
// By default the pin mode low
const int buttonPin = 2;  //digital pin 2
int last_state = 0; // store laste state of button

void setup() {
    Serial.begin(9600);
    pinMode(buttonPin, INPUT);
}

void loop() {
    // check button state
    int state = digitalRead(buttonPin);
    // print state if has changed
    if (state != last_state) {
        Serial.println(state);
        last_state = state;
    }
}
