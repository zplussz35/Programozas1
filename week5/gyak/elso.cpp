#include "Simple_window.h"
#include"Graph.h"
#include"std_lib_facilities.h"

#include<iostream>
#include<vector>

using namespace Graph_lib;

double one(double){return 1;}

double slope(double x){return x/2;}

double square(double d){return d*d;}

double sloping_cos(double d){return cos(d)+slope(d);}

int fact(int n)
{
	int r=1;
	while(n>1)
	{
		r*=n;
		--n;
	}
	return r;
}
double term(double x, int n){return pow(x,n)/fact(n);}
double expe(double x,int n)
{
	double sum=0;
	for(int i=0;i<n;++i) sum+=term(x,i);
	return sum;
}

int main()
try{
	int xmax=600;
	int ymax=400;

	int x_orig=xmax/2;
	int y_orig=ymax/2;

	int rmin=-11;
	int rmax=11;

	int n_points=400;

	Simple_window win {Point{100,100},xmax,ymax,"Canvas"};

	Point origo{x_orig,y_orig};

	int xlength=xmax-40;
	int ylength=ymax-40;

	int xscale=30,yscale=30;

	/*Function s(one,rmin,rmax,origo,n_points,xscale,yscale);
	Function sl(slope,rmin,rmax,origo,n_points,xscale,yscale);
	Function sq(square,rmin,rmax,origo,n_points,xscale,yscale);
	Function sl_cos([](double d){return cos(d)+slope(d);},rmin,rmax,origo,n_points,xscale,yscale);
	sl_cos.set_color(Color::red);

	Text ts {Point{100,y_orig-40},"one"};
	Text ts2 {Point{100,y_orig+y_orig/2-20},"x/2"};
	Text ts3 {Point{x_orig-100,20},"x*x"};*/

	Function real_exp(exp,rmin,rmax,origo,200,xscale,yscale);

	for(int n=0;n<50;++n)
	{
		ostringstream ss;
		ss<<"exp approximation; n== "<<n;
		win.set_label(ss.str());

		Function e ([n](double d){return cos(d)+slope(d);},rmin,rmax,origo,n_points,xscale,yscale);
		win.attach(e);
		win.wait_for_button();
		win.detach(e);
	}


	Axis x {Axis::x,Point{20,y_orig},xlength,xlength/xscale,"x"};
	Axis y {Axis::y,Point{x_orig,ylength+20},ylength,ylength/yscale,"y"};
	x.set_color(Color::red);
	y.set_color(Color::red);
	win.set_label("Function graphing: label function");


	/*win.attach(s);
	win.attach(sl);
	win.attach(sq);
	win.attach(sl_cos);*/
	win.attach(x);
	win.attach(y);
	//win.attach(ts);
	//win.attach(ts2);
	//win.attach(ts3);
	win.attach(real_exp);
	
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
