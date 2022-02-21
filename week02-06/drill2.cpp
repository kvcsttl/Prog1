/*
g++ drill2.cpp GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp -o drill2 `fltk-config --ldflags --use-images` -std=c++11
*/
#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main(){

	try{
	
		Point t1{300,50};
		Simple_window win(t1, 1000, 800, "My window");
		win.wait_for_button();
		
		Lines grid;
		int x_size = 800;
		int y_size = 800;
		for(int i = 100; i<=x_size; i+=100){
			grid.add(Point(i, 0), Point(i, y_size));
			grid.add(Point(0, i), Point(x_size, i));
		}
		win.attach(grid);
		win.wait_for_button();
		
		/*
		for(int i=100; i<=x_size; i+=100){
			for(int j=100; j<=y_size; j+=100){
				Rectangle r(Point(i, j), 100, 100);
				r.set_fill_color(Color::red);
				win.attach(r);
			}
		} 
		*/
		
		Rectangle r0(Point(0,0), 100, 100);
		r0.set_fill_color(Color::red);
		win.attach(r0); //ezt még 7x, vagy 
		
		//vektoros megoldás
		/*Vector<Rectangle> v;
		for(int i=0; i<8; i++){
			v.push_back(new Rectangle(Point(i*100, i*100), 101, 101));
			v[v.size()-1].set_fill_color(Color::red);
			win.attach(v[v.size()-1]);
		}*/
		
		win.wait_for_button();

	}catch(exception& e){
		cerr << "exception: "<< e.what() << "\n";
		return 1;
	}catch(...){
		cerr << "exception\n";
		return 2;
	}
}
