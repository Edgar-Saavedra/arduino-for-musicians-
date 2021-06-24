#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();
const byte transposition = 3;
const byte channel = 1;
byte note = 0;
byte velocity = 0;
void setup() {
    MIDI.begin();
}

void loop() {
    if (MIDI.read()) {
        switch (MIDI.getType())
        {
        case midi::NoteOn:
            // transpose note (data byte 1) and send to channel 1
            note = MIDI.getData1();
            velocity = MIDI.getData2();
            MIDI.sendNoteOn(note + transposition, velocity, channel);
            /* code */
            break;
        case midi::NoteOff:
            // transpose note (data byte 1) and send to channel 1
            note = MIDI.getData1();
            velocity = MIDI.getData2();
            MIDI.sendNoteOff(note + transposition, velocity, channel);
            /* code */
            break;
        default:
            break;
        }
    }
}
