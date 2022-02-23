#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

double one(double) {
	return 1;
}

double square(double x){
	return x*x;
}

int main()
{
    try{
    	
		int x_size = 600;
		int y_size = 400; //ablak méretek
		
		Simple_window win{Point{100,100}, x_size, y_size, "My window"};
		win.wait_for_button();

		int xorigo = x_size/2;
		int yorigo = y_size/2;
		Point origo{xorigo, yorigo}; //felvesszük az origót
		int xlength = x_size - 40;
		int ylength = y_size - 40;
		int x_scale = 10;
		int y_scale = 10;
		Axis x {Axis::x, Point{20, yorigo}, xlength, xlength/x_scale, "X axis"};
		win.attach(x);
		//win.wait_for_button();
		Axis y {Axis::y, Point{xorigo, ylength+20}, ylength, ylength/y_scale, "Y axis"};
		win.attach(y);
		//win.wait_for_button();

		Function s0 (one, -11, 11, origo, 400, x_scale, y_scale); //konstans függvény
		Function s1 (square, -11, 11, origo, 400, x_scale, y_scale); //négyzetfüggvény
		win.attach(s0);
		win.attach(s1);
		//win.wait_for_button();

		Rectangle r{Point{20, 300}, 100, 50}; //téglalap
		r.set_fill_color(Color::green);
		r.set_style(Line_style(Line_style::dash, 4));
		win.attach(r);

		Text t{Point{25,25}, "Hello graphics, te gyongyszem! :))) "}; //szöveg
		t.set_font(Font::times_bold_italic);
		t.set_font_size(15);
		t.set_color(Color::magenta);

		win.attach(t);

		Image img{Point{300, 150}, "./GUI/badge.jpg"}; //kép
		win.attach(img);

		Text hiba{Point{450, 150}, "Valamiert unsupported a kep"};
		hiba.set_color(Color::dark_red);
		win.attach(hiba);

		Circle c {Point{400,300},50}; //kör
		c.set_fill_color(Color::dark_magenta);
		win.attach(c);
		Mark m {Point{400,300},'x'};
		win.attach(m);
		Ellipse e{Point{400,300}, 75, 25};
		e.set_color(Color::red);
		win.attach(e);

		Polygon poly; //alakzatok
		poly.add(Point{500, 280}); //több pont hozzáadása, azokat összeköti
		poly.add(Point{450, 380});
		poly.add(Point{550, 380});
		poly.set_fill_color(Color::yellow);
		poly.set_style(Line_style(Line_style::dashdot, 2));
		win.attach(poly);

		win.wait_for_button();
    }
    catch (exception &e)
    {
        cerr << "exception: " << e.what() << "\n";
        return 1;
    }
    catch (...)
    {
        cerr << "error\n";
        return 2;
    }
    
}
