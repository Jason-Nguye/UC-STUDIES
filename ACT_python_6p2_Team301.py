import math


data = open('Snow_Fall.txt','r')
snow = data.readlines()
data.close()
ResultFile = open('Snowfall.txt', 'w')
Max = 0.0
Day = " "
total = 0.0
Tdays = 0.0


for Line in snow:
#Line is Split into two
    value=Line.split
    if float(value[1])>Max:
        #Get Max number
        Max=float(value[1])
        day=value[0]
    if float(value[1])>1:
        total = total +1
    Tdays = Tdays+1
percent = (Total/Tdays)*100
ResultFile.write("Maximum snowfall:{0} inches on {1}\n".format(Max,day))
print("Maximum snowfall: {0} inches on {1} \n".format (Max,day))
ResultFile.write("Percent of Days snowfall exceeded 1 inch: {0:.2f}%".format(percent))
print("Percent of dayssnowfall exceeded 1 inch: {0:.2f}%".format (percent))

ResultFile.close()
