#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	
	vector<int> v;
	v.push_back(10);
	v.push_back(15);
	v.push_back(25);
	v.push_back(30);
	v.push_back(25);
	v.push_back(35);

	v.erase(v.begin() + 2, v.begin() + 3);
	//std::remove(v.begin(),v.end(),30);

	for(auto &val:v)
		cout<<val<<endl;
	return 0;
}
