#include "std_lib_facilities.h"

int length(char* str)
{
	int n=0;
	while(str[n])
	{
		++n;
	}
	return n;
}

int main()
{
	char ac[]="Howdy";

	length(ac);

	cout<<"len== "<<length(ac)<<endl;

	cout<<"Size of char== "<<sizeof(char) <<" bytes.\n";
	cout<<"Size of double== "<<sizeof(double) <<" bytes.\n";
	cout<<"Size of double*== "<<sizeof(double*) <<" bytes.\n";
	cout<<"Size of char*== "<<sizeof(char*) <<" bytes.\n";



	return 0;
}