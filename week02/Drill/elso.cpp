#include "Simple_window.h"
#include"Graph.h"
#include"std_lib_facilities.h"

using namespace Graph_lib;

int main()
try{
	
	
	const int xmax=1280;
	const int ymax=720;
	const int xlen=xmax-40;
	const int ylen=ymax-40;
	Point origo{xmax/2,ymax/2};
	Simple_window win {Point{100,100},xmax,ymax,"My window"};
	
	
	Axis x {Axis::x,Point{20,ymax/2},xlen,40,"X Axis"};
	Axis y {Axis::y,Point{xmax/2,ylen+20},ylen,40,"Y Axis"};
	x.label.set_color(Color::dark_red);
	y.label.set_color(Color::blue);
	
	
	
	Function cosf {[](double x){return cos(x);},-11,11,origo,1000,50,50};
	
	Polygon poly;
	poly.add(Point{740,100});
	poly.add(Point{840,50});
	poly.add(Point{940,100});
	poly.set_color(Color::red);
	poly.set_style(Line_style::dash);
	
	Rectangle r {Point{250,610},250,100};
	
	Closed_polyline polyrect;
	polyrect.add(Point{125,200});
	polyrect.add(Point{125,300});
	polyrect.add(Point{375,300});
	polyrect.add(Point{375,200});
	polyrect.add(Point{250,100});
	polyrect.set_fill_color(Color::green);
	polyrect.set_style(Line_style(Line_style::dash,2));
	
	Text t {Point{890,610},"Hello Graphics!"};
	t.set_font(Font::times_bold);
	t.set_font_size(30);
	t.set_color(Color::red);
	
	Image ii {Point{340,160},"badge.jpg"};
	
	Circle c{Point{100,200},50};
	Ellipse e {Point{100,200},75,25};
	e.set_color(Color::dark_red);
	Mark m{Point{100,200},'X'};
	
	ostringstream oss;
	oss<<"screen size: "<<x_max()<<"*"<<y_max()<<"; windows size: "<<win.x_max()<<"*"<<win.y_max();
	Text sizes {Point{100,20},oss.str()};
	
	
	
	
	win.attach(x);
	win.attach(y);
	win.wait_for_button();
	
	win.set_label("Ablak 2");
	win.attach(cosf);
	win.wait_for_button();
	
	win.set_label("Ablak 3");
	win.attach(poly);
	win.attach(r);
	win.attach(polyrect);
	win.attach(t);
	win.attach(ii);
	win.wait_for_button();
	ii.move(100,250);
	win.attach(ii);
	win.wait_for_button();
	win.attach(e);
	win.attach(c);
	win.attach(m);
	win.wait_for_button();
	win.attach(sizes);
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
