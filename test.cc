/* *************************************
*
* @Author         Noxaean
* @Email          noxaean@gmail.com
* @Description  
* @Created        2017-01-10 16:54:14
* @Last Modified  2017-06-13 13:24:59
*
* ****************************************/
#include <iostream>
 
using namespace std;
int main(){
	int a = 1200,b= 920,c;

	c =  (a / 100 - b /100) * 60 + a % 100 - b % 100  ;
	cout << c << endl;
	return 0;
}


