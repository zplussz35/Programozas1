#include<iostream>
#include<string>
#include <vector>

using namespace std;

struct Person{
	Person(){age=0;}

	Person(string s,int i):first_name{s},second_name{s},age{i}{
		
		char badchar[]={';',':','\"','\'','[',']','*','&','^','%','$','#','@','!'};

		if(age<0||age>150) throw exception();
		int len = sizeof(badchar)/sizeof(badchar[0]);
		for(int i=0;i<len;++i)
		{
			if(first_name.find(badchar[i])!=string::npos) throw exception();
		}
		

	}
	string getname()const {return first_name;}
	int getage()const {return age;}
	void setname(string newname){ first_name=newname;second_name=newname;}
	void setage(int newage){age=newage;}
private:
	string first_name;
	string second_name;
	int age;
};

int main()
try{
	vector<Person> persons;

	Person p("Goofy",63);
	cout<<"name: "<<p.getname()<<", age: "<<p.getage()<<endl;

	Person pp;
	cout<<"name: "<<pp.getname()<<", age: "<<pp.getage()<<endl;

	
	string newname;
	int newage;
	while(cin>>newage>>newname)
	{
		Person pers(newname,newage);
		
		persons.push_back(pers);
		
		

	}
	for(int i=0;i<persons.size();++i)
	{
		cout<<persons[i].getname()<<" "<<persons[i].getage()<<endl;
	}



	return 0;
}catch(exception& e){
	cerr<<"exception: "<<e.what()<<endl;
	return 1;
}
