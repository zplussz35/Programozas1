#include "Simple_window.h"
#include"Graph.h"
#include"std_lib_facilities.h"

using namespace Graph_lib;

double one(double){return 1;}
double slope(double d){return d/2;}
double square(double d){return d*d;}
double sloping_cos(double d){return cos(d)+slope(d);}

int main()
try{
	
	
	const int xmax=600;
	const int ymax=600;
	const int xlen=400;
	const int ylen=400;
	const int xscale=20, yscale=20;
	const int x_min=-10,x_max=11;
	const int pcount=400;
	Point origo{xmax/2,ymax/2};
	Simple_window win {Point{100,100},xmax,ymax,"Function graphs."};
	
	
	Axis x {Axis::x,Point{100,ymax/2},xlen,xlen/xscale,"1==20 pixels"};
	Axis y {Axis::y,Point{xmax/2,ylen+100},ylen,ylen/yscale,"1==20 pixels"};
	x.set_color(Color::red);
	y.set_color(Color::red);

	Function f{one,x_min,x_max,origo,pcount,xscale,yscale};
	Function f2{slope,x_min,x_max,origo,pcount,xscale,yscale};
	Function f3{square,x_min,x_max,origo,pcount,xscale,yscale};
	Function f4{cos,x_min,x_max,origo,pcount,xscale,yscale};
	f4.set_color(Color::blue);
	Function f5{sloping_cos,x_min,x_max,origo,pcount,xscale,yscale};

	Text t{Point{90,380},"x/2"};

	
	
	
	
	
	
	
	win.attach(x);
	win.attach(y);
	win.attach(f);
	win.attach(f2);
	win.attach(f3);
	win.attach(f4);
	win.attach(f5);
	win.attach(t);
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
