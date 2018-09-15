#include<iostream>
#include<map>
#include<unordered_map>

//compile cmd: g++ -std=c++11 -o maps maps.cc

using namespace std;

int main (){
	//pair example just to understand how pairs work
	pair<int,int> pr;
	pr=make_pair(9,18);
	cout<<"Pair value"<<pr.first<<"--"<<pr.second<<endl;

	//maps key,value
	unordered_map<int,int> ump;
	map<int,int> mp;
	mp[3]=30;
	mp[5]=50;
	mp[2]=20;
        mp.insert(make_pair(1,10));

	cout<<"map"<<endl;
	for(auto itr=mp.begin(); itr != mp.end(); itr++){
		cout<<itr->first<<"---"<<itr->second<<endl;
	}

	cout<<"unodered map"<<endl;
	ump[3]=30;
	ump[5]=50;
	ump[2]=20;
        ump.insert(make_pair(1,10));
	for(auto itr=ump.begin(); itr != ump.end(); itr++){
		cout<<itr->first<<"---"<<itr->second<<endl;
	}

	cout<<"multimap"<<endl;
	multimap<int,int> mmp;
	mmp.insert(make_pair(1,20));
	mmp.insert(make_pair(1,20));
	mmp.insert(make_pair(1,50));
	mmp.insert(make_pair(1,20));

	for (auto itr=mmp.begin(); itr != mmp.end(); itr++){
		cout<<itr->first<<"--"<<itr->second<<endl;
	}
	return 0;
}
