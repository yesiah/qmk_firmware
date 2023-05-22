# yesiah

## Corne Keyboard (CRKBD) layout

1. Mac/Win dual system user
1. Vim user
1. Programmer

## Build

`qmk compile -kb crkbd -km yesiah`

Alternatively, `make crkbd:yesiah`

The output will be at `~/qmk_firmware/crkbd_rev1_yesiah.hex`

## Handedness

I use [Handedness by EEPROM](https://docs.qmk.fm/#/feature_split_keyboard?id=handedness-by-eeprom).

## Flashing

Use QMK Toolbox to flash both hands separately.

1. Open QMK Tookbox
1. Plug in the left half of the keyboard
1. Press the physical reset button twice to reset the keyboard
1. Select Tool -> EEPROM -> Set Left Hand Side (or similar wording), and wait until finish
1. Flash
1. Do the same for the right half

## Layers

TODO (maybe not)
