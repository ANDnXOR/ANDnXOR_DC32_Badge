# Flashing #

1. Put badge into bootloader mode.
2. Copy doom_tiny_nibbler.uf2 to RP2-RPI drive
3. Put badge back into bootloader mode (hold bootsel during reset)
4. Flash doom wad `picotool load -v  -t bin doom1.whx -o 0x10060000`
