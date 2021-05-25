#include "Lines_window.h"


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

/*Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    :Window{xy,w,h,title},
    next_button{Point{x_max()-300,0}, 150, 40, "Next point",
        [](Address, Address pw) {reference_to<Lines_window>(pw).next();}},
    quit_button{Point{x_max()-150,0}, 150, 40, "Quit",
        [](Address, Address pw) {reference_to<Lines_window>(pw).quit();}},
    next_x{Point{300,0}, 50, 40, "next x:"},
    next_y{Point{450,0}, 50, 40, "next y:"},
    xy_out{Point{100,0}, 100, 40, "current (x,y):"}
{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    attach(lines);
}

void Lines_window::quit()
{
    hide();
}

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point{x,y});

    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());

    redraw();
}
*/