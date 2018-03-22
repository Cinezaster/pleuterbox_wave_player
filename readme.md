# Pleuterbox wave player

This is the source code for the "Pleuterbox" music player. 
Pleuterbox is a project from [Culturegem](http://www.cultureghem.be/) 

## Project goal

Make a music player, based on 3 old toggle switches. By toggling the switches the little kids can listen to 7 different songs.

## Bill Of Material

- Arduino UNO
- [Adafruit Wave shield](https://www.adafruit.com/product/94)
- [220V AC --> 12V DC 10A](https://www.banggood.com/AC-220V-To-DC-12V-10A-120W-Power-Supply-Lighting-Transformer-Adapter-Driver-For-Strip-Light-Lamp-p-1145387.html?rmmds=search)
- [DC - DC adjustable converter 12V --> 7,5V](https://www.aliexpress.com/item/XL6009-DC-Adjustable-Step-up-boost-Power-Converter-Module-Replace-LM2577/32636472543.html)
- [XH-M181 2x15Watt amplifier](https://www.aliexpress.com/item/OriginalChip-PAM8610-XH-M181-Digital-Micropower-Amplifier-Board-High-Power-Amplifier-Module-Class-D-Dual-2x15W/32791023825.html)
- speaker
- Wires
- 3 x (Retro) Toggle switches

## connection diagram

- power source 12V --> Amp +12V
- power source GND --> Amp GND
- power source 12V --> DC-DC converter +IN
- power source GND --> DC-DC converter -IN
- DC-DC converter +OUT --> Arduino VIN
- DC-DC converter -OUT --> Arduino GND
- A0 --> SWITCHO1 <-- GND
- A1 --> SWITCHO2 <-- GND
- A2 --> SWITCHO3 <-- GND
- Wave Shield AUDIO OUT GND --> Amp (between L_IN & R_IN)
- Wave Shield AUDIO OUT LEFT --> Amp L_IN
- Wave Shield AUDIO OUT LEFT --> Amp R_IN
- Amp L+ --> Speaker +
- Amp L- --> Speaker -

