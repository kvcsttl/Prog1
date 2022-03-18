/*
g++ drill15_graph.cpp GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp -o drill15 `fltk-config --ldflags --use-images` -std=c++11
*/
#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"
#include <functional>

double one(double x){
	return 1;
}

double slope(double x){
	return x/2;
}

double square(double x){
	return x * x;
}

double sloping_cos(double x){
	return cos(x) + slope(x);
}

constexpr int rangeMin = -10;
constexpr int rangeMax = 11;
Point origin{300, 300};
constexpr int resolution = 400;
constexpr double scale = 20;

int main(){
    try{
        Simple_window win{Point{300, 50}, 600, 600, "Function graphs"};
        Axis xa{Axis::x, Point{100, 300}, 400, 20, "1 == 20 pixels"};
        Axis ya{Axis::y, Point{300, 500}, 400, 20, "1 == 20 pixels"};
        xa.set_color(Color::red);
        ya.set_color(Color::red);
        win.attach(xa);
        win.attach(ya);

        Text slopeText{Point{100, 300}, "x/2"};
        win.attach(slopeText);

        Function f1{one, rangeMin, rangeMax, origin, resolution, scale, scale};
        win.attach(f1);

        Function f2{slope, rangeMin, rangeMax, origin, resolution, scale, scale};
        win.attach(f2);

        Function f3{square, rangeMin, rangeMax, origin, resolution, scale, scale};
        win.attach(f3);

        Function f4{cos, rangeMin, rangeMax, origin, resolution, scale, scale};
        f4.set_color(Color::blue);
        win.attach(f4);
        
        Function f5(sloping_cos, rangeMin, rangeMax, origin, resolution, scale, scale);
        win.attach(f5);

        win.wait_for_button();
    }
    catch (exception &e){
        cout << "error: " << e.what() << endl;
        return 1;
    }
    catch (...){
        cout << "unknown error" << endl;
        return 2;
    }
}