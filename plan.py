#!/usr/bin/env python3
from ev3dev2.motor import *
from ev3dev2.sound import *

# Initialize the motors
motor_left = LargeMotor(OUTPUT_A)
motor_right = LargeMotor(OUTPUT_D)
motor_arm = Motor(OUTPUT_C)

arm_speed = 25

motor_arm.on_for_degrees(arm_speed, -1200)
