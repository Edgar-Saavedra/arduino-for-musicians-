## MIDI
- midi keyboard is connected to a comp or instrtument and sends data like:
    - key pressed
    - pedal status
    - position of modulation
    - pitch bending controllers
- "Transmits perfomnance"
### MIDI Ports
- OUT : used to transmit data to another MIDI device via MIDI cable
    - the connection as serial connection
    - data flows one byte at a time at rate of `31,250 baud`
- IN : used to extablish a connection from a MIDI Device
    - receiving hardward uses information to tigger a sound or other action
- THRU: used to daisy chain MIDI Devices.
    - passes along any messages that are recieved at the MIDI In port
### MIDI MESSAGES
- `8-bit bytes` are at the heart of MIDI protocol
- #### STATUS BYTE
    - MIDI messages start with a `status byte`; starts usually with `1`
    - status byte: specifies the type of event. EX. "Note-On" or "Note-OFF"
    - falls within decimal range of `128` to `255`. Correspond to range of 8-bit values
      | Decimal | Binary |
      | ------- | ------ |
      |   128   |  10000000 |
      |   255   |  11111111 |
- #### DATA BYTE
    - the first bit of a `data byte` is always `0`.
    - Data Bytes range `0` - `127`
      | Decimal | Binary |
      | ------- | ------ |
      |   0     |  00000000 |
      |   127   |  01111111 |
- #### Message types:
    - #### Channel Messages
        - Used to transmit data that is intended for one of the `16 channels` provided by MIDI specification
        - Divided in to 2 smaller categories:
            - #### Channel Voice
                - A MIDI channel number from `1 - 16` is encoded in each Channel Message
                - allows to use a single MIDI cable to transmit perfomance data, intended for upto 16 different sound sources on a single device.
                - EXAMPLE: When receiving hardward or software receives a Channel Voice message such as a Note-ON message and play with associated channel.
                - first `four bits` are used to indicate the type of message eg. Note-ON or Note-OFF
                - `second grouping of four bits` specifies the midi channel
                  | status byte | Decimal value | Message Type | Channel |
                  | ----------- | ------------- | ------------ | ------- |
                  | 1001 0000   |  144          | 1001 = NOTE-ON | 0000 = Channel 1 |
                  | 1000 0000   |  128          | 1000 = NOTE-OFF | 0000 = Channel 1 |
                  | 1001 0001   |  145          | 1001 = NOTE-ON | 0001 = Channel 2 |
                  | 1000 0001   |  129          | 1000 = NOTE-OFF | 0001 = Channel 2 |
                - `NOTE-ON message`
                    - first four bits indicate the type of message
                    - second sereis of four bits indicate channel
                    - requires two data bytes
                        - first byte `0kkkkkkk` note number `0-127`
                        - second byte `0vvvvvvv` velocity of the key press `0-127`
                    - Sometimes note-on used for note-off
                        - Running Status : Has todo with data compression
                        - its possible to transmit just the data bytes
                        - running status can beu used to optimize streams of data.
                        - status bytes should be refreshed every 16 -32 events.
                        - Advanced, topic
                - `NOTE-OFF message`
                    - When note is released
                    - note off `1000` `128` - `143` (1-16)
                        - first byte `0kkkkkkk` note number `0-127`
                        - second byte `0vvvvvvv` velocity of the key press `0-127`
                - Polyphonic Key Pressure
                    - `1010` (decimal 160 - 175)
                - Channel Pressure (after touch)
                    - `1101`  (208 - 223)
                - Program Change message
                    - used to specifyy a new sound or "patch", play on a different  instruments
                    - `1100` , (192-207)
                - Pitch Wheel change
                    - requires 2 data bytes
                    - `1110`, (224 - 239)
                    - There are Least significant and most significatn
                - `Control Change Messages`
                    - A message within a message
                    - First data byte of a control change, One of possible 120 controller numbers
                    - Second data byte specifies the controller value
                    - `1011` (176 - 191)
                    - 0ccccccc controller number (0 - 119)
                    - 0vvvvvvv Controller value (0 - 127)
                    - used for selecting different banks
            - #### Channel Mode
                - A subset of Control messages in the range of `120 to 127`
                - if the first data byte of a Control Change Message is equal to 121, a device should reset the condition of all its controllers
                - `1011` Control Change status byte, (176-191) control chaange byte
                - 0kkkkkkk 121 indicate reset all controllers
                - 0vvvvvvv usually zero
                - `Local Control`
                    - used to interrupt the internal control path between the keyboard and sound generating circuit.
                    - typically turned off when a keyboard is used in a squencing enviroment so notes not triggered twice
                    - data byte of `122` indicates the Local Control
                    - `1011` (Control Change status byte), 176-191, data bytes : 0kkkkkkk (121 indicates local control function) 0vvvvvvv
    - #### System Messages
        - System wide messages that are primarily used to transmit `timing information`
            - relate to entire MIDI system
        - `System Common Messages`
            - these messages do not pertain to a particular channel.
            - first four bits of each of the following is equal to `1111`
            - indicate something is happening
            | Binary Value | Decimal Value | Data Bytes | Notes |
            | ------------ | ------------- | ---------- | ----- |
            | 1111 0000    |  240          |  various   | System exclusive | 
            | 1111 0001    |  241          | 0nnndddd (nnn = Message type) (dddd = values) | MIDI Time Code cneter Frame |
            | 1111 0010    |  242          | 0LLLLLLL , 0MMMMMMM | Song position Pointer - 14-bit value representing the number of of MIDI beats |
            | 1111 0111    |  247          | NA         | END OF exlcusive : signals the end of a system exclusive dump |
            | 1111 1000    |  248          |  | Timing Clock: 24 Timing clock miessages are sent per quarter note. THis message is particularly useful for synchronizing a MIDI arpeggiator or delay when ultra percise timing is not required.
            | 1111 1011    | 250           |  | Start: indicates that sequence wil begin, when next clock message is received
            | 1111 1100    | 252           |  | Continue: indicates a sequence will ocntinue playing when nex clock message recieved
            | 1111 1110    | 254           |  | Stop: stops the sequence ignoring timing
            | 1111 1111    | 255           |  | Reset:  Reset all recievers in the system to power-up status. Use sparingly, preferably under manual control. Dont send on power up.

        - `System Exclusive Messages`
            - originally intended as non-real time messages
            - used to transfer variable-length data in the form of sample dumps, device settings etc.
            - a unique message could be sent
            | Byte | Description |
            | 240  | System exclusive status byte|
            | 18 | E-MU ID byte|
            | 04 | Produc ID byte |
            | dd | Device ID |
            | data | varaiable number of data bytes| 
            | 247 | end of exclusive |
        - `Unversal system exclusive messages`
        - They provide access to MIDI Machine Control commands. Allows for an external device to control a DAW or hardware recorder
        - The first 2 bytes indicate the message is a REAL TIME UNIVERSAL EXCLUSIVE MESSAGE, Third byte indicates a device ID.
        - Structure of a MIDI Machine Control Command
            | Byte (hex) | Decimal | description |
            | ---------- | ------- | ----------- |
            | F0 | 240 | F0 followed by 7F indicates Universal Real Time SysEx
            | 7F | 127 |  |
            | Device ID | ?? | Specifies a particular device 7F = all devices |
            | 06 | 6 | MID Machine Control Command |
            | dd | ?? | Command (see table 5.2)
            | F7 | 247 | End of MMC Message |
        - Single Byte MMC Commands
            | Command | Decimal | Description |
            | ------- | ------- | ----------- |
            | 01 | 1 | stop |
            | 02 | 2 | play |
            | 03 | 3 | deferred play |
            | 04 | 4 | Fast Forward |
            | 05 | 5 | Rewind |
            | 06 | 6 | record strobe (punch in) |
            | 07 | 7 | record exit (punch out) |
            | 08 | 8 | Record pause |
            | 09 | 9 | pause |
            | 10 | 10 | Eject |
            | 11 | 11 | Chase |
            | 12 | 12 | Command Error reset |
            | 13 | 13 | MMC Reset |
        - Need to configure device to listen to MMC command
            - Differe type of SysEX messages
            - 2 ypes: Real Time and Non-Real Time
            - Non-Real time example: initiating a sample dump or turning Downloadable Sounds on/off
## MIDI Libraries
- [Arduino MIDI Library](https://github.com/FortySevenEffects/arduino_midi_library)


https://www.instructables.com/Send-and-Receive-MIDI-with-Arduino/
https://www.instructables.com/Scripting-Processing-with-MIDI/
https://learn.sparkfun.com/tutorials/connecting-arduino-to-processing/all
http://www.smallbutdigital.com/projects/themidibus/
https://itp.nyu.edu/physcomp/labs/labs-serial-communication/lab-midi-output-using-an-arduino/
https://bvavra.github.io/MIDI_Accordion/sending-midi/
https://help.ableton.com/hc/en-us/articles/209774225-Setting-up-a-virtual-MIDI-bus
https://www.youtube.com/watch?v=zZXCA7Eh0sk