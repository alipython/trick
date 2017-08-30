# vim filetype=python
# -*-coding:utf-8-*-
# **************************************
# 
# @Author         Noxaean
# @Email          noxaean@gmail.com
# @Description  
# @Created        2017-07-07 14:12:41
# @Last Modified  2017-07-07 14:29:23
# 
# **************************************

import sys
from collections import defaultdict



def getUePrint(files):
    """ return an map{int:[int...]}"""
    dicts = defaultdict()
    with open(files) as f:
        for line in f.readlines():
            lst  = map(int,line.strip().split())
            if dicts.has_key(lst[0]):
                dicts[lst[0]].append(lst[1])
            else:
                dicts[lst[0]] =  []
                dicts[lst[0]].append(lst[1])

        return dicts

def trafficRate(dicts):
    for key,value in dicts.items():
        for i in range(1,len(value)):
            value[i] = value[i] * 100 / value[0] 
    return dicts


def main():
    fileName = sys.argv[1]
    result = getUePrint(fileName)
    result = trafficRate(result)
    for i in  result:
        print i,result.get(i)


if __name__ == '__main__':
    main()
