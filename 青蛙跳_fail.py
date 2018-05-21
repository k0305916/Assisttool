

def fuc(dis):
    order = []
    result = 1
    if(len(dis) <= 0):
        return -99, [-1]
    elif len(dis) > 0 and dis[0] == 0:
        order.append(0)
        return -99, order
    elif len(dis) > 0 and dis[0] >= len(dis):
        order.append(dis[0])
        return 1, order
    order.append(dis[0])
    #在可跳跃的范围内取一个最大值
    distemp = dis[1:dis[0]+1]
    disnext = dis[1:]
    maxdis = max(distemp)
    if distemp.count(maxdis) > 1:
        distemp = disnext[(len(distemp) - distemp[::-1].index(maxdis) - 1):]
    else:
        distemp = disnext[disnext.index(maxdis):]
    if dis[0]+maxdis <= len(dis):
        result, suborder = fuc(distemp)
        result += 1
        order.append(suborder)
    else:
        result += 1
        order.append(maxdis)
    return result, order


wide = int(input('Please input the river wide: '))
disstr = input('Please input dis: ').split()
dis = list(map(eval, disstr))
result, order = fuc(dis)
print(order)
if result <= 0:
    print(-1)
else:
    print(result)
