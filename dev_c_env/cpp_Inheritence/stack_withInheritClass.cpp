#include<iostream>
using namespace std;

const int MAX=25;

//base class
class stack
{
  protected:
    int top;
    int s[MAX];
  public:
    //constructor
    stack()
    {
      top=-1;
    }

    //member function push
    void push (int n)
    {
       top++;
       s[top]=n;
    } 
    
    //member function pop
    int pop ()
    {
       int n;
       n=s[top];
       top--;
       return n;
    }   
};

//derived class

class stack_derive : public stack
{
   public:
    //member function push
    void push (int n)
    {
       if (top == MAX-1)
       {
         cout << "Stack is full" << endl;
       }
       else
       {
         stack::push(n);
       }
    }
    
    //member function pop
    int pop ()
    {
       int n;
       if (top == -1)
       {
          cout << "Stack is empty" << endl;
          return 0;
       }
       else
       {

          n=stack::pop();
          return n;
       }
    }   
    
};

int main ()
{
  int del;
  stack_derive stk;
  stk.push(10);
  stk.push(30);
  del=stk.pop();
  cout << "poped out "<< del << endl;
  return 0;
}
