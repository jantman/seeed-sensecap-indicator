# seeed-sensecap-indicator

Software related to the Seeed Studio SenseCap Indicator

This serves mostly as a place to store a persistent backup of everything needed to make these work nicely with HomeAssistant, including reading the RP2040 data.

* [wiki/](wiki/) - A backup of the [SenseCAP_Indicator section of the Seeed Studio wiki](https://wiki.seeedstudio.com/Sensor/SenseCAP/SenseCAP_Indicator/Get_started_with_SenseCAP_Indicator/), which contains a lot of information about development, flashing, etc.
* [SenseCAP_Indicator_RP2040-main/](SenseCAP_Indicator_RP2040-main/) - Archive of https://github.com/Seeed-Solution/SenseCAP_Indicator_RP2040/tree/a8625ebc09306fc50998e451b67aa6f97d0c1199
* [sensecap-indicator-rp2040-extended/](sensecap-indicator-rp2040-extended/) - Archive of https://github.com/tobi1449/sensecap-indicator-rp2040-extended as of [5ff29ef936afa53c4f493a2600f74b7f5543bb47](https://github.com/tobi1449/sensecap-indicator-rp2040-extended/tree/5ff29ef936afa53c4f493a2600f74b7f5543bb47), found via https://github.com/Seeed-Solution/SenseCAP_Indicator_ESP32/discussions/35#discussioncomment-11312786
* [arduino-pico/](arduino-pico/) - Archive of https://github.com/earlephilhower/arduino-pico/tree/5296241949f66d138af95cd780050a3e3ffbabcb for RP2040 support in Arduino IDE.

## RP2040 Build and Flash

1. Open Ardunio IDE. Go to `File` -> `Preferences`, in the `Additional boards manager URLs` enter https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json (this is also backed up in this repo). Click OK.
2. Click into `Tools` -> `Boards` -> `Boards Manager` to bring up the Boards Manager sidebar. Type `indicator` in the search box to bring up `Raspberry Pi Pico/RP2040/RP2350 by Earle F. Philhower, III` and install version 4.4.1; wait for the installation to finish.
3. Click into `Tools` -> `Manage Libraries` to bring up the Library Manager sidebar and install the following libraries (which are also archived under [libraries/](libraries/)):
    * [Seeed_Arduino_AHT20](https://github.com/Seeed-Studio/Seeed_Arduino_AHT20) version 1.0.1
    * [Sensirion Gas Index Algorithm](https://github.com/Sensirion/arduino-gas-index-algorithm) version 3.2.3
    * [Sensirion I2C SCD4x](https://github.com/Sensirion/arduino-i2c-scd4x) version 0.4.0
    * [Sensirion I2C SGP40](https://github.com/Sensirion/arduino-i2c-sgp40) version 0.1.0
    * [PacketSerial](https://github.com/bakercp/PacketSerial) version 1.4.0
    * [Sensirion Core](https://github.com/Sensirion/arduino-core) version 0.7.1
