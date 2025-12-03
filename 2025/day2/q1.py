sum = 0

with open("q1.txt") as f:
    line = f.readline().strip()
    ranges = line.split(",")
    for val in ranges:
        elems = val.split("-")
        s = int(elems[0])
        e = int(elems[1])
        
        # print(s, e)
        
        for i in range(s, e+1):
            st = str(i)
            n = len(st)
            if n % 2: continue
            # print(i, st[:n//2], st[n//2:])
            if st[:n//2] == st[n//2:]:
                print(i)
                sum += i
        
        
ranges = []


print("Sum: ", sum)