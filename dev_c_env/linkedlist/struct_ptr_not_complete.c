#include<stdio.h>

struct a{

	struct b{
		int i;
		float f;
		char ch;
	}x;
	struct c{
		int j;
		float g;
		char ch;
	}y;
}z;

void func (struct c* p){
	int offset;	
	struct b* address;
	
	offset = (char*)&((struct c*)(&((struct a*)0)->y)->j);
	
}

int main (int c, const char** argv){

	struct a z;
	func(&z.y);
	printf("%d %f %c\n", z.x.i, z.x.f, z.x.ch);

	return 0;

}
