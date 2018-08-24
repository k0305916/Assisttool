import math
import sys


for inputvalue in sys.stdin.readlines():
    result = []
    # minvalue, maxvalue = input().split(' ')
    minvalue, maxvalue = map(int, inputvalue.strip().split())
    for i in range(minvalue, maxvalue+1):
        value = i
        valuelist = []
        while i != 0:
            valuelist.append(i % 10)
            i = int(i / 10)
        if sum(list(map(lambda x: pow(x, 3), valuelist))) == value:
            result.append(str(value))

print("no" if not result else " ".join(result))
