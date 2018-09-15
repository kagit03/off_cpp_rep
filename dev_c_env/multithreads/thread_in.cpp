#include <iostream>
#include <thread>
using namespace std;

class mangal
{
	public:
	mangal()//zero argument constructor
	{

	}
	
	void hello ()
	{
		cout << "Hi cpp world !! I have stepped in"<<endl;
	}
};

void hello ()	
{
	cout << "Hi cpp world !! I have stepped in"<<endl;	
}


int main(int argc, char* argv[]){
while(1)
{
	mangal f1;
	//f1.hello();	
	std::thread t1(&mangal::hello,mangal());
        //std::thread t1(hello);
	t1.join();
}

	return 0;
}

