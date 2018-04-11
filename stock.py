# vim filetype=python
# -*-coding:utf-8-*-
# **************************************
#
# @Author         Noxaean
# @Email          noxaean@gmail.com
# @Description
# @Created        2017-04-04 20:02:34
# @Last Modified  2017-08-10 23:57:57
#
# **************************************
import requests
import datetime
import json

# stock key word search

# define var and parameter

pageIndex = "1"
currentDay = datetime.datetime.now().strftime("%Y-%m-%d")
keywords = ""


def getUrl(date,page):
    sourceUrl =  "http://data.eastmoney.com/notices/getdata.ashx?StockCode=&FirstNodeType=0&CodeType=1&PageIndex=" + page + "&PageSize=50&jsObj=RfzIEoDN&SecNodeType=0&Time=" + date +"&rt=49710125"
    return sourceUrl


def formatter(stringBuffer):
    subIndex = stringBuffer.index("{")
    subString = stringBuffer[subIndex:-1]
    return json.loads(subString)

def searchPages(date):

    "remove after test"
    date = "2017-04-04"

    url = getUrl(date,"1")

    reply = requests.get(url)
    if reply.status_code == 200:
        print "ok"

        info = formatter(reply.text.encode("utf-8"))
    else :
        print "nok"


if __name__ == "__main__":
    searchPages(currentDay)

