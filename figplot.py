# vim filetype=python
# -*-coding:utf-8-*-
# **************************************
#
# @Author         Noxaean
# @Email          noxaean@gmail.com
# @Description
# @Created        2018-04-11 15:28:26
# @Last Modified  2018-04-12 17:03:43
#
# **************************************
import CONFIG
import matplotlib.pyplot as plt
import matplotlib.dates as mdates
import pandas as pd
from datetime import datetime

def plot_curvel(dates, data1, label1, data2, label2):
    plt.figure(figsize=(8,6))
    ax = plt.subplot(111)
    plt.ylim( (-1, 101) )
    plt.title('每日指标图')
    plt.grid(True)
    plt.xlabel('日期')
    plt.ylabel('百分比(%)')
    plt.gca().xaxis.set_major_formatter(mdates.DateFormatter('%Y/%m/%d'))
    plt.gca().xaxis.set_major_locator(mdates.DayLocator())
    line1, = plt.plot(dates, data1, 'o-', linestyle='-', color = 'r', label=label1)
    for x, y in zip(dates,data1):
        plt.text(x, y, y, ha='center', va='bottom', fontsize=10)
    line2, = plt.plot(dates, data2, '*-', linestyle='-', color = 'b', label=label2)
    for x, y in zip(dates,data2):
        plt.text(x, y, y, ha='center', va='bottom', fontsize=10)
    plt.gcf().autofmt_xdate()
    plt.legend(loc='upper left', framealpha = 0)
    plt.subplots_adjust(top=0.92, bottom=0.15, left=0.10, right=0.95, hspace=0.25,
            wspace=0.35)

    plt.savefig("examples.jpg", dpi=100)
    plt.show()



def main():

    df = pd.read_csv('log/graph.csv')
    dates1 = list(df['time'])
    dates = [str(i) for i in dates1]
    xs = [datetime.strptime(d, '%Y%m%d').date() for d in dates]
    ystd  = list(df['ystd'])
    tover = list(df['turnOverLimUp'])
    label1 = "昨日涨停高开率"
    label2 = "换手封板率"
    plot_curvel(xs, ystd, label1, tover,label2)

main()











