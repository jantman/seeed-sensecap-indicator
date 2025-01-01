# seeed-sensecap-indicator

Software related to the Seeed Studio SenseCap Indicator

This serves mostly as a place to store a persistent backup of everything needed to make these work nicely with HomeAssistant, including reading the RP2040 data.

See also: https://github.com/Seeed-Solution/SenseCAP_Indicator_ESP32/discussions/35#discussioncomment-11312786

* [wiki/](wiki/) - A backup of the [SenseCAP_Indicator section of the Seeed Studio wiki](https://wiki.seeedstudio.com/Sensor/SenseCAP/SenseCAP_Indicator/Get_started_with_SenseCAP_Indicator/), which contains a lot of information about development, flashing, etc.
* [SenseCAP_Indicator_RP2040-main/](SenseCAP_Indicator_RP2040-main/) - Archive of https://github.com/Seeed-Solution/SenseCAP_Indicator_RP2040/tree/a8625ebc09306fc50998e451b67aa6f97d0c1199
* [sensecap-indicator-rp2040-extended/](sensecap-indicator-rp2040-extended/) - Archive of https://github.com/tobi1449/sensecap-indicator-rp2040-extended as of [5ff29ef936afa53c4f493a2600f74b7f5543bb47](https://github.com/tobi1449/sensecap-indicator-rp2040-extended/tree/5ff29ef936afa53c4f493a2600f74b7f5543bb47), found via https://github.com/Seeed-Solution/SenseCAP_Indicator_ESP32/discussions/35#discussioncomment-11312786
* [arduino-pico/](arduino-pico/) - Archive of https://github.com/earlephilhower/arduino-pico/tree/5296241949f66d138af95cd780050a3e3ffbabcb for RP2040 support in Arduino IDE.
* [esphome-sensecap-indicator-sensors/](esphome-sensecap-indicator-sensors/) - Archive of https://github.com/tobi1449/esphome-sensecap-indicator-sensors as of [08e62eecdd8a72e51628c57a1709bbe519757d95](https://github.com/tobi1449/esphome-sensecap-indicator-sensors/tree/08e62eecdd8a72e51628c57a1709bbe519757d95)

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
4. Compile: `cd sensecap-indicator-rp2040-extended/indicator_rp2040 && rduino-cli compile -b rp2040:rp2040:seeed_indicator_rp2040 --output-dir build .`
    ```
    $ arduino-cli compile -b rp2040:rp2040:seeed_indicator_rp2040 --output-dir build .
    Sketch uses 110380 bytes (5%) of program storage space. Maximum is 2093056 bytes.
    Global variables use 11568 bytes (4%) of dynamic memory, leaving 250576 bytes for local variables. Maximum is 262144 bytes.

    Used library                  Version Path
    Sensirion I2C SGP40           0.1.0   /home/jantman/Arduino/libraries/Sensirion_I2C_SGP40
    Wire                          1.0     /home/jantman/.arduino15/packages/rp2040/hardware/rp2040/4.4.1/libraries/Wire
    Sensirion Core                0.7.1   /home/jantman/Arduino/libraries/Sensirion_Core
    Sensirion I2C SCD4x           0.4.0   /home/jantman/Arduino/libraries/Sensirion_I2C_SCD4x
    Sensirion Gas Index Algorithm 3.2.3   /home/jantman/Arduino/libraries/Sensirion_Gas_Index_Algorithm
    SPI                           1.0     /home/jantman/.arduino15/packages/rp2040/hardware/rp2040/4.4.1/libraries/SPI
    SD                            2.0.0   /home/jantman/.arduino15/packages/rp2040/hardware/rp2040/4.4.1/libraries/SD
    SDFS                          0.1.0   /home/jantman/.arduino15/packages/rp2040/hardware/rp2040/4.4.1/libraries/SDFS
    ESP8266SdFat                  2.2.2   /home/jantman/.arduino15/packages/rp2040/hardware/rp2040/4.4.1/libraries/ESP8266SdFat
    PacketSerial                  1.4.0   /home/jantman/Arduino/libraries/PacketSerial
    Seeed_Arduino_AHT20           1.0.1   /home/jantman/Arduino/libraries/Seeed_Arduino_AHT20

    Used platform Version Path
    rp2040:rp2040 4.4.1   /home/jantman/.arduino15/packages/rp2040/hardware/rp2040/4.4.1
    jantman@myprecious::~/GIT/seeed-sensecap-indicator/sensecap-indicator-rp2040-extended/indicator_rp2040 (main *%>)$ ls -lh build/
    total 5.2M
    -rwxr-xr-x 1 jantman jantman 125K Jan  1 10:26 indicator_rp2040.ino.bin
    -rwxr-xr-x 1 jantman jantman 2.9M Jan  1 10:26 indicator_rp2040.ino.elf
    -rw-r--r-- 1 jantman jantman 1.9M Jan  1 10:26 indicator_rp2040.ino.map
    -rw-r--r-- 1 jantman jantman 250K Jan  1 10:26 indicator_rp2040.ino.uf2
    ```
5. **TBD** Upload/flash - see https://wiki.seeedstudio.com/SenseCAP_Indicator_How_To_Flash_The_Default_Firmware/#for-rp2040

## ESP32 / ESPHome

Configure your device something like:

```
external_components:
  - source:
      type: git
      url: https://github.com/jantman/seeed-sensecap-indicator
      ref: main
      path: esphome-sensecap-indicator-sensors/components/
    components: [ rtttl, dfplayer ]

sensor:
  - platform: sensecap_indicator_sensors
    co2:
      name: "CO2 (SCD41)"
    altitude: 405
    tvoc:
      name: "TVOC (SGP40)"
    temperature_internal:
      name: "Temperature Internal (SCD41)"
    humidity_internal:
      name: "Humidity Internal (SCD41)"
```

## Other References

* [Love4yzp/sensecap-indicator-ha: The use of SenseCAP indicator interacts with Home Assistant in three API methods](https://github.com/Love4yzp/sensecap-indicator-ha)
* [SenseCAP\_Indicator\_ESP32/examples/indicator\_ha at main · Seeed-Solution/SenseCAP\_Indicator\_ESP32](https://github.com/Seeed-Solution/SenseCAP_Indicator_ESP32/tree/main/examples/indicator_ha)

