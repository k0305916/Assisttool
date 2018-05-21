#可以查看别人的，比我简介多了。。。。
#https://blog.csdn.net/rosboy/article/details/38542649
#原因：检验是否是质数：只要小于其数的平方根即可。
#当然，别人的考虑里面还有其他的性能上的考量，而我这没有。

def IsPrime(value):
    if value == 2:
        return True
    for i in range(2, value+1):
        if value % i == 0:
            return False
        else:
            return True


def CalculatePrime(value):
    for i in range(2, value+1):
        if value % i == 0 and IsPrime(i):
            return i
    return 0


def function(value):
    if value == 1:
        return [1]
    result = []
    while value != 1:
        prime = CalculatePrime(int(value))
        value /= prime
        result.append(prime)
    return result


value = input()
out = function(int(value))
print(" ".join(str(x) for x in out)+' ')
