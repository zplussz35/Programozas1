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
