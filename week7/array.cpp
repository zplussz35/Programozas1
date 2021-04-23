#include<stdio.h>

int sum(int num1,int num2);
int sub(int num1,int num2);
int mult(int num1,int num2);
int div(int num1,int num2);

int main()
{
	int x,y,choice,result;
	int (*ope[4])(int,int);
	ope[0]=sum;
	ope[1]=sub;
	ope[2]=mult;
	ope[3]=div;

	printf("Enter two integers: ");
	scanf("%d%d",&x,&y);
	printf("Enter 0 to sum, 1 to sub, 2 to multiplie, 3 to divide: ");
	scanf("%d",&choice);
	result=ope[choice](x,y);
	printf("%d",result);
}

int sum(int num1,int num2){return num1+num2;}
int sub(int num1,int num2){return num1-num2;}
int mult(int num1,int num2)	{return num1*num2;}
int div(int num1,int num2){if (num2!=0) return num1/num2; else return 0;}