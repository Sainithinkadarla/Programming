import math


x=list(map(int,input().split()))
print(x)
x2=[]
s_of_x=0
s_of_x2=0

for i in range(0,len(x)):
    x2.append(math.pow(x[i],2))

for i in range(0,len(x)):
    s_of_x=s_of_x+x[i]
    s_of_x2=s_of_x2+x2[i]
print(x2)

print("sum of x=",s_of_x)
print("sum of x2=",s_of_x2)