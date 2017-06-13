# vim filetype=python
# -*-coding:utf-8-*-
# **************************************
# 
# @Author         Noxaean
# @Email          noxaean@gmail.com
# @Description  
# @Created        2017-02-09 11:09:02
# @Last Modified  2017-06-13 13:32:46
# 
# **************************************

print hex(16)  ==  "0x10"

#262800100945047+5999

start = 262800100945047
width = 5999

for i in range(0,6000):
    num = hex(start + i)
    if "ffff" in num:
        print num,"==" ,i






