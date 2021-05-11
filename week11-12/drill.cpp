#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<fstream>
#include<string>
#include<algorithm>


using namespace std;

struct Item{
	string name;
	int iid;
	double value;
	Item(){iid=0;value=0.0;}
	Item(string newname,int newid, double newvalue): name{newname},iid{newid},value{newvalue}{}
};


//-----------------------------functions for vector------------------------------

void sortbyName(vector<Item>& v)
{
	sort(v.begin(),v.end(),[](Item i1, Item i2){return (i1.name<i2.name);});
}

void sortbyID(vector<Item>& v){
	sort(v.begin(),v.end(),[](Item i1, Item i2){return (i1.iid<i2.iid);});
}

void sortbyValue_desc(vector<Item>& v){
	sort(v.begin(),v.end(),[](Item i1, Item i2){return (i1.value>i2.value);});
}

void removebyName(vector<Item>& v, string name){
	remove_if(v.begin(),v.end(),[name](Item i){return i.name==name;});
	v.pop_back();
}
void removebyID(vector<Item>& v,int id){
	remove_if(v.begin(),v.end(),[id](Item i){return i.iid==id;});
	v.pop_back();
}

//-------------------------------functions for list-----------------------------

void sortlistbyName(list<Item>& v)
{
	v.sort([](Item i1, Item i2)->bool {return (i1.name<i2.name);});
}

void sortlistbyID(list<Item>& v){
	v.sort([](Item i1, Item i2)->bool {return (i1.iid<i2.iid);});
}

void sortlistbyValue(list<Item>& v){
	v.sort([](Item i1, Item i2)->bool {return (i1.value>i2.value);});
}

void removelistbyName(list<Item>& v, string name){
	v.remove_if([name](Item i)->bool {return i.name==name;});
	v.pop_back();
}
void removelistbyID(list<Item>& v,int id){
	v.remove_if([id](Item i)->bool {return i.iid==id;});
	v.pop_back();
}

//-----------------------------functions for map-----------------------------

istream& operator>>(istream& in,map<string,int>& m)
{  
	string s; int i;
	cout<<"Please give the string: ";
	in>>s;
	cout<<"Please give the int: ";
	in>>i;
	m.insert(pair<string,int>(s,i));



	return in;
}



int main()
{	

	//-----------------------vector---------------------------
	Item item;
	vector<Item> vi;

	string name;
	int id;
	double value;

	
	ifstream ReadMyFile("source.txt");
	if(ReadMyFile.is_open())
	{
		while(ReadMyFile>>name>>id>>value){
			item.name=name;
			item.iid=id;
			item.value=value;
			vi.push_back(item);
		}

		ReadMyFile.close();

	}
	else cout<<"Unable to open this file!";

	cout<<"\n\n----------The vector----------\n\n"<<endl;	

	for(auto x:vi)
	cout<<x.name<<' '<<x.iid<<' '<<x.value<<'\n';

	cout<<"\n*Sorted by name:\n\n";
	sortbyName(vi);

	for(auto x:vi)
	cout<<x.name<<' '<<x.iid<<' '<<x.value<<'\n';

	cout<<"\n*Sorted by id:\n\n";
	sortbyID(vi);

	for(auto x:vi)
	cout<<x.name<<' '<<x.iid<<' '<<x.value<<'\n';

	cout<<"\n*Sorted by value desc:\n\n";
	sortbyValue_desc(vi);

	for(auto x:vi)
	cout<<x.name<<' '<<x.iid<<' '<<x.value<<'\n';


	vi.push_back(Item("horse shoe",99,12.34));
	vi.push_back(Item("Canon s400",9988,499.95));

	cout<<"\n*Add 2 elements to the vector sorted by value:\n\n";
	sortbyValue_desc(vi);
for(auto x:vi)
	cout<<x.name<<' '<<x.iid<<' '<<x.value<<'\n';
	
	removebyName(vi,"jacket");
	removebyID(vi,5);

	cout<<"\n*After removed 2 elements from the vector sorted by value:\n\n";
	sortbyValue_desc(vi);
for(auto x:vi)
	cout<<x.name<<' '<<x.iid<<' '<<x.value<<'\n';

//-----------------------list-------------------------------

list<Item> li;
ifstream ReadMyFile2("source.txt");
if(ReadMyFile2.is_open())
{
	while(ReadMyFile2>>name>>id>>value)
	{
		item.name=name;
		item.iid=id;
		item.value=value;
		li.push_back(item);

	}
	ReadMyFile2.close();
}
else cout<<"Unable to open this file!"<<endl;

cout<<"\n\n----------The list----------\n\n"<<endl;	

for(auto x:li)
	cout<<x.name<<' '<<x.iid<<' '<<x.value<<'\n';

	cout<<"\n*Sorted by name:\n\n";
	sortlistbyName(li);

	for(auto x:li)
	cout<<x.name<<' '<<x.iid<<' '<<x.value<<'\n';

	cout<<"\n*Sorted by id:\n\n";
	sortlistbyID(li);

	for(auto x:li)
	cout<<x.name<<' '<<x.iid<<' '<<x.value<<'\n';

	cout<<"\n*Sorted by value desc:\n\n";
	sortlistbyValue(li);

	for(auto x:li)
	cout<<x.name<<' '<<x.iid<<' '<<x.value<<'\n';


	li.push_back(Item("horse shoe",99,12.34));
	li.push_back(Item("Canon s400",9988,499.95));

	cout<<"\n*Add 2 elements to the list sorted by value:\n\n";
	sortlistbyValue(li);
for(auto x:li)
	cout<<x.name<<' '<<x.iid<<' '<<x.value<<'\n';
	
	removelistbyName(li,"jacket");
	removelistbyID(li,5);

	cout<<"\n*After removed 2 elements from the list sorted by value:\n\n";
	sortlistbyValue(li);
for(auto x:vi)
	cout<<x.name<<' '<<x.iid<<' '<<x.value<<'\n';


//-----------------------Tha map------------------------------


map<string,int> msi;
msi["first"]=1;
msi["second"]=2;
msi["third"]=3;
msi["fourth"]=4;
msi["fifth"]=5;
msi["sixth"]=6;
msi["seventh"]=7;
msi["eighth"]=8;
msi["ninth"]=9;
msi["tenth"]=10;


cout<<"\n\n----------The map-----------\n\n"<<endl;	
for(auto elem:msi)
{
	cout<<"msi["<<elem.first<<"]= "<<elem.second<<endl;
}

msi.erase(msi.begin(),msi.end());

cout<<"\nAfter deleting the elements:"<<endl;

for(auto elem:msi)
	cout<<"msi["<<elem.first<<"]= "<<elem.second<<endl;


cout<<"Please insert 10 elements to the map:\n";

for(int i=0;i<10;i++)
{
	cout<<i+1<<".\n";
	cin>>msi;
}

cout<<"\nAfter inserting 10 elements to the map:"<<endl;


for(auto elem: msi)
{
	cout<<"msi["<<elem.first<<"]= "<<elem.second<<endl;
}

int sum=0;

for(auto elem:msi)
{
	sum+=elem.second;
}

cout<<"\nThe sum of the ints: "<<sum<<endl;



map<int,string> mis;

for(auto elem:msi)
{
	mis.insert(pair<int,string>(elem.second,elem.first));
}

cout<<"\ncopy 10 elements to mis:\n";

for(auto elem:mis)
{
	cout<<"mis["<<elem.first<<"]= "<<elem.second<<endl;
}



//-----------------------the vector again--------------------------------------



cout<<"\n\n-------------------The vector again--------------------------\n\n";

vector<double> vd;
double d;

ifstream ReadmyFile3("source2.txt");

if(ReadmyFile3.is_open())
{
	while(ReadmyFile3>>d)
		vd.push_back(d);
	ReadmyFile3.close();
}
else cout<<"Unable to open this file!"<<endl;

for(int i=0;i<vd.size();i++)
{
	cout<<vd[i]<<' ';
}
cout<<endl;

vector<int> vi2;




for(int i=0;i<vd.size();i++)
{
	vi2.push_back(i);
}

for(int i=0;i<vi2.size();i++)
{
	vi2[i]=vd[i];
}

cout<<"\nThe elements of vi2 and vd:\nvi\tvd\n";
for(int i=0;i<vi2.size();i++)
{
	cout<<vi2[i]<<'\t'<<vd[i]<<endl;
}

long double sum2=0.0;
for(int i=0;i<vd.size();i++)
{
	sum2+=vd[i];
}
cout<<"\nThe sum of vd elements: "<<sum2<<endl;

long double sum3=0.0;

for(int i=0;i<vi2.size();++i)
{
	sum3+=vi2[i];
}
cout<<"\nDifference between vd("<<sum2<<") and vi2("<<sum3<<"): "<<sum2-sum3<<endl;

reverse(vd.begin(),vd.end());

cout<<"\n Double vector in reverse:\n";

for(int i=0;i<vd.size();i++)
	cout<<vd[i]<<'\n';

double mean=(double)sum2/vd.size();
cout<<"\nThe mean of vd: "<<mean<<endl;


std::vector<double> vd2(20);

copy_if(vd.begin(),vd.end(),vd2.begin(),[mean](double x){ return x<mean;});

cout<<"The vd values that less than mean("<<mean<<"):\n";
for(int i=0;i<vd2.size();++i)
{
	cout<<vd2[i]<<'\n';
}

sort(vd.begin(),vd.end());

cout<<"\nSorted double vector:\n";
for(int i=0;i<vd.size();++i)
	cout<<vd[i]<<'\n';
	return 0;
}

