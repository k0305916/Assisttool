

def fuc(dis):
    if(len(dis) <= 0):
        return -99
    elif len(dis) > 0 and dis[0] == 0:
        return -99
    elif len(dis) > 0 and dis[0] >= len(dis):
        return 1
    #在可跳跃的范围内取一个最大值
    distemp = dis[1:dis[0]+1]
    result = 1
    disnext = dis[1:]
    maxdis = max(distemp)
    if distemp.count(maxdis) > 1:
        distemp = disnext[(len(distemp) - distemp[::-1].index(maxdis) - 1):]
    else:
        distemp = disnext[disnext.index(maxdis):]
    if dis[0]+maxdis <= len(dis):
        result = 1 + fuc(distemp)
    else:
        result += 1
    return result


wide = int(input('Please input the river wide: '))
disstr = input('Please input dis: ').split()
dis = list(map(eval, disstr))
result = fuc(dis)
if result <= 0:
    print(-1)
else:
    print(result)
