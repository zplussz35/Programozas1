#include<iostream>
#include <vector>
#include<list>

using namespace std;

int main()
{
	int arr[]={0,1,2,3,4,5,6,7,8,9};
	vector<int> v={0,1,2,3,4,5,6,7,8,9};
	list<int>l ={0,1,2,3,4,5,6,7,8,9};

	int arr2[10];
	int size=sizeof(arr)/sizeof(arr[0]);
	for(int i=0;i<size;i++)
	{
		arr2[i]=arr[i]+2;
	}
	vector<int> v2=v;
	list<int> l2 =l;



	return 0;
}