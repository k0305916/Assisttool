#排队接水问题
# n个人一起排队接水，第i个人需要a[i]的时间来接水。1 <= n <= 1000,
#1 <= a[i] <= 1000同时只能有一个人接水，正在接水的人和没有接水的人都需要等待。
# 完成接水的人会立刻消失，不会继续等待。你可以决定所有人接水的顺序，
# 并希望最小化所有人等待时间的总和。
#----感觉上这仍然是一个动态规划/贪心算法的问题

import random

persionN = int(input('input the number of persion: '))
ReceiveWaterTime = {}
for i in range(1, persionN+1):
    ReceiveWaterTime[i] = random.randint(1, 1000)

#全排列的方式


#贪心算法：总是选择最小的----但是这个能保证是全局最小吗？
temp = dict(sorted(ReceiveWaterTime.items(),
                   key=lambda d: d[1], reverse=False))
sumtime = 0
for i in range(1, len(temp)):
    #通过计算公式一次性得到时间总和
    sumtime += (temp[i]*(len(temp)-i+1))
print(sumtime)
