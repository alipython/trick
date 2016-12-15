# vim filetype=python
# -*-coding:utf-8-*-
# **************************************
# 
# @Author         Noxaean
# @Email          noxaean@gmail.com
# @Description  
# @Created        2016-12-15 19:05:14
# @Last Modified  2016-12-15 20:18:45
# 
# **************************************

"""
 persuade code:
    init(list)
    random choice(list)
    if choice = car:
        rest = random choice(list.remove(car))
    else:
        rest = car

arithmetic:
    Probability 1st time:  car  =  1/3 ; sheep = 2/3
    after remove 1 sheelp;
    Probability for the car:
    change will swap the 1st Probability. 
"""
import random
doorBehind = ["car","sheep1","sheep2"]
def changeOrNot(lists,change=False):
    copy_list = lists[:]
    " random the source"
    random.shuffle(copy_list)
#    print "init objects are: " , copy_list
    firstChoice = random.choice(copy_list)
    copy_list.remove(firstChoice)
    if firstChoice == "car":
        left = random.choice(copy_list)
#        print "your choice: ", firstChoice ," and left is ",left
        return (1 if change == False else 0)
    else:
        left = "car"
#        print "your choice: ", firstChoice ,"and left is ",left
        return (0 if change == False else 1)

if __name__ == "__main__":
    cout = 0
    times = 10000
    for i in range(times):
        res= changeOrNot(doorBehind,change=True)
        if res == 1 :
            cout = cout + 1

    proba = cout *100 // times 
    print "Probability for ",times,"times are: ", proba,"%"
