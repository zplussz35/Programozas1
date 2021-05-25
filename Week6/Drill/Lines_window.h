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

/*struct Lines_window : Graph_lib::Window {
	Lines_window(Point xy, int w, int h, const string& title );
	Open_polyline lines;

	bool wait_for_button();

private:
	Button next_button;
	Button quit_button;

	In_box next_x;
	In_box next_y;

	Out_box xy_out;

	void next();
	void quit();

};*/