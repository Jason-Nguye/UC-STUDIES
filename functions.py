#!/usr/bin/env python3

from ev3dev2.motor import *
from ev3dev2.sound import *
from ev3dev2.sensor.lego import *
from ev3dev2.sensor import *
from ev3dev2.display import *
import time
def move(distance):
    # Initialize the motors
    motor_left = LargeMotor(OUTPUT_A)
    motor_right = LargeMotor(OUTPUT_D)


    rotations= (distance/11) #INCHES

    # Declare Varibles
    tank_drive = MoveTank(OUTPUT_A,OUTPUT_D)
    speed1 = SpeedPercent(24.5) #OUTPUTA RIGHT
    speed2 = SpeedPercent(25) #OUTPUTD LEFT
    tank_drive.on_for_rotations( speed1, speed2, (-rotations))

def turnright():
    motor_left = LargeMotor(OUTPUT_A)
    motor_right = LargeMotor(OUTPUT_D)
    tank_drive = MoveTank(OUTPUT_A,OUTPUT_D)
    speed1 = SpeedPercent(25)#OUTPUTA RIGHT
    speed2 = SpeedPercent(25)#OUTPUTD LEFT
    tank_drive.on_for_degrees(left_speed=SpeedPercent(20), right_speed=SpeedPercent(-20), degrees=170)   


def turnleft():
    motor_left = LargeMotor(OUTPUT_A)
    motor_right = LargeMotor(OUTPUT_D)
    tank_drive = MoveTank(OUTPUT_A,OUTPUT_D)
    speed1 = SpeedPercent(25)#OUTPUTA RIGHT
    speed2 = SpeedPercent(25)#OUTPUTD LEFT
    tank_drive.on_for_degrees(left_speed=SpeedPercent(-20), right_speed=SpeedPercent(20), degrees=230) 
def turn180():
    motor_left = LargeMotor(OUTPUT_A)
    motor_right = LargeMotor(OUTPUT_D)
    tank_drive = MoveTank(OUTPUT_A,OUTPUT_D)
    speed1 = SpeedPercent(25)#OUTPUTA RIGHT
    speed2 = SpeedPercent(25)#OUTPUTD LEFT
    tank_drive.on_for_degrees(left_speed=SpeedPercent(20), right_speed=SpeedPercent(-20), degrees=365) 
def turndeg(degree):
    motor_left = LargeMotor(OUTPUT_A)
    motor_right = LargeMotor(OUTPUT_D)
    tank_drive = MoveTank(OUTPUT_A,OUTPUT_D)
    speed1 = SpeedPercent(25)#OUTPUTA RIGHT
    speed2 = SpeedPercent(25)#OUTPUTD LEFT
    tank_drive.on_for_degrees(left_speed=SpeedPercent(20), right_speed=SpeedPercent(-20), degrees=degree)
def arm(degree):
    motor_arm = Motor(OUTPUT_C)
    arm_speed = 100
    motor_arm.on_for_degrees(arm_speed, degree)    

def scan():
    colorscan = ColorSensor(INPUT_3)
    boxtype = 0 
    
    if colorscan.color == 1:
        boxtype += 1
        
    move(.7) 
    sleep(1)
    if colorscan.color == 1:
        #BOXTYPE 3
        boxtype += 3
        
    move(.7) 
    sleep(1)
    if colorscan.color == 1:
        #BOXTYPE 2
        boxtype += 2 
        
    move(.7)
    sleep(1)
    if colorscan.color == 1:
        #BOXTYPE 4
        boxtype += 4
    sleep(1)    
    
    if boxtype == 1:
        return 1
    if boxtype ==3:
        return 2
    if boxtype == 4:
        return 3
    if boxtype ==5:
        return 4
    

def obsticle():
    ultra = UltrasonicSensor(INPUT_2)

def draw_barcode(barcodetype):
    ldc = Display()
    if barcodetype == 1:
        text = "Box Type 1 BARCODE MATCHES"

        ldc.text_pixels(text,clear_screen=True,x=0,y=0,text_color='black',font=None) 
        ldc.rectangle(clear_screen=False,x1=30,y1=30,x2=60,y2=80,fill_color='black')
        ldc.rectangle(clear_screen=False,x1=60,y1=30,x2=90,y2=80,fill_color='white')
        ldc.rectangle(clear_screen=False,x1=90,y1=30,x2=120,y2=80,fill_color='white')
        ldc.rectangle(clear_screen=False,x1=120,y1=30,x2=150,y2=80,fill_color='white')
    if barcodetype == 2:
        text = "Box Type 2"

        ldc.text_pixels(text,clear_screen=True,x=0,y=0,text_color='black',font=None) 
        ldc.rectangle(clear_screen=False,x1=30,y1=30,x2=60,y2=80,fill_color='black')
        ldc.rectangle(clear_screen=False,x1=60,y1=30,x2=90,y2=80,fill_color='white')
        ldc.rectangle(clear_screen=False,x1=90,y1=30,x2=120,y2=80,fill_color='black')
        ldc.rectangle(clear_screen=False,x1=120,y1=30,x2=150,y2=80,fill_color='white')
    if barcodetype == 3:
        text = "Box Type 3"

        ldc.text_pixels(text,clear_screen=True,x=0,y=0,text_color='black',font=None) 
        ldc.rectangle(clear_screen=False,x1=30,y1=30,x2=60,y2=80,fill_color='black')
        ldc.rectangle(clear_screen=False,x1=60,y1=30,x2=90,y2=80,fill_color='black')
        ldc.rectangle(clear_screen=False,x1=90,y1=30,x2=120,y2=80,fill_color='white')
        ldc.rectangle(clear_screen=False,x1=120,y1=30,x2=150,y2=80,fill_color='white')
    if barcodetype == 4:
        text = "Box Type 4"

        ldc.text_pixels(text,clear_screen=True,x=0,y=0,text_color='black',font=None) 
        ldc.rectangle(clear_screen=False,x1=30,y1=30,x2=60,y2=80,fill_color='black')
        ldc.rectangle(clear_screen=False,x1=60,y1=30,x2=90,y2=80,fill_color='white')
        ldc.rectangle(clear_screen=False,x1=90,y1=30,x2=120,y2=80,fill_color='white')
        ldc.rectangle(clear_screen=False,x1=120,y1=30,x2=150,y2=80,fill_color='black')
        
    
    ldc.update()
    time.sleep(10)



        
