# PEE50_CTG
PEE50 school project for creating a simple basic cardiotocograph with a STM32L476RG Microcontroller.

## first iteration
This project is the first iteration of a basic cardiototocograph. It will only measure heart rate and the respitory rate of a patient.

## target audience
This repository is meant for future PEE50 students who have to further develop the cardiotocograph or people that need an example on how to implement 
the following modules in an STM32 micro controller.

modules implemented:
- UART  :heart rate and respitory rate will be send via uart to the user
- TIMER :execute ADC en DAC code at a specific intervals. 
- GPIO  :user has to be able to switch between respitory and hear rate.
- DAC   :100Khz 0-3.3V sine wave for the respitory hardware.
- ADC   :1000Hz sampel rate ADC for heartrate and respitory rate.
- DMA   :transfering data between memory and DAC peripheral. 


