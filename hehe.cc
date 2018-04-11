/* *************************************
 *
 * @Author         Noxaean
 * @Email          noxaean@gmail.com
 * @Description
 * @Created        2017-09-05 08:43:04
 * @Last Modified  2017-09-05 08:47:07
 *
 * ****************************************/
#include <iostream>

#include <vector>
using namespace std;

int main(){
    vector<vector<int> > tmp ;
    vector<int> a(4,100);
    vector<int> b(2,200);

    tmp.push_back(a);
    tmp.push_back(b);

    int* q = (int*) &tmp;

    for(int i = 0; i !=6; ++i)
	cout << *(q + i) << endl;
}
