
// MID MACHINE CONTROL
const byte stopCommand = 0x01;
const byte playCommnad = 0x02;

void mmcCommand(byte command) {
    Serial.write(0xF0);
    Serial.write(0x7F);

    // send command bytes
    Serial.write(0x7F); //all devices
    Serial.write(0x06); // denotes this is a MMC command
    Serial.write(command); // send command
    Serial.write(0xF7); // END MMC Command

}

void setup() {
    // baud
    Serial.begin(31250);
    // star playback
    mmcCommand(playCommnad);
    // let device play for 5 seconds
    delay(5000);
    mmcCommand(stopCommand);
}

void loop() {
}
