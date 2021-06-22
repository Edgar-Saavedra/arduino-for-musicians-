## arduino-cli
- [compiling](https://arduino.github.io/arduino-cli/latest/commands/arduino-cli_compile/)
    - `$ arduino-cli compile --fqbn=arduino:avr:uno --port=/dev/cu.usbmodem144301 ch4/metronome-4.2/metronome-4.2.ino;`
- [uploading](https://arduino.github.io/arduino-cli/latest/commands/arduino-cli_upload/)
    - `$  arduino-cli upload --fqbn=arduino:avr:uno --port=/dev/cu.usbmodem144301 ch4/metronome-4.2/metronome-4.2.ino`
- [getting board info](https://arduino.github.io/arduino-cli/latest/commands/arduino-cli_board/)
    - `$ arduino-cli board list`
    - ```--additional-urls strings   Comma-separated list of additional URLs for the Boards Manager.
      --config-file string        The custom config file (if not specified the default will be used).
      --format string             The output format, can be {text|json}. (default "text")
      --log-file string           Path to the file where logs will be written.
      --log-format string         The output format for the logs, can be {text|json}.
      --log-level string          Messages with this level and above will be logged. Valid levels are: trace, debug, info, warn, error, fatal, panic
  -v, --verbose                   Print the logs on the standard output.
  ```
- [installing board](https://arduino.github.io/arduino-cli/latest/commands/arduino-cli_board_listall/)
    - `$ arduino-cli board listall [boardname] [flags]`
    - List all known boards and their corresponding FQBN.
- [new sketch](https://arduino.github.io/arduino-cli/latest/commands/arduino-cli_sketch_new/)
    - Create a new Sketch
    - `$ arduino-cli sketch new MultiBlinker`
    - arduino-cli sketch new [flags]
        - ```
        --additional-urls strings   Comma-separated list of additional URLs for the Boards Manager.
        --config-file string        The custom config file (if not specified the default will be used).
        --format string             The output format, can be {text|json}. (default "text")
        --log-file string           Path to the file where logs will be written.
        --log-format string         The output format for the logs, can be {text|json}.
        --log-level string          Messages with this level and above will be logged. Valid levels are: trace, debug, info, warn, error, fatal, panic
        -v, --verbose                   Print the logs on the standard output.
        ```
- [Read Serial Monitor](https://www.woolseyworkshop.com/2020/08/07/quick-tip-using-the-screen-utility-to-view-arduino-serial-output/)
    - `$ ls /dev/tty.*`
    - The second piece of information we need is the baud rate (number of bits per second) of the serial connection to the board. This is specified within our sketch with the Serial.begin(9600);
    - `$ screen <port> <baud>`
    - To disconnect the screen utility, press CTRL-a followed by CTRL-\ and then press y at the prompt asking if you really want to quit.

## Troubleshooting
- Some ports have issues uploading; disconnect and reconnect; reset button; make sure correct "Fully Qualified Board Name" (fqbn); Make sure correct port (`$ arduino-cli board list`); pin `A0` connected can give issues.
- ### what is avrdude: stk500_recv() error? [link](https://www.programmingelectronics.com/avrdude-stk500_recv/)
    - is caused by a generic connection error between your computer and the Arduino, and can result from many different issues
        - Try disconnecting and reconnecting the USB cable. Yes – that simple!
        - Press the reset button and see if you can upload without the avrdude: stk500_recv() error.
        - Close the Arduino IDE, and reopen it again – believe it or not, this can work!
        - Make sure you have the right Arduino board selected.
        - Check to make sure you have the correct port selected
        - The Receive (RX) and Transmit (TX) pins on the Arduino (pins 0 and 1) are used when uploading sketches on your Arduino board. If you have any connections to those pins, pull them out before you upload to the board.
        - If you have an Arduino shield attached to your Arduino board, remove the shield and try uploading again