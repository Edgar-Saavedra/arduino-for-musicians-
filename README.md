## arduino-cli
- [compiling](https://arduino.github.io/arduino-cli/latest/commands/arduino-cli_compile/)
    - `$ arduino-cli compile -b arduino:avr:uno /home/user/Arduino/MySketch`
- [uploading](https://arduino.github.io/arduino-cli/latest/commands/arduino-cli_upload/)
    - `$  arduino-cli upload /home/user/Arduino/MySketch`
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

