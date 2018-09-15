#include<iostream>
#include<vector>
#include<algorithm>//sort
using namespace std;

int main (){
	vector<int> v;
	v.push_back(95);
	v.push_back(39);
	v.push_back(63);
	v.push_back(82);
	
	sort(v.begin(), v.end());
	vector<int>::iterator itr;
	
	itr = v.begin();	
	
	for(;itr != v.end(); itr++){
		cout<<*(itr)<<endl;
	}

	cout<<"Size="<<v.size()<<endl;
	v.clear();
	cout<<"Size="<<v.size()<<endl;
	
	return 0;
}
