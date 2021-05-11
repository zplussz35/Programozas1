#include<iostream>

using namespace std;

class B1 {
	public:
	void f() const { cout<<"B1::f()\n";}
	virtual void vf() const {cout<<"B1::vf()\n";}
	virtual void pvf()=0;
};

struct B2 {
	virtual void pvf()=0;

};
struct D21:B2 {
	string data="D21::pvf()";
	void pvf() override{cout<<data;}

};

struct D22:D21{
	int data=0;
	void f(B2& b2){b2.pvf();}

};

struct D1:B1{
	void f()  {cout<<"D1::f()\n";}
	void vf() const {cout<<"D1::vf()\n";}
	void pvf() override {cout<<"D1::pvf()\n";}
	
};

struct D2:D1{
	void f()const {cout<<"D2::f()\n";}
	void vf() {cout<<"D2::vf()\n";}
	void pvf() override { cout<<"D2::pvf()\n";}
};

void call ( B1& b)
{
	b.vf();
	b.f();
	b.pvf();
	}

int main()
{
	//B1 b;
	D1 d;
	D2 dd;
	
	//call(b);
	call(d);
	call(dd);
	
	
	
	
	
	
	cout<<"Call eng\n";

	//B2 b2;
	D21 d21; cout<<'\n';
	D22 d22;
	
	//b2.pvf();
	d21.pvf(); cout<<'\n';
	d22.pvf();

	return 0;

}
