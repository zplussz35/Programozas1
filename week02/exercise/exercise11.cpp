#include "Simple_window.h"
#include "Graph.h"

#include <string>
#include <iostream>
#include <vector>

using namespace Graph_lib;

int main()
try {

	Point t1 {100,100};
	Simple_window win {t1, 600, 400, "Chapter 12 ex 11"};
	
	constexpr double PI = 3.14159265;
	const int X = win.x_max() / 2 - 50;
	const int Y = win.y_max() / 2 - 50;
	
	//Triangle
	Polygon tri;
	int alt = sin(60*PI/180)*100;
	tri.add(Point{X, Y + alt});
	tri.add(Point{X + 50, Y});
	tri.add(Point{X + 100, Y + alt});
	tri.set_color(Color::red);
	win.attach(tri);
	
	//Square
	Rectangle sqr {Point {X, Y}, 100, 100};
	sqr.set_color(Color::green);
	win.attach(sqr);
	
	//Pentagon
	Polygon pent;
	int pr = 50 / sin(36*PI/180);
	int px = 300;
	int py = 200 - pr;
	
	pent.add(Point{px,py});
	
	px += sin(54*PI/180)*100;
	py += sin(54*PI/180)*100;
	pent.add(Point{px,py});
	
	px -= sin(72*PI/180)*100;
	py += sin(72*PI/180)*100;
	pent.add(Point{px,py});
	
	px -= 100;
	pent.add(Point{px,py});
	
	px -= sin(72*PI/180)*100;
	py -= sin(72*PI/180)*100;
	pent.add(Point{px,py});
	
	pent.set_color(Color::blue);
	win.attach(pent);
	

	win.wait_for_button();
	
}
catch(exception& e) {
	cerr << "exception" << e.what() << '\n';
	return 1;
}
catch(...) {
	cerr << "error\n";
	return 2;
}
