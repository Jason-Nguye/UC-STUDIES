#!/usr/bin/env python3
from ev3dev2.motor import *
from ev3dev2.sound import *

# Initialize the motors
motor_left = LargeMotor(OUTPUT_A)
motor_right = LargeMotor(OUTPUT_D)

# Initialize sound
sound = Sound()

# Play a sound before starting
sound.speak('Starting')

# Get inputs
distance = float(input("Enter the total distance"))
laps = int(input("Enter the amount of laps"))

rotations= (distance/(19.75)) #CM

# Declare Varibles
tank_drive = MoveTank(OUTPUT_A,OUTPUT_D)
speed1 = SpeedPercent(25)#OUTPUTA RIGHT
speed2 = SpeedPercent(24.83)#OUTPUTD LEFT
#For loop
for k in range(laps):
    tank_drive.on_for_rotations( speed1, speed2, (-rotations))
    tank_drive.on_for_rotations( speed1, speed2, (rotations*.9))

