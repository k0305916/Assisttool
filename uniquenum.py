

value = int(input('input a number: '))
resultlist = []
while value > 1.0:
    temp = value % 10
    value = int(value / 10)
    resultlist.append(temp)
result = set(resultlist)#已经经过了排序了。。。但是我看文档，说明是unordered unique elements
# sorted(result)
print(result)