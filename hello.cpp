/* *************************************
 *
 * @Author         Noxaean
 * @Email          noxaean@gmail.com
 * @Description  
 * @Created        2017-08-05 23:49:14
 * @Last Modified  2017-08-06 01:02:04
 *
 * ****************************************/
#include <iostream>
#include <fstream> 
#include <bitset>
#define	LOADER_FILE_PATH		"/Users/ali/github/scripttest/"
using namespace std;

int main(){
    string fileName	    =		"test.s";
    string fileNameTo	    =		"bin.log";
    string fullFilePath	    =		LOADER_FILE_PATH + fileName;
    fstream inFile;
    string fullFileNameTo	    =		LOADER_FILE_PATH + fileNameTo;
    ofstream outFile;
    outFile.open(fullFileNameTo, ofstream::app | ofstream::binary);
    inFile.open(fullFilePath.data());
    string s ;
    while(getline(inFile, s)){
	cout << s << endl;
	string str1 = s + "\n";
	char *str = (char*)str1.data();
	for (int i = 0; i != s.length() + 1; ++i){
	    outFile.write(bitset<8>(*(str + i)), 8);
	}
	}	    
		    outFile.close();
		    inFile.close();   
		}


