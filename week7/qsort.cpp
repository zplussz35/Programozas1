#include <stdio.h>
#include <stdlib.h>

using namespace std;

int compare(const void*,const void*);

int main()
{
	int arr[5]={52,14,50,48,13};
	int num,width,i;
	num=sizeof(arr)/sizeof(arr[0]);
	width=sizeof(arr[0]);
	qsort( (void*)arr,num,width,compare);
	for(i=0;i<5;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}

int compare(const void* elem1,const void*elem2){

	if((*(int*)elem1)==(*(int*)elem2)) return 0;
	else if((*(int*)elem1)<(*(int*)elem2)) return -1;
	else return 1;
}