/* *************************************
 *
 * @Author         Noxaean
 * @Email          noxaean@gmail.com
 * @Description
 * @Created        2017-09-05 09:02:33
 * @Last Modified  2017-09-05 10:33:36
 *
 * ****************************************/

#include <iostream>
#include<mysql/mysql.h>
#include <vector>
using namespace std;

int main(){
    vector<int> a(4,100);
    vector<vector<int> > avec;
    vector<int>b(2,200);
    avec.push_back(a);
    avec.push_back(b);

    cout << &a << "---" << &*a.begin()<< endl;


}
