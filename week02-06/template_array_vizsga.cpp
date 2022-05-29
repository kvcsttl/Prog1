 #include "std_lib_facilities.h"
 #include <array>
 #include <iterator>
 #include <iostream>

template<typename C>
void printout(const C& c)
{
	for(int i = 0; i < c.size(); ++i)
		cout << c[i] << endl;
}

template<typename T, int N>
struct my_array {

	T elem[N];

	T& operator[](int n) { return elem[n]; }
	const T& operator[](int n) const { return elem[n]; }

	int size() const { return N; }

    public:
    using size_type = unsigned long;
	using value_type = T;
	using iterator = T*;
	using const_iterator = const T*;

	iterator begin() { return elem; }
	const_iterator begin() const { return elem; }
	iterator end() { return elem+N; }
	const_iterator end() const { return elem+N; }
};

int main()
{
	const my_array<int, 2> int_array = {10,100};
	my_array<double, 5> double_array = {0.1,0.2,0.3,0.4,0.5};

	for(int i = 0; i < int_array.size(); ++i)
		cout << int_array[i] << endl;

	for(int i = 0; i < double_array.size(); ++i)
		cout << double_array[i] << endl;

	printout(int_array);
	printout(double_array);

	vector<int> iv = {10,20,30,40,50};

	printout(iv);

    cout<<"--------"<<endl;
    for(auto i = double_array.begin(); i != double_array.end(); ++i)
		cout << " " << *i << endl;

	return 0;
}