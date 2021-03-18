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
	
	
	
	Rectangle r{Point{400,300},400,400};
	r.set_fill_color(Color::white);
	
	
	Rectangle a1{Point{450,450},100,100};
	Rectangle a2{Point{650,450},100,100};
	a1.set_fill_color(Color::yellow);
	a2.set_fill_color(Color::yellow);
	
	Rectangle door{Point{565,575},75,125};
	door.set_fill_color(Color::dark_red);
	
	Closed_polyline roof;
	roof.add(Point{400,300});
	roof.add(Point{800,300});
	roof.add(Point{600,50});
	roof.set_fill_color(Color::red);
	
	Circle doorh {Point{575,645},10};
	doorh.set_fill_color(Color::black);	
	
	Rectangle chim{Point{660,100},50,100};
	chim.set_fill_color(Color::dark_red);
	
	win.attach(r);
	win.attach(a1);
	win.attach(a2);
	win.attach(door);
	win.attach(roof);
	win.attach(doorh);
	win.attach(chim);
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
