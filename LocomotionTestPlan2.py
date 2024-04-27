#!/usr/bin/env python3


from ev3dev2.motor import *
from ev3dev2.sound import *


motor_left = LargeMotor(OUTPUT_A)
motor_right = LargeMotor(OUTPUT_D)
tank_drive = MoveTank(OUTPUT_A,OUTPUT_D)
speed1 = SpeedPercent(25) #OUTPUTA RIGHT
speed2 = SpeedPercent(24.83) #OUTPUTD LEFT
distance = int(input("Input Distance"))

rotations= (distance/(10.5)) #INCHES
tank_drive.on_for_rotations( speed1, speed2, (-12/10.5))
tank_drive.on_for_degrees(left_speed=SpeedPercent(50), right_speed=SpeedPercent(-50), degrees=1100)
tank_drive.on_for_rotations( speed1, speed2, (-96/10.5))
