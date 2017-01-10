/* ************************************
*
* @Author         Noxaean
* @Email          noxaean@gmail.com
* @Description  
* @Created        2017-01-06 15:37:38
* @Last Modified  2017-01-10 10:46:26
*
* ****************************************/
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>

void freshPage(){
}

void joinParty(){
	// join the party
	SetCursorPos(247,80);
	mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,0,0,0,0);
	SYSTEMTIME sys;
	//auto mission
	GetLocalTime(&sys);
	SetCursorPos(247,80);
	mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,0,0,0,0);
}

/*	Define Activity
 *	10:00 
 *	12:00
 *	14:00
 *	14:30
 *	15:00
 *  15:30
 *  16:00
 *  16:40
 *  18:00
 *  19:00
 */
using namespace std;
int main(){
	POINT pt;
	//while(true){
	//GetCursorPos(&pt);
	//cout << "hehe" << pt.x << "and " << pt.y << endl;	
	//Sleep(1000);
	//}
	SYSTEMTIME sys;
	//auto mission
	GetLocalTime(&sys);
	struct tm *timer;
	time_t timep;
	time(&timep);
	timer = gmtime(&timep);
	cout << "h" << timer->tm_hour << "m" << timer->tm_min << endl;
	cout << "h " << sys.wHour << endl;
	// define 10:00 activity
	Sleep(5000);
	cout << "h" << timer->tm_hour << "m" << timer->tm_min << endl;
	return 0;
}


