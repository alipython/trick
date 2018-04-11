/* *************************************
 *
 * @Author         Noxaean
 * @Email          noxaean@gmail.com
 * @Description
 * @Created        2017-09-05 15:32:15
 * @Last Modified  2017-09-05 15:33:39
 *
 * ****************************************/
#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int main(){
    string a = "abcdefg";

    for(auto i : a)
	toupper(i);
    cout << a << endl;
}

