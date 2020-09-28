# Daisy Pod Display
Arduino-based display for the [Daisy Pod](https://www.electro-smith.com/daisy/pod) controlled by the pod's RGB LEDs. Supposing the application running on the Daisy uses the pod's RGB LEDs for status indication, this sketch lets you attach human-readable text displayed on an alphanumerical LCD connected to an Arduino Uno. Also captures potentiometers POT1 & POT2.

Default sketch has the menu's for [HammondEggsMusic's Pollen(8) synthesizer](https://hammondeggsmusic.ca/daisy/pollen8.html).

Connections:

Daisy -> Arduino
----------------
27 (led1_r) -> 8

26 (led1_g) -> 9

25 (led1_b) -> 10

24 (led2_r) -> 11

31 (led2_g) -> 12

30 (led2_b) -> 13

28 (pot_1) -> A0

22 (pot_2) -> A1

40 (GND) -> GND

LCD -> Arduino
--------------
E -> 7

RS -> 6

D4 -> 5

D5 -> 4

D6 -> 3

D7 -> 2
