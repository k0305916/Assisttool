# a = [2,3,4,5,6]

# print(" ".join(str(x) for x in a))

while True:
    try:
        s = input()
        l = len(s)
        min = l
        for i in range(l):
            x = []
            for j in 'ABCDE':
                x.append(s.find(j))
            x.sort()
            if min > x[-1]:
                min = x[-1]
            s = s[1:] + s[0]
            print(l-min-1)
    except:
        break
