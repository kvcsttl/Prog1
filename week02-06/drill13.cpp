/*
g++ drill13.cpp GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp -o drill13 `fltk-config --ldflags --use-images` -std=c++11
*/
#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int randomNumber(){
	int res = (rand() % 8) + 1;
	return res*100;
}

int main()
{

	try
	{

		Point t1{300, 50};
		Simple_window win(t1, 800, 1000, "My window");
		win.wait_for_button();

		Lines grid;
		int x_size = 800;
		int y_size = 800;
		for (int i = 100; i <= x_size; i += 100)
		{
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

		Rectangle r0(Point(0, 0), 100, 100);
		r0.set_fill_color(Color::red);
		win.attach(r0); // ezt még 7x, vagy
		Rectangle r1(Point(100, 100), 100, 100);
		r1.set_fill_color(Color::red);
		win.attach(r1); // ezt még 7x, vagy
		Rectangle r2(Point(200, 200), 100, 100);
		r2.set_fill_color(Color::red);
		win.attach(r2); // ezt még 7x, vagy
		Rectangle r3(Point(300, 300), 100, 100);
		r3.set_fill_color(Color::red);
		win.attach(r3); // ezt még 7x, vagy
		Rectangle r4(Point(400, 400), 100, 100);
		r4.set_fill_color(Color::red);
		win.attach(r4); // ezt még 7x, vagy
		Rectangle r5(Point(500, 500), 100, 100);
		r5.set_fill_color(Color::red);
		win.attach(r5); // ezt még 7x, vagy
		Rectangle r6(Point(600, 600), 100, 100);
		r6.set_fill_color(Color::red);
		win.attach(r6); // ezt még 7x, vagy
		Rectangle r7(Point(700, 700), 100, 100);
		r7.set_fill_color(Color::red);
		win.attach(r7); // ezt még 7x, vagy
		/*Rectangle r8(Point(800,800), 100, 100);
		r8.set_fill_color(Color::red);
		win.attach(r8);*/
		// ezt még 7x, vagy

		// vektoros megoldás
		/*Vector<Rectangle> v;
		for(int i=0; i<8; i++){
			v.push_back(new Rectangle(Point(i*100, i*100), 101, 101));
			v[v.size()-1].set_fill_color(Color::red);
			win.attach(v[v.size()-1]);
		}*/

		win.wait_for_button();

		Image img1(Point(0, 0), "./kep.jpg");
		win.attach(img1);
		Image img2(Point(300, 0), "./kep.jpg");
		win.attach(img2);
		Image img3(Point(0, 400), "./kep.jpg");
		win.attach(img3);
		win.wait_for_button();

		int randomX = randomNumber();
		int randomY = randomNumber();
		Image img4(Point(randomX, randomY), "./susus.png");
		win.attach(img4);
		while(win.wait_for_button()){
			randomX = randomNumber();
			randomY = randomNumber();
			img4.move(randomX, randomY);
		};

		/*int randomTeszt = rand() % 100 + 1;
		string randomSzam;
		randomSzam = to_string(randomTeszt);
		Text teszt(Point(100,100), randomSzam);
		win.attach(teszt);*/

		win.wait_for_button();
	}
	catch (exception &e)
	{
		cerr << "exception: " << e.what() << "\n";
		return 1;
	}
	catch (...)
	{
		cerr << "exception\n";
		return 2;
	}
}
