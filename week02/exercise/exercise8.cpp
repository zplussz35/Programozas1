#include "Simple_window.h"
#include"Graph.h"
#include"std_lib_facilities.h"

#include<string>
#include<iostream>
#include<vector>

using namespace Graph_lib;

int main()
try{
	
	
	Simple_window win {Point{100,100},1280,720,"Ablak 0"};
	
	Circle r1{Point{200,200},50};
	r1.set_color(Color::blue);
	
	Circle r2{Point{300,200},50};
	r2.set_color(Color::black);
	
	Circle r3{Point{400,200},50};
	r3.set_color(Color::red);
	
	Circle r4{Point{250,250},50};
	r4.set_color(Color::yellow);
	
	Circle r5{Point{350,250},50};
	r5.set_color(Color::green);
	
		
	win.attach(r1);
	win.attach(r2);
	win.attach(r3);
	win.attach(r4);
	win.attach(r5);
	win.wait_for_button();
	
	return 0;
}

catch(exception& e)
{
	cerr<<"exeption: "<<e.what()<<'\n';
	return 1;
}
catch(...)
{
	cerr<<"error\n";
	return 2;
}
