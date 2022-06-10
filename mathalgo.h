#include <stdio.h>
#include <math.h>
#include <windows.h>


void wipe(){
	for (int i=0; i<100000; i++){
	printf(" ");
	if (i%1000==0){
		printf("\n");
	}
}
}

COORD coord= {0,0}; 
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void findprime(){
	printf("Running now up to...");
	long int upto;
	long int * ptrupto = &upto;
	ptrupto = (long int*)malloc(sizeof(long int));
	scanf("%ld", &upto);
	//long int arr[250000];
	long int *arr;
	(arr)=(long int*)malloc(upto*sizeof(long int));
	int finding;
	int index = 0;
	int dice = 0;
	
	for (int i=1; i<=upto; i+=2)
	{
		index = 0;
		if (i==1){
			//printf("Found prime: %d\n", i);
			arr[dice] = i;
			dice++;
			//printf("Found prime: %d\n", 2);
			arr[dice] = 2;
			dice++;
			continue;
		}
		for (int j=1; j<=i; j++)
		{
			if (i%j==0){
				index++;
			}
		}
		float prog = i;
		if (index<=2){
			//printf("%d\n", i-1);
			//printf("Found prime: %d\n", i);
			gotoxy(3, 3);
			printf("Progress...%.02f%%", (prog/upto)*100);
			arr[dice] = i;
			dice++;
		}
		else{
		//	printf("%d\n%d\n", i-1, i);
		}
	}
	gotoxy(3, 3);
	printf("                                                                                                            \n");
	printf("Completed!\n");
	printf("Compiled list of primes:\n");
	for (int i=0; i<dice; i++){
		printf("%d", arr[i]);
		if (i%9==0&&i!=0){
			printf("\n");
		}
		else{
			printf(", ");
		}
		
	}
	printf("\nTry again? y/n: ");
	free(arr);
	getchar();
	char ans;
	scanf("%c", &ans);
	if (ans=='y'||ans=='Y'){
		findprime();
	}
}
