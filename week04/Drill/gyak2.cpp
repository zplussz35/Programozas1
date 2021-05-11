#include<iostream>
#include<string>

using namespace std;

class Shape{
private:
	string color;

public:
	
	virtual void print_color()=0;

};
class Point:public Shape{
private:
	double x;
	double y;
public:
	print_color()


};

class Circle:public Shape{
private:
	double r;

};



int main()
{
	return 0;
}