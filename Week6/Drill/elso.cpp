#include "GUI.h"


using namespace Graph_lib;

struct Lines_window : Graph_lib::Window {
	Lines_window(Point xy, int w, int h, const string& title);
//private:
	//data:
	Open_polyline lines;
//widgets:
	Button next_button; // add (next_x,next_y) to lines
	Button quit_button;
	In_box next_x;
	In_box next_y;
	Out_box xy_out;
	Menu color_menu;
	Menu lines_menu;
	Button color_menu_button;
	Button lines_menu_button;


	void change_color(Color c){ lines.set_color(c); }
	void change_line_style(Line_style lst){lines.set_style(lst);}
	void hide_color_menu(){ color_menu.hide(); color_menu_button.show();}
	void hide_lines_menu(){ lines_menu.hide(); lines_menu_button.show();}


// the actions:
	void red_pressed(){ change_color(Color::red);hide_color_menu(); }
	void blue_pressed(){ change_color(Color::blue);hide_color_menu(); }
	void black_pressed(){ change_color(Color::black);hide_color_menu(); }

	void solid_pressed(){ change_line_style(Line_style::solid);hide_lines_menu(); }
	void dash_pressed(){ change_line_style(Line_style::dash);hide_lines_menu(); }
	void dot_pressed(){ change_line_style(Line_style::dot);hide_lines_menu(); }

	void color_menu_pressed(){ color_menu_button.hide(); color_menu.show();}
	void lines_menu_pressed(){ lines_menu_button.hide(); lines_menu.show();}


	void next();
	void quit();
//callback functions
 	static void cb_red(Address, Address); // callback for red button
 	static void cb_blue(Address, Address); // callback for blue button
 	static void cb_black(Address, Address); // callback for black button
 	static void cb_color_menu(Address, Address);
 	static void cb_next(Address, Address);
 	static void cb_quit(Address, Address);
 	static void cb_lines_menu(Address, Address);


 	static void cb_solid(Address, Address); 
 	static void cb_dash(Address, Address);
 	static void cb_dot(Address, Address);
};

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
:Window{xy,w,h,title},
next_button{Point{x_max()-150,0}, 70, 20, "Next point", cb_next},
quit_button{Point{x_max()-70,0}, 70, 20, "Quit",cb_quit},
next_x{Point{x_max()-310,0}, 50, 20, "next x:"},
next_y{Point{x_max()-210,0}, 50, 20, "next y:"},
xy_out{Point{100,0}, 100, 20, "current (x,y):"},
color_menu{Point{x_max()-70,40},70,20,Menu::vertical,"color"},
color_menu_button{Point{x_max()-80,30}, 80, 20, "color menu", cb_color_menu},
lines_menu{Point{x_max()-150,40},70,20,Menu::vertical,"Line"},
lines_menu_button{Point{x_max()-160,30}, 80, 20, "Line menu", cb_lines_menu}
{
attach(next_button);
attach(quit_button);
attach(next_x);
attach(next_y);
attach(xy_out);
xy_out.put("no point");

color_menu.attach(new Button{Point{0,0},0,0,"red",cb_red});
color_menu.attach(new Button{Point{0,0},0,0,"blue",cb_blue});
color_menu.attach(new Button{Point{0,0},0,0,"black",cb_black});

lines_menu.attach(new Button{Point{0,0},0,0,"solid",cb_solid});
lines_menu.attach(new Button{Point{0,0},0,0,"dash",cb_dash});
lines_menu.attach(new Button{Point{0,0},0,0,"dot",cb_dot});

attach(color_menu);
attach(lines_menu);
color_menu.hide();
lines_menu.hide();
attach(color_menu_button);
attach(lines_menu_button);
attach(lines);
}

void Lines_window::quit()
{
hide(); // curious FLTK idiom to delete window
}

void Lines_window::next()
{
int x = next_x.get_int();
int y = next_y.get_int();
lines.add(Point{x,y});
// update current position readout:
ostringstream ss;
ss << '(' << x << ',' << y << ')';
xy_out.put(ss.str());
redraw();
}

void Lines_window::cb_next(Address,Address pw){
	reference_to<Lines_window>(pw).next();

}

void Lines_window::cb_quit(Address,Address pw){
	reference_to<Lines_window>(pw).quit();

}
void Lines_window::cb_color_menu(Address,Address pw){
	reference_to<Lines_window>(pw).color_menu_pressed();

}
void Lines_window::cb_red(Address,Address pw){
	reference_to<Lines_window>(pw).red_pressed();

}
void Lines_window::cb_blue(Address,Address pw){
	reference_to<Lines_window>(pw).blue_pressed();

}
void Lines_window::cb_black(Address,Address pw){
	reference_to<Lines_window>(pw).black_pressed();

}

void Lines_window::cb_lines_menu(Address,Address pw){
	reference_to<Lines_window>(pw).lines_menu_pressed();

}



void Lines_window::cb_solid(Address,Address pw){
	reference_to<Lines_window>(pw).solid_pressed();

}
void Lines_window::cb_dash(Address,Address pw){
	reference_to<Lines_window>(pw).dash_pressed();

}
void Lines_window::cb_dot(Address,Address pw){
	reference_to<Lines_window>(pw).dot_pressed();
}






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
