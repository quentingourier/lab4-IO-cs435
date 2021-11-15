/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

//Define the PWM speaker output
PwmOut speaker(PB_10);

//Define analog inputs
AnalogIn potR(PA_0); //freq
AnalogIn potG(PA_1); //vol

//Define variables
float pitch, volume;

//320 hz to 8khz <=> 0.003125s to 0.000125s (diff of 0.003)

int main()
{
    while(1){
        pitch = potR.read(); //[0.0 to 1.0] freq
        volume = potG.read(); //[0.0 to 1.0] vol
        
        for(float i=0; i<1.0; i+= 0.01){

            float freq = (0.003125-(0.003*pitch));
            speaker.period(freq);

            speaker = (1-volume)*i;
        }
        
    }
}
