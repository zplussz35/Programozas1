#include<iostream>
#include <vector>
#include<list>
#include<algorithm>
#include<iterator>

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


//Copy
 

	int arr2[10];
	
	for(int i=0;i<size;i++)
	{
		arr2[i]=arr[i];
	}



	vector<int> v2=v;
	list<int> l2(l);

cout<<"copies:"<<endl;
cout<<"Array2: ";
	for(int i=0;i<size;i++)
	{
		cout<<arr2[i]<<" ";
	}
	cout<<endl;

	cout<<"vector2 elements: ";
	for(int i=0;i<v2.size();i++)
	{
		cout<<v2[i]<<" ";
	}
	cout<<endl;

	cout<<"list2 elements: ";
	for(int n: l2)
	{
		cout<<n<<" ";
	}
	cout<<endl;

//value changes:


	for(int i=0;i<size;i++)
	{
		arr2[i]+=2;
	}

	for(int i=0;i<v2.size();++i)
	{
		v2[i]+=3;
	}


	int l2_size=l2.size();

	for(int i=0;i<l2_size;i++)
	{
	
		l2.pop_back();
	}


	for(int i=0;i<l2_size;++i)
	{
		l2.push_back(i+5);

	}
	cout<<"changes of copied containers:"<<endl;

	//output the new containers

	cout<<"Array2 elements: ";
	for(int i=0;i<size;i++)
	{
		cout<<arr2[i]<<" ";
	}
	cout<<endl;

	cout<<"vector2 elements: ";
	for(int i=0;i<v2.size();i++)
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

	//using my_copy
	
	cout<<"After using my_copy:"<<endl;
	my_copy(arr2,arr2+size,v2.begin());
	cout<<"The new vector2 is: ";
	for(int i=0;i<v2.size();i++)
	{
		cout<<v2[i]<<" ";
	}
	cout<<endl;

	my_copy(l2.begin(),l2.end(),arr2);
	cout<<"The new array2 is: ";
	for(int i=0;i<size;i++)
	{
		cout<<arr2[i]<<" ";
	}
	cout<<endl;

	//using find
	cout<<"using find:"<<endl;
	vector<int>::iterator viter;
	list<int>::iterator liter;

	viter=find(v2.begin(),v2.end(),3);
	if(viter!=v2.end())
		
			cout<<"Element found in v2 vector: "<<*viter<<", at position: "<<(viter-v2.begin())<<'\n';
		
	else
			cout<<"Element not found in v2 vector";


	liter=find(l2.begin(),l2.end(),27);
	if(liter!=l2.end())
		cout<<"Element found in l2 list: "<<*liter<<endl;
	else
		cout<<"Element not found in l2 list."<<endl;

	return 0;
}