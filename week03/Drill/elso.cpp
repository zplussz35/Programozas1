#include "Simple_window.h"
#include"Graph.h"
#include"std_lib_facilities.h"

#include<iostream>
#include<vector>

using namespace Graph_lib;

int main()
try{
	
	//1. feladat
	Simple_window win{Point{100,100},1000,800,"Ablak 0"};
	
	//2. feladat
	int x_size = win.x_max(); 
	int y_size = win.y_max();
	int x_grid = 100;
	int y_grid = 100;
	
	Lines grid;
	
	for (int x=x_grid; x<=x_size-200; x+=x_grid)
	grid.add(Point{x,0},Point{x,y_size}); 
	for (int y = y_grid; y<y_size; y+=y_grid)
	grid.add(Point{0,y},Point{x_size-200,y});
	
	win.attach(grid);
	win.wait_for_button();
	
	//3.feladat:
	
	Vector_ref<Rectangle> vr;
	int lepes=100;
	int j=0;
	for(int i=0;i<8*lepes;i+=lepes)
	{
		if(j<8){
		vr.push_back(new Rectangle{Point{i,i},100,100});
		vr[j].set_fill_color(Color::red);
		win.attach(vr[j]);
		j++;
		}
		else{ break;}
	}
	
	
	win.wait_for_button();
	
	//4. feladat:
	
	Image ii {Point{400,200},"hattyu.jpg"};
	Image ii2 {Point{600,0},"hattyu.jpg"};
	Image ii3 {Point{0,400},"hattyu.jpg"};
	
	win.attach(ii);
	win.attach(ii2);
	win.attach(ii3);
	
	win.wait_for_button();
	
	//5. feladat:
	
	Image pi{Point{0,0},"alien.gif"};
	win.attach(pi);
	win.wait_for_button();
	
	for(int i=0;i<8;i++)
	{
		pi.move(100,100);
		win.wait_for_button();
		
		
	}
	
	
	
	
	
	
	
	
	
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
