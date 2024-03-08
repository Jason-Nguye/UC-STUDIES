import math


TempC = open ('TempC.txt', 'r')
Data = TempC.readlines()
TempC.close()
n=[]
for Line in Data:
    n.append(math.ceil((int(Line)*9/5)+32))
TempF=open("TempF.txt","w")
for i in range(len(n)):
    TempF.write(str(n[i])+"\n")
   

    

TempC.close()
TempF.close()
