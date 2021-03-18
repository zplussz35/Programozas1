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
	//1. feladat: 
	win.set_label("1. feladat:");
	
	Rectangle r(Point{100,100},150,100);
	r.set_color(Color::blue);
	
	Polygon poly;
	poly.add(Point{300,100});
	poly.add(Point{300,200});
	poly.add(Point{450,200});
	poly.add(Point{450,100});
	poly.set_color(Color::red);
	
	win.attach(r);
	win.attach(poly);
	win.wait_for_button();
	
	//2. feladat:
	win.set_label("2. feladat:");
	
	Rectangle r2{Point{100,300},100,30};
	Text t {Point{120,320},"Howdy!"};
	
	win.attach(r2);
	win.attach(t);
	win.wait_for_button();
	
	//3. feladat:
	win.set_label("3. feladat:");
	
	Text t2 {Point {300,400},"T"};
	Text t3 {Point {400,400},"Z"};
	t2.set_font_size(150);
	t3.set_font_size(150);
	t2.set_color(Color::red);
	t3.set_color(Color::green);
	t2.set_font(Font::courier);
	t3.set_font(Font::courier);
	
	
	win.attach(t2);
	win.attach(t3);
	win.wait_for_button();
	
	//4. feladat:
	win.set_label("4. feladat:");
	
	Vector_ref<Rectangle> vr;
	int w=50;
	for(int row=0;row<3;++row)
		for(int col=0;col<3;++col)
		{
			vr.push_back(new Rectangle {Point {550+w*col,300+w*row},w,w});
			int i=vr.size() - 1;
			i%2==0?vr[i].set_fill_color(Color::red):vr[i].set_fill_color(Color::white);
			win.attach(vr[i]);
			
		}
	
	win.wait_for_button();
	
	//5. feladat:
	
	win.set_label("5. feladat:");
	
	Rectangle huge {Point{150,150}, x_max()*2/3,y_max()*3/4};
	huge.set_style(Line_style(Line_style::solid,8));
	huge.set_color(Color::red);
	
	win.attach(huge);
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
