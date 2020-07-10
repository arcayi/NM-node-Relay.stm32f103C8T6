# NM-node-Relay.stm32f103C8T6
## Prepare uploading by usb
1. programming the bootloader through st-link:

    https://github.com/rogerclarkmelbourne/STM32duino-bootloader/blob/master/binaries/generic_boot20_pc13.bin

2. install maple dfu drivers

    [Arduino sketches]\Arduino_STM32\drivers\win\install_drivers.bat

    [Arduino sketches]\Arduino_STM32\drivers\win\install_STM_COM_drivers.bat

## Hardware wiring

[MySensors](https://github.com/mysensors/MySensors/)\hal\architecture\STM32F1\MyHwSTM32F1.cpp
Wiring RF24 radio / SPI1
RF24 pin|STM32F1 pin
--------|------------
CLK     |	PA5
MISO	|   PA6
MOSI	|   PA7
CSN	    |   PA4
CE	    |   PB0 (default)
IRQ	    |   NA

![wiring of STM32F1 and NRF24](schematics/mysensors.STM32F103%20bluepill+RF24接线图.png?raw=true "wiring of STM32F1 and NRF24")

## Dependencies
### development
- MySensors NodeManager by user2684 Version 1.8.0 INSTALLED(development branch e9c50ab by arcayi)
- MySensors by The MySensors Team Version 2.3.2 INSTALLED
- STM32F1xx/GD32F1xx boards by stm32duino Version 2020.6.20 INSTALLED
