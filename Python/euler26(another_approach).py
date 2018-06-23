import time
start = time.time()
def cycle_length(x):
    while x%2 == 0: x//=2
    while x%5 == 0: x//=5
    if x==1:
        return 0
    t = 9
    while True:
        if t%x == 0:
            return len(str(t))
        t= t*10 + 9

results = [(cycle_length(i), i) for i in range(1, 1000)]
print(max(results)[1])
end = time.time()
print("time : {0}".format(end-start))
