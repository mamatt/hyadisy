EESchema Schematic File Version 2  date mer. 08 janv. 2014 18:39:42 CET
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:microchip_additionnel
LIBS:device_additionnel
LIBS:synth-cache
EELAYER 25  0
EELAYER END
$Descr A4 11700 8267
encoding utf-8
Sheet 1 1
Title ""
Date "8 jan 2014"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
NoConn ~ 5650 4800
NoConn ~ 8450 3550
NoConn ~ 7200 3950
Wire Wire Line
	7250 4150 7200 4150
Wire Wire Line
	7200 4150 7200 4050
Wire Bus Line
	7100 4150 7100 3400
Wire Bus Line
	7100 3400 3400 3400
Wire Wire Line
	7350 2950 7350 3150
Connection ~ 7350 3150
Connection ~ 8800 4150
Wire Wire Line
	8450 4150 8800 4150
Wire Wire Line
	8450 3750 8800 3750
Wire Wire Line
	4250 4200 4000 4200
Wire Wire Line
	4000 4200 4000 3950
Wire Wire Line
	4000 3950 3300 3950
Wire Wire Line
	1400 3250 1400 3550
Wire Wire Line
	1100 5550 1100 5450
Wire Wire Line
	3650 1050 4500 1050
Wire Wire Line
	4500 1850 3650 1850
Connection ~ 4100 1450
Wire Wire Line
	3250 1450 4500 1450
Connection ~ 3750 1050
Connection ~ 4100 1850
Connection ~ 3750 1850
Wire Wire Line
	3650 1850 3650 1800
Wire Wire Line
	3250 1500 3250 1350
Wire Wire Line
	1550 800  1550 750 
Wire Wire Line
	1550 750  1500 750 
Wire Wire Line
	1600 1700 1600 1550
Wire Wire Line
	1600 1550 1650 1550
Wire Wire Line
	2850 2200 2850 2350
Wire Wire Line
	1100 1800 1650 1800
Wire Wire Line
	4500 1050 4500 1000
Wire Wire Line
	1650 1300 1100 1300
Wire Wire Line
	1100 1300 1100 1400
Wire Wire Line
	1650 1050 1650 750 
Wire Wire Line
	1650 750  2850 750 
Wire Wire Line
	2850 750  2850 1050
Wire Wire Line
	1500 1000 1650 1000
Connection ~ 1650 1000
Connection ~ 3250 1450
Connection ~ 4100 1050
Connection ~ 3750 1450
Wire Wire Line
	4500 1450 4500 1550
Wire Wire Line
	1400 5550 1400 5450
Wire Wire Line
	1400 5450 1100 5450
Wire Wire Line
	3300 3850 4000 3850
Wire Wire Line
	4000 3850 4000 3600
Wire Wire Line
	4000 3600 4250 3600
Wire Bus Line
	3400 3400 3400 3650
Wire Wire Line
	8800 3750 8800 4300
Wire Wire Line
	8450 3950 8700 3950
Wire Wire Line
	8700 3950 8700 3150
Wire Wire Line
	8700 3150 7250 3150
Wire Wire Line
	7250 3150 7250 3550
Wire Wire Line
	7250 3750 7000 3750
Wire Wire Line
	7000 3750 7000 4300
Wire Wire Line
	7000 4300 3300 4300
Wire Wire Line
	7200 3850 7250 3850
Wire Wire Line
	7250 3850 7250 3950
Entry Wire Line
	7100 4050 7200 3950
Entry Wire Line
	7100 3950 7200 3850
Entry Wire Line
	7100 4150 7200 4050
$Comp
L VDD #PWR01
U 1 1 52CD8CB3
P 7350 2950
F 0 "#PWR01" H 7350 3050 30  0001 C CNN
F 1 "VDD" H 7350 3060 30  0000 C CNN
	1    7350 2950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 52CD8C92
P 8800 4300
F 0 "#PWR02" H 8800 4300 30  0001 C CNN
F 1 "GND" H 8800 4230 30  0001 C CNN
	1    8800 4300
	1    0    0    -1  
$EndComp
$Comp
L MCP4921 DAC1
U 1 1 52CD8C21
P 7850 3900
F 0 "DAC1" H 7650 3450 60  0000 C CNN
F 1 "MCP4921" H 7850 4400 60  0000 C CNN
	1    7850 3900
	1    0    0    -1  
$EndComp
Entry Wire Line
	3300 3550 3400 3450
Entry Wire Line
	3300 3650 3400 3550
NoConn ~ 3300 4850
NoConn ~ 3300 4950
Entry Wire Line
	3300 3750 3400 3650
NoConn ~ 3300 3350
NoConn ~ 3300 3250
NoConn ~ 3300 3450
NoConn ~ 3300 5550
NoConn ~ 3300 5450
NoConn ~ 3300 5350
NoConn ~ 3300 5250
NoConn ~ 3300 5150
NoConn ~ 3300 5050
NoConn ~ 3300 4700
NoConn ~ 3300 4600
NoConn ~ 3300 4500
NoConn ~ 3300 4400
NoConn ~ 3300 4200
NoConn ~ 3300 4100
$Comp
L CRYSTAL X1
U 1 1 52CD7F7E
P 4250 3900
F 0 "X1" H 4250 4050 60  0000 C CNN
F 1 "CRYSTAL" H 4250 3750 60  0000 C CNN
	1    4250 3900
	0    -1   -1   0   
$EndComp
NoConn ~ 1400 3850
$Comp
L VDD #PWR03
U 1 1 52CD7C21
P 1400 3250
F 0 "#PWR03" H 1400 3350 30  0001 C CNN
F 1 "VDD" H 1400 3360 30  0000 C CNN
	1    1400 3250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 52CD7BFA
P 1100 5550
F 0 "#PWR04" H 1100 5550 30  0001 C CNN
F 1 "GND" H 1100 5480 30  0001 C CNN
	1    1100 5550
	1    0    0    -1  
$EndComp
$Comp
L ATMEGA328-P IC1
U 1 1 52CD7BC9
P 2300 4350
F 0 "IC1" H 1600 5600 50  0000 L BNN
F 1 "ATMEGA328-P" H 2550 2950 50  0000 L BNN
F 2 "DIL28" H 1700 3000 50  0001 C CNN
	1    2300 4350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR05
U 1 1 52CD746E
P 4500 1550
F 0 "#PWR05" H 4500 1550 30  0001 C CNN
F 1 "GND" H 4500 1480 30  0001 C CNN
	1    4500 1550
	1    0    0    -1  
$EndComp
$Comp
L POWER_JACK J1
U 1 1 52CD6767
P 1050 900
F 0 "J1" H 700 700 60  0000 C CNN
F 1 "POWER_JACK" H 950 1150 60  0000 C CNN
	1    1050 900 
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR06
U 1 1 52CD6652
P 1550 800
F 0 "#PWR06" H 1550 800 30  0001 C CNN
F 1 "GND" H 1550 730 30  0001 C CNN
	1    1550 800 
	1    0    0    -1  
$EndComp
NoConn ~ 2850 1550
NoConn ~ 2850 1300
$Comp
L TC962 DC1
U 1 1 52CD63AA
P 2250 1400
F 0 "DC1" H 2250 800 60  0000 C CNN
F 1 "TC962" H 2250 1900 60  0000 C CNN
	1    2250 1400
	1    0    0    -1  
$EndComp
$Comp
L VEE #PWR8
U 1 1 52CD3C25
P 4500 1850
F 0 "#PWR8" H 4500 2050 40  0001 C CNN
F 1 "VEE" H 4500 2000 40  0000 C CNN
	1    4500 1850
	-1   0    0    1   
$EndComp
$Comp
L VDD #PWR07
U 1 1 52CD3C15
P 4500 1000
F 0 "#PWR07" H 4500 1100 30  0001 C CNN
F 1 "VDD" H 4500 1110 30  0000 C CNN
	1    4500 1000
	1    0    0    -1  
$EndComp
$Comp
L CP1 C6
U 1 1 52CD304C
P 4100 1650
F 0 "C6" H 3900 1750 50  0000 L CNN
F 1 "470uF" H 3850 1550 50  0000 L CNN
	1    4100 1650
	-1   0    0    -1  
$EndComp
$Comp
L CP1 C5
U 1 1 52CD3049
P 4100 1250
F 0 "C5" H 4150 1350 50  0000 L CNN
F 1 "470uF" H 4150 1150 50  0000 L CNN
	1    4100 1250
	1    0    0    -1  
$EndComp
$Comp
L CP1 C3
U 1 1 52CD2F86
P 3750 1250
F 0 "C3" H 3800 1350 50  0000 L CNN
F 1 "10uF" H 3800 1150 50  0000 L CNN
	1    3750 1250
	1    0    0    -1  
$EndComp
$Comp
L CP1 C4
U 1 1 52CD2F76
P 3750 1650
F 0 "C4" H 3800 1750 50  0000 L CNN
F 1 "10uF" H 3550 1550 50  0000 L CNN
	1    3750 1650
	-1   0    0    -1  
$EndComp
$Comp
L 7905 U2
U 1 1 52CD2E76
P 3250 1750
F 0 "U2" H 3400 1555 60  0000 C CNN
F 1 "7905" H 3250 1950 60  0000 C CNN
	1    3250 1750
	1    0    0    1   
$EndComp
$Comp
L 7805 U1
U 1 1 52CD2E61
P 3250 1100
F 0 "U1" H 3400 904 60  0000 C CNN
F 1 "7805" H 3250 1300 60  0000 C CNN
	1    3250 1100
	1    0    0    -1  
$EndComp
$Comp
L CP1 C1
U 1 1 52CD2D25
P 1100 1600
F 0 "C1" H 1150 1700 50  0000 L CNN
F 1 "10uF" H 1150 1500 50  0000 L CNN
	1    1100 1600
	1    0    0    -1  
$EndComp
$Comp
L CP1 C2
U 1 1 52CD2CC7
P 2850 2000
F 0 "C2" H 2900 2100 50  0000 L CNN
F 1 "10uF" H 2900 1900 50  0000 L CNN
	1    2850 2000
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR08
U 1 1 52CD2CA3
P 2850 2350
F 0 "#PWR08" H 2850 2350 30  0001 C CNN
F 1 "GND" H 2850 2280 30  0001 C CNN
	1    2850 2350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR09
U 1 1 52CD284B
P 1600 1700
F 0 "#PWR09" H 1600 1700 30  0001 C CNN
F 1 "GND" H 1600 1630 30  0001 C CNN
	1    1600 1700
	1    0    0    -1  
$EndComp
$EndSCHEMATC