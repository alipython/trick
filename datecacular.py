#!/usr/bin/env python
#! -*- coding:utf-8 -*-

import datetime
import os,re
def mainWindow():
		while True:
			print "\n--------------------\n"
			print "选择类型【1|2|3】"
			print "1. 计算2个日期中间天数"
			print "2. 计算某日期前后天数"
			print "3. 退出"
			print "--------------------\n"
			option = raw_input("~>")
			if option == '1':datesCal()
			elif option == '2':dateCal()
			elif option == '3':exit()
			else:continue

def dateCal():
	try:
		print "输入日期!(eg:2015.06.02)"
		dateInput = dateFormat()
		rangeDay = int(raw_input("需要计算的前后日期.eg:+40/-40 \n~>"))
		datetimeDelt = datetime.timedelta(days = rangeDay)
		dateOutput = dateInput + datetimeDelt
		print "输出结果:",dateOutput
	except:
		print "\033[1;31;40m%s\033[0m"%"日期格式错误"			

def datesCal():
	try:
		print "输入第一个日期!(eg:2015.06.02)"
		dateFisrt = dateFormat()
		print "输入第二个日期!(eg:2015.06.03)"
		dateSecond = dateFormat()
		dateOutput = (dateSecond - dateFisrt).days
		print "相差:",dateOutput,"天"
	except:
		print "\033[1;31;40m%s\033[0m"%"日期格式错误"

def dateFormat():
	dates = getInput()
	dateInput = datetime.date(dates[0],dates[1],dates[2])
	return dateInput

def getInput():
	pattern = r'(\d+)?'
	rawInput = re.findall(pattern,raw_input("~>"))
	date = [int(x) for x in rawInput if x != '']
	return date

if __name__ == '__main__':	
	
	mainWindow()


	
	
	

	
	
	
		
		
	


