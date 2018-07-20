# 继MIUI8推出手机分身功能之后，MIUI9计划推出一个电话号码分身的功能：首先将电话号码中的每个数字加上8取个位，
# 然后使用对应的大写字母代替 （"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT",
#  "NINE"）， 然后随机打乱这些字母，所生成的字符串即为电话号码对应的分身。
# 输入描述:
# 第一行是一个整数T（1 ≤ T ≤ 100)表示测试样例数；接下来T行，每行给定一个分身后的电话号码的分身（
# 长度在3到10000之间）。
# 输出描述:
# 输出T行，分别对应输入中每行字符串对应的分身前的最小电话号码（允许前导0）。
# 示例1
# -----
# 输入
# 4
# EIGHT
# ZEROTWOONE
# OHWETENRTEO
# OHEWTIEGTHENRTEO
# -----
# 输出
# 0
# 234
# 345
# 0345
import operator
import collections


def Init():
    string = ["ZERO", "ONE", "TWO", "THREE", "FOUR",
              "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
    charstring = set('')
    dic = {}
    for item in string:
        charstring = charstring | set(item)
    for c in charstring:
        for item in string:
            if c in item:
                if c not in dic:
                    dic[c] = [item]
                else:
                    dic[c].append(item)
    return dic


def GetStringArrayPossibility(text, dic):
    result = {}
    for c in text:
        value = dic[c]
        for item in value:
            if item not in result:
                result[item] = 1
            else:
                result[item] += 1
    print(result)
    # get result max--python3
    # max(result.items(), key=operator.itemgetter(1))[0]
    #2 conditions:---这个思路不一定能解决所有问题。。。不是好方法。
    #1. item len <= count;
    #2. item together with text count == item len->to make sure each char of item is contained.
    compareresult = {k: v for k, v in result.items() if (len(k) <= v) and 
    (len(set(k) & set(text)) == len(set(k)))}.keys()
    print(compareresult)
    return compareresult


def GetNumber(text):
    result = []
    dic = {'ONE': 1, 'TWO': 2, 'THREE': 3, 'FOUR': 4, 'FIVE': 5, 'SIX': 6, 'SEVEN': 7, 'EIGHT': 8,
           'NINE': 9, 'ZERO': 0}
    # if isinstance(number,collections.Iterable):
    for item in text:
        result.append(dic[item])
    # else:
    #     result.append(dic[text])
    return result


def GetMinSequence(number):
    return sorted(number)


def GetOriginalNumber(number):
    original = []
    for num in number:
        original.append((10 + (num - 8)) % 10)
    # return ''.join(''.join('%s' % id for id in original))
    return original


initdic = Init()
print(initdic)
number = int(input("Input number please: "))
for i in range(number):
    text = input('Input string please: ').upper()
    possbilityvalue = GetStringArrayPossibility(text, initdic)
    possbilityNumber = GetNumber(possbilityvalue)
    possibilityOriginNumber = GetOriginalNumber(possbilityNumber)
    result = GetMinSequence(possibilityOriginNumber)
    
    # if len(possibilityOriginNumber) <= 1:
    #     result = possibilityOriginNumber[0]
    # else:
    #     result = ' '.join(possibilityOriginNumber)
    print(''.join('%s' % id for id in result))
