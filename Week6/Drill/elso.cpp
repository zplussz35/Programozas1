// g++ elso.cpp Graph.cpp Window.cpp GUI.cpp Lines_window.cpp -o main `fltk-config --ldflags --use-images` -Wno-deprecated

#include "Lines_window.h"


int main()
try{
	
	Lines_window win {Point{100,100},600,400,"lines"};
	return gui_main();
	
	
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
