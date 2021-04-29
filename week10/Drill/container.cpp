#include<iostream>
#include <vector>
#include<list>

using namespace std;

template<typename Iter1,typename Iter2>
Iter2 my_copy(Iter1 f1,Iter1 e1,Iter2 f2)
{
	while(f1!=e1){
		*f2=*f1;
		f1++;
		f2++;	
	}
	return f2;
	
}

int main()
{
	int arr[]={0,1,2,3,4,5,6,7,8,9};
	vector<int> v={0,1,2,3,4,5,6,7,8,9};
	list<int>l ={0,1,2,3,4,5,6,7,8,9};

	int size=sizeof(arr)/sizeof(arr[0]);

	cout<<"Array: ";
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	cout<<"vector elements: ";
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;

	cout<<"list elements: ";
	for(int n: l)
	{
		cout<<n<<" ";
	}
	cout<<endl;





	int arr2[10];
	
	for(int i=0;i<size;i++)
	{
		arr2[i]=arr[i]+2;
	}



	vector<int> v2=v;
	list<int> l2;

	for(int i=0;i<v2.size();++i)
	{
		v2[i]+=3;
	}

	for(int i=0;i<12;++i)
	{
		l2.push_back(i+5);

	}

	cout<<"Array2 elements: ";
	for(int i=0;i<size;i++)
	{
		cout<<arr2[i]<<" ";
	}
	cout<<endl;

	cout<<"vector2 elements: ";
	for(int i=0;i<v.size();i++)
	{
		cout<<v2[i]<<" ";
	}
	cout<<endl;

	list<int>::iterator iter=l2.begin();
	cout<<"list2 elements: ";
	for( iter;iter!=l2.end();iter++)
	{
		cout<<*iter<<" ";
		
	}
	cout<<endl;
	
	my_copy(arr2,arr2+size,v.begin());
	cout<<"The new vector2 is: ";
	for(int i=0;i<v.size();i++)
	{
		cout<<v2[i]<<" ";
	}
	cout<<endl;

	my_copy(l2.begin(),l2.end(),arr2+size);
	cout<<"The new array2 is: ";
	for(int i=0;i<size;i++)
	{
		cout<<arr2[i]<<" ";
	}
	cout<<endl;


	return 0;
}