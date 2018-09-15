#include<stdio.h>
#include<stdlib.h>


int main (){
	int a = 0x5Ebb;
	int temp = 0;
	int shift;

/*==========Strings=========*/
/*	char a[10] = "Mangal";
	char b[10];
	char *src,*dest;
	src=a;
	dest=b;
	int begin,end=0,count=0;
*/

/*==========String reversal=========*/
/*	while ( a[count] != '\0'){
		count++;
	}
	
	for(begin=count; begin>0; begin--){
		b[end]= a[begin-1];
		end++;
	}
	b[count]='\0';
	printf("%s\n",b);
*/

/*==========String copy=========*/
/*	while (*src != '\0'){
		*dest=*src;
		src++;
		dest++;
	}
	dest++;
	*dest='\0';
	printf("%s\n", b);
*/
	
	temp = ((a>>8) | (a<<8))&0x0000FFFF;
	
	printf("%x\n", temp);
		
	return 0;
}
