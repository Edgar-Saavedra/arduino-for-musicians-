
void setup() {
    Serial.begin(31250);
    byte statusCC = 176; // control change on channel 1
    byte bankSelect = 32; // control change type : banck select
    byte bank = 1; // BANCK 1

    // send control change message
    Serial.write(statusCC); // send status byte, select controller in first data byte
    Serial.write(bankSelect); // send data byte 1, determin the value
    Serial.write(bank); // Chose the bank

    // set up bytes to send a program change
    byte programChange = 192;
    byte program = 5;

    // send program change message
    Serial.write(programChange); // send status byte
    Serial.write(program);
}

void loop() {
}
