#! /usr/bin/python
import sys,getopt
import json,urllib2
import re

PROD = "CXP2001005"
def usage():
	"""
	This script is used for prod quick searh
	./find.py -p CXC30004 -l 5
	"""
	print "hah over"

def isParamCorrect(paramDict):
	pattern = r'^CXP\d{7}$'
	if paramDict.has_key("help"):
		usage()
		exit(0)
	if paramDict.has_key("prod"):
		if not re.match(pattern, paramDict["prod"]):
			print "wrong prod Num : {}".format(paramDict["prod"])
			exit(0)
	if paramDict.has_key("latest"):
		if not re.match(r'^\d+$', paramDict["latest"]):
			print "should be num not ({}). ".format(paramDict["latest"])
			exit(0)
	if paramDict.has_key("search"):
		if not re.match(pattern, paramDict["search"]):
			print "wrong release Num :{}".format(paramDict["search"])
			exit(0)


def main():
	try:
		options,args = getopt.getopt(sys.argv[1:], "hp:l:s:",
		["help", "product=", "latest=", "search="])
	except getopt.GetoptError:
		print "wrong param input"
		sys.exit()
	param =  dict()
	for name,value in options:
		if name in ("-h", "--help"):
			param["help"] = 1
		if name in ("-p", "--product") :
			param["prod"] = value.upper()
		if name in ("-l", "--latest") :
			param["latest"] = value
		if name in ("-s", "--search") :
			param["search"] = value.upper()
	isParamCorrect(param)
	print param


if __name__ == '__main__':
	main()

