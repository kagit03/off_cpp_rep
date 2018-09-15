#include<iostream>
using namespace std;

//Base class
class index 
{
	protected:
	int count;

	public:
	index()//constructor 
	{
	  count = 0;  
	}

	index(int c)//constructor with args
	{
	  count = c;  
	}
	void operator++()
	{
	  count++;
	}
        void display()
        {
           cout << "The coount is =" << count << endl;
        }
};

//Derived class
class index1 : public index
{
    public:
	void operator--()
	{
	   count--;	
        }
};


int main()
{
  index1 a;
  ++a;
  ++a;
  a.display();
  --a;
  a.display();
  return 0;
}
