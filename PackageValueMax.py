import operator


package = {'n1':1,'n2':2,'n3':3,'n4':10,'n5':5,'n6':6,'n7':7,'n8':8,'n9':9,'n10':4}
weight = int(input('Please input weight: '))

#以value的值进行排序，reverse：True:从大到小;False:从小到大
result = sorted(package.items(),key=operator.itemgetter(1),reverse=True)

weightlist = []
for i in result:
    if i[1] <= weight:
        weightlist.append(i)
        weight -= i[1]

print(weightlist)

