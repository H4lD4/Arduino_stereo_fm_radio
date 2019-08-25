# Arduino_stereo_fm_radio
Simple Arduino stereo FM receiver using modul TEA 5767

# Components
1. Arduino UNO
2. TEA5767 (FM Stereo Radio Module)
3. 16 X 2 LCD Display
4. 1 kΩ Potentiometer to set the frequency
5. 10 kΩ Trimr to set the display contrast
6. 2 kΩ Trimr to set up the display brightness
7. 150 Ω resistor
8. Breadboard
9. Speaker

# Code
TEA 5767 does not support RDS, so in code you will find function printStationName(). This function should simulate RDS and you have to update it based on location where you are to see your favourite stations.
