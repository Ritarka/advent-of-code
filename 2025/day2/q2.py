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
            
            for size in range(1, n // 2 + 1):
                if n % size: continue
                acceptable = True
                            
                begin = 0
                end = size
                target = st[begin:end]
                while end < n:
                    begin += size
                    end += size
                    check = st[begin:end]
                    # if (i == 11):
                    #     print(target, check, begin, end)

                    if check != target:
                        acceptable = False
                        break

                if not acceptable:
                    continue
                sum += i
                print(i)
                break

print("Sum: ", sum)