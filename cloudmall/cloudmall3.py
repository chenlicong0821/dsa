# 请实现一个方法，要求在给定的字母排序顺序，对输入的一组单词进行字典序排序操作。
# 例如给定字母顺序'cba'
# 对于单词组['ab', 'ac', 'ba', 'bc', 'abc']，
# 预期的排序结果为['bc', 'ba', 'ac', 'ab', 'abc']

def compareWord(letterDict, a, b):
    aLen = len(a)
    bLen = len(b)
    minLen = min(aLen, bLen)
    for i in range(minLen):
        if a[i] == b[i]:
            continue
        aScore = letterDict.get(a[i], 0)
        bScore = letterDict.get(b[i], 0)
        if aScore > bScore:
            return True
        else:
            return False

    return aLen > bLen


def sortWords(orders, words):
    letterDict = {}
    for i, letter in enumerate(orders):
        letterDict[letter] = i + 1

    n = len(words)
    for i in range(n - 1):
        swapFlag = False
        for j in range(n - 1 - i):
            if (compareWord(letterDict, words[j], words[j + 1])):
                words[j + 1], words[j] = words[j], words[j + 1]
                swapFlag = True
        if not swapFlag:
            break

    return words


if __name__ == '__main__':
    orders = 'cba'
    words = ['ab', 'ac', 'ba', 'bc', 'abc']
    print(sortWords(orders, words))
