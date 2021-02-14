import time
def gp(base,cm=1):
    series = []
    x = time.time()
    while base < 100000 : 
        series.append(base)
        base *= cm
    y = time.time()
    print("Time inside loop" + str(y-x) + "seconds")
    return series
start = time.time()
a = int(input("Enter the value of a: "))
q = int(input("Enter the value of q: "))
if(q==1):
    print("Infinite series")
else:
    print(gp(a,q))
end = time.time()
print("Total time : " + str(end - start) + "seconds")

