#include<iostream>

using namespace std;

class base{
	private:
		int i;
	public:
	base(){
		cout<<"In base constructor"<<endl;
	}
	~base(){
		cout<<"In base destructor"<<endl;
	}
	virtual void func(){
		cout<<"in base class"<<endl;
	}
	void func1(){
		cout<<"In base non virtual function"<<endl;
	}
};

class derived : public base{
	public:
	derived(){
		cout<<"In derived class constructor"<<endl;
	}
	~derived(){
		cout<<"In derived class destructor"<<endl;
	}
	void func(){
		cout<<"In dervided class"<<endl;
	}
	void func1(){
		cout<<"In derived non virtual function"<<endl;
	}
};

int main(){
	base *p;
	derived s;
	p=&s;
	p->func();
	p->func1();
	return 0;
}
