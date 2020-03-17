EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 8268 11693 portrait
encoding utf-8
Sheet 1 1
Title "Sistema de vibracion "
Date "2020-03-15"
Rev ""
Comp "Ojo de Van Gogh"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L VIbrador-rescue:HC-05-Modulos U?
U 1 1 5E6EC1C3
P 5000 2200
F 0 "U?" V 5074 2338 50  0000 L CNN
F 1 "HC-05" V 5165 2338 50  0000 L CNN
F 2 "" H 5000 2200 50  0001 C CNN
F 3 "" H 5000 2200 50  0001 C CNN
	1    5000 2200
	0    1    1    0   
$EndComp
$Comp
L VIbrador-rescue:Pila3,7V-Modulos U?
U 1 1 5E6ECDF3
P 2900 1550
F 0 "U?" H 2950 1765 50  0000 C CNN
F 1 "Pila3,7V" H 2950 1674 50  0000 C CNN
F 2 "" H 2900 1550 50  0001 C CNN
F 3 "" H 2900 1550 50  0001 C CNN
	1    2900 1550
	1    0    0    -1  
$EndComp
Text GLabel 2600 1750 3    50   Input ~ 0
VIN
Text GLabel 3300 1750 3    50   Input ~ 0
GND
Wire Wire Line
	3300 1750 3300 1600
Wire Wire Line
	3300 1600 3200 1600
Wire Wire Line
	2700 1600 2600 1600
Wire Wire Line
	2600 1600 2600 1750
Text GLabel 2350 3750 3    50   Input ~ 0
VIN
Wire Wire Line
	2450 3700 2350 3700
Wire Wire Line
	2350 3700 2350 3750
Text GLabel 2000 3600 0    50   Input ~ 0
GND
Text GLabel 4750 2900 3    50   Input ~ 0
TX
Text GLabel 4850 2900 3    50   Input ~ 0
RX
$Comp
L VIbrador-rescue:Buzzer-Modulos U?
U 1 1 5E6F1D29
P 4850 3500
F 0 "U?" H 4900 3350 50  0000 C CNN
F 1 "Buzzer" H 4900 3450 50  0000 C CNN
F 2 "" H 4850 3500 50  0001 C CNN
F 3 "" H 4850 3500 50  0001 C CNN
	1    4850 3500
	-1   0    0    1   
$EndComp
Text GLabel 4500 3650 3    50   Input ~ 0
D9
Wire Wire Line
	4600 3550 4500 3550
Wire Wire Line
	4500 3550 4500 3650
Text GLabel 4500 3250 1    50   Input ~ 0
GND
Wire Wire Line
	4500 3350 4500 3250
Wire Wire Line
	4500 3350 4600 3350
Text GLabel 5050 2900 3    50   Input ~ 0
VIN
Text GLabel 4950 2900 3    50   Input ~ 0
GND
Text GLabel 3700 2400 2    50   Input ~ 0
TX
$Comp
L VIbrador-rescue:ArduinoNANO-Modulos U?
U 1 1 5E6EAAF3
P 3100 2700
F 0 "U?" V 2475 2375 50  0000 C CNN
F 1 "ArduinoNANO" V 2566 2375 50  0000 C CNN
F 2 "" H 3100 2700 50  0001 C CNN
F 3 "" H 3100 2700 50  0001 C CNN
	1    3100 2700
	0    1    1    0   
$EndComp
Wire Wire Line
	3250 2400 3350 2400
Wire Wire Line
	3600 2400 3700 2400
Text GLabel 3700 2500 2    50   Input ~ 0
RX
Text GLabel 3700 2600 2    50   Input ~ 0
D9
Wire Wire Line
	3600 2400 3600 2450
Wire Wire Line
	3600 2450 3350 2450
Wire Wire Line
	3350 2450 3350 2400
Wire Wire Line
	3350 2500 3350 2550
Wire Wire Line
	3350 2550 3600 2550
Wire Wire Line
	3600 2550 3600 2500
Wire Wire Line
	3600 2500 3700 2500
Wire Wire Line
	3700 2600 3600 2600
Wire Wire Line
	3600 2600 3600 2650
Wire Wire Line
	3600 2650 3350 2650
Wire Wire Line
	3350 2650 3350 2600
Wire Wire Line
	3350 2600 3250 2600
Wire Wire Line
	3250 2500 3350 2500
Wire Wire Line
	2450 3600 2350 3600
Wire Wire Line
	2350 3600 2350 3650
Wire Wire Line
	2350 3650 2100 3650
Wire Wire Line
	2100 3650 2100 3600
Wire Wire Line
	2100 3600 2000 3600
Wire Wire Line
	4750 2550 4750 2650
Wire Wire Line
	4750 2650 4800 2650
Wire Wire Line
	4800 2650 4800 2800
Wire Wire Line
	4800 2800 4750 2800
Wire Wire Line
	4750 2800 4750 2900
Wire Wire Line
	4850 2900 4850 2800
Wire Wire Line
	4850 2800 4900 2800
Wire Wire Line
	4900 2800 4900 2650
Wire Wire Line
	4900 2650 4850 2650
Wire Wire Line
	4850 2650 4850 2550
Wire Wire Line
	4950 2550 4950 2650
Wire Wire Line
	4950 2650 5000 2650
Wire Wire Line
	5000 2650 5000 2850
Wire Wire Line
	5000 2850 4950 2850
Wire Wire Line
	4950 2850 4950 2900
Wire Wire Line
	5050 2550 5050 2650
Wire Wire Line
	5050 2650 5100 2650
Wire Wire Line
	5100 2650 5100 2850
Wire Wire Line
	5100 2850 5050 2850
Wire Wire Line
	5050 2850 5050 2900
$EndSCHEMATC
