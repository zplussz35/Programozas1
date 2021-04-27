#include<iostream>
#include<string>
#include <vector>
#include "std_lib_facilities.h"

using namespace std;

struct Person{
private:
	string first_name;
	string second_name;
	int _age;
public:
	Person(){_age=0;}
	Person(string name,int age,int name_chosen);

	friend ostream&  operator<<(ostream &output, const Person &P){
		output<<"name: ";

		if(P.first_name=="0")
		{
			output<<P.second_name;
		}
		else if(P.second_name=="0")
		{
			output<<P.first_name;
		}
		output<<"\nage: "<<P._age;
		
		
		return output;
		
	}
	friend istream& operator>>(istream &input, Person &P){
		int name_chosen;
		cout<<"Give Person's name and age:\nWhich name do you want to give? (1-first,2-second): ";
		cin>>name_chosen;
		cout<<"Name: ";
		if(name_chosen==1)
		{
			input>>P.first_name;
			P.second_name="0";
		}
		else if(name_chosen==2)
		{
			input>>P.second_name;
			P.first_name="0";
		}
		else throw exception();
		cout<<"Age: ";
		input>>P._age;
		return input;
		
	}
	
	string getname() const;

	
	int getage()const {return _age;}
	void setname(string newname,int name_chosen);	

	void setage(int newage){_age=newage;}
	

};

int main()
try{
	
	Person a;
	//cin>>a;
	//cout<<a;
	
	Person p("Goofy",63,1);
	cout<<"\nname: "<<p.getname()<<", age: "<<p.getage()<<endl;

	vector<Person> persons;
	

	cout<<"Type Persons data: (if you type '0' to the name, it finishes the input.)"<<endl;

	string name;
	int age;
	int name_chosen;
	int i=1;

	while(true)
	{
		cout<<'\t'<<i<<'\n';
		cout<<"which name do you want to give? (1-first,2-second): ";
		cin>>name_chosen;
		if (name_chosen!=1||name_chosen!=2) error("You must give 1 or 2!");
		cout<<"Name: ";
		cin>>name;
		if(name=="0") break;
		cout<<"Age: ";
		cin>>age;
		Person person(name,age,name_chosen);
		persons.push_back(person);
		++i;
	}

	cout<<"\n\nThe persons' list:\n\tname\tage\n\n";

	for(int i=0;i<persons.size();++i)
	{
		cout<<i+1<<".\t"<<persons[i].getname()<<"\t"<<persons[i].getage()<<endl;
	}




	


	return 0;
}catch(exception& e){
	cerr<<"exception: "<<e.what()<<endl;
	return 1;
}


	Person::Person(string name,int age,int name_chosen){

		if(name_chosen==1)
		{
			first_name=name;
			second_name="0";
		}
		else if(name_chosen==2)
		{
			second_name=name;
			first_name="0";
		}
		_age=age;


		//Name and age is correct?

		char badchar[]={';',':','\"','\'','[',']','*','&','^','%','$','#','@','!'};

		if(_age<0||_age>=150) error("Not allowed age! (allowed: 0-149)");

		int len = sizeof(badchar)/sizeof(badchar[0]);
		for(int i=0;i<len;++i)
		{
			if(first_name.find(badchar[i])!=string::npos) error("Not allowed character in name!");
		}
		

	}
	
	string Person::getname() const {
		if(first_name=="0"&&second_name!="0")
		{
			return second_name;	
		}
		else if(second_name=="0"&&first_name!="0")
		{
			return first_name;
		}
		else return "Not name is given!";
	}
	void Person::setname(string newname,int name_chosen){ 
		if(name_chosen==1)
		{
			first_name=newname;
			second_name="0";
		}
		else if(name_chosen==2)
		{
			second_name=newname;
			first_name="0";
		}
		else{
			first_name=second_name="Not name is given!";
		}	
	}