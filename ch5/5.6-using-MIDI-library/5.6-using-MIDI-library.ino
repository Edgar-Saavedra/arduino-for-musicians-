#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();
const int velocity = 127;
const int channel = 1;
void setup() {
    MIDI.begin(1);
}

void loop() {
  // For each note from 53 to 93, perform the following code for that note,
  // incrementing note by 1 each time.
  for (int note = 53; note <= 93; note ++) {
    MIDI.sendNoteOn(note, velocity, channel);  // Turn the note on.
    delay(1000);                               // Wait 1000 milliseconds.
    MIDI.sendNoteOff(note, velocity, channel); // Turn the note off.
  }
//    for (int i = 50; i < 70; i++)
//    {
//        MIDI.sendNoteOn(i, velocity, channel);
//        MIDI.sendNoteOn(i + 4, velocity, channel);
//        MIDI.sendNoteOn(i + 8, velocity, channel);
//        delay(125);
//        MIDI.sendNoteOff(i, 0, channel);
//        MIDI.sendNoteOff(i + 4, 0, channel);
//        MIDI.sendNoteOff(i + 8, 0, channel);
//    }
//    
}
