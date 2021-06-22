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

## Troubleshooting
- Some ports have issues uploading; disconnect and reconnect; reset button; make sure correct "Fully Qualified Board Name" (fqbn); Make sure correct port (`$ arduino-cli board list`); pin `A0` connected can give issues.