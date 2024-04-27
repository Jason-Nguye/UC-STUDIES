#!/usr/bin/env python3
from ev3dev2.motor import *
from ev3dev2.sound import *

# Initialize the motors
motor_left = LargeMotor(OUTPUT_A)
motor_right = LargeMotor(OUTPUT_D)

#tweleve=(12/(7.775))


tank_drive = MoveTank(OUTPUT_A,OUTPUT_D)
speed1 = SpeedPercent(25) #OUTPUTA RIGHT
speed2 = SpeedPercent(24.83) #OUTPUTD LEFT
tank_drive.on_for_rotations( speed1, speed2, (-1))