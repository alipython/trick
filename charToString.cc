/* *************************************
 *
 * @Author         Noxaean
 * @Email          noxaean@gmail.com
 * @Description
 * @Created        2017-08-24 22:03:55
 * @Last Modified  2017-08-24 22:19:44
 *
 * ****************************************/
#include <iostream>
#include <string>
using namespace std;
int main(){

    char *pchar0;
    char *pchar1 = "char start string";

    char achar0[] = "init array char";
    char achar1[100];

    string s1 = "s1 string";
    string s2;
    //achar0 = s1;
    pchar0 =  (char*)&s1;
    cout << pchar0 << endl;
    s2 = pchar1;
    cout << s2 << endl;
    s2 = achar0;
    cout << s2 << endl;
}

