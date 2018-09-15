#include<stdio.h>
#include<string.h>
#include<getopt.h>
#include<stdlib.h>

static void CmdlineParser (int argc, char* argv[]){
	int option;
	int cflag=0;
	int fflag=0;
	while ((option = getopt(argc, argv, "cf")) != -1){
		switch (option){
			case 'c':
				if (cflag){
					printf("Only one option\n");
					exit (1);
				}else{
					cflag++;
					fflag++;
					printf("You want Centigrade Temp\n");
				}	
				break;
			case 'f':
				if (cflag){
					printf("Only one option\n");
					exit (1);
				}else{
					cflag++;
					fflag++;
					printf("You want Farneheit Temp\n");
				}
				break;
			default:
				printf("Error Entry\n");
				break;
		}
	}
}

static void print_usage(){

}

int main (int argc, char* argv[]){
       
	CmdlineParser (argc, argv);
	return 0;
}
