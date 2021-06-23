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
                - NOTE-ON message
                    - first four bits indicate the type of message
                    - second sereis of four bits indicate channel
                    - requires two data bytes
                        - first byte `0kkkkkkk` note number `0-127`
                        - second byte `0vvvvvvv` velocity of the key press `0-127`
            - #### Chanel Mode
    - #### System Messages
        - System wide messages that are primarily used to transmit `timing information` 

