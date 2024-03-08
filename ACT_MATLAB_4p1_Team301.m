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

Picture =imread('Arm_Fracture(1).jpg');
size(Picture)
Picture(1,1)
Picture(235:240,160:165)
figure(1); imshow(Picture);
Picture = Picture + 50;
figure(2);imshow(Picture);
Picture=Picture/2;
figure(3); imshow(Picture);