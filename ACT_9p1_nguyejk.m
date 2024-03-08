% Activity XX: 2D ARRAYS
% File: CFU 2D ARRAYS
% Date: 2/27
% By: Jason Nguyen nguyejk (If Team Assignment, include all members info)
%
% Section: 17
% Team: 301
%
% ELECTRONIC SIGNATURE (if team assignment, include all members info)
% Full Name
%
% The electronic signature above indicates the script
% submitted for evaluation is my individual work, and I
% have a general understanding of all aspects of its
% development and execution.
%
% A BRIEF DESCRIPTION OF WHAT THE SCRIPT OR FUNCTION DOES
%
clear all;close all; clc;

thres= input('Please enter the threshold value:');
while thres<0
    thres= input('Please re-enter threshold value');
end
while thres>255
    thres= input('Please re-enter threshold value');
end

Picture =imread('Arm_Fracture(1).jpg');
[r,c] = size(Picture);
Picture(1,1)
Picture = uint8(Picture);
figure(1); imshow(Picture);
newPicture=zeros(size(Picture));
for row = 1:r
    for col = 1:c
        if(Picture(row,col)) <thres
            newPicture(row,col)=0;
        else
            newPicture(row,col)=255;
        end
    end
end
newPicture(1,1)
figure(2); imshow(newPicture)

