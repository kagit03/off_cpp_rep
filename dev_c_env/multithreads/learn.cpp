#include<iostream>

using namespace std;

int main (){
	cout << "Hello World from Mangal!!\n" << endl;
	try {
		int mangal =15;
		int mahen = 12;
		
		if (mangal > mahen){
			throw 25;
		}
	}catch (int x){
		cout << "mahen is always greater, ERROR:" << x << endl;
	}
	
	return 0;
}
