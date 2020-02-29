import json

from typing import Dict
def cloudmall_interview2(revList: Dict[str, str]) -> str:
    ret = {}

    for k, v in revList.items():
        vList = v.split('.')
        if len(vList) == 1:
            ret[v] = k
        else:
            tmpDict = ret
            i = 0
            for tmpk in vList:
                if tmpk in tmpDict:
                    tmpDict = tmpDict[tmpk]
                else:
                    if i == len(vList) - 1:
                        tmpDict[tmpk] = k
                    else:
                        a = {vList[-1]: k}
                        b = {}
                        for j in range(len(vList) - 2, i, -1):
                            b[vList[j]] = a
                            a = b
                            b = {}
                        tmpDict[tmpk] = a
                    break
                i += 1

    return json.dumps(ret)

if __name__ == '__main__':
    revList = {"1": "bar", "2": "foo.bar", "3": "foo.foo", "4": "baz.cloudmall.com", "5": "baz.cloudmall.ai"}
    ret = cloudmall_interview2(revList)
    print(ret)
