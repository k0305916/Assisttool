
#最短子串问题。
while True:
    order = input()
    jewelrylist = ['A','B','C','D','E']
    loc = []
    #split word to char
    orderlist = list(order)
    start = 0
    for jewel in orderlist:
        if jewel in jewelrylist:
            findloc = orderlist.index(jewel,start)
            loc.append(findloc)
            start = findloc+1

    #the last diff
    #add the last diff
    loc.append(loc[0] + loc[-1] + 1)

    last = 0
    locdiff = []
    for i in loc:
        locdiff.append(i - last -1)
        last = i
    locdiff = locdiff[1::]
    print(max(locdiff))


