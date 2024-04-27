#!/usr/bin/env python3
from ev3dev2.motor import *
from ev3dev2.sound import Sound
from time import sleep

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
speed2 = SpeedPercent(25)#OUTPUTD LEFT

#For loop
for k in range(laps*2):
    tank_drive.on_for_rotations( speed1, speed2, -rotations)
    

    sound.speak('Turning')
   

    tank_drive.on_for_degrees(left_speed=SpeedPercent(24.83), right_speed=SpeedPercent(-25), degrees=360)
    



sound.speak("Marty is done")
