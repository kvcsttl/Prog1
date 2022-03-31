/*
g++ drill19.cpp GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp -o drill19 `fltk-config --ldflags --use-images` -std=c++11
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<typename T>
struct S{
    S(T vv = 0) : val{vv} {} //alapérték 0, ha kapunk vmit, akkor a val legyen egyenlő vv-vel
    T& get();
    const T& get() const;
    void set(T new_t) {val = new_t;}
    S<T>& operator=(const T& s);
    private:
        T val;
};

template <typename T>
T& S<T>::get(){ //T típusú visszatér. érték
    return val;
}

template <typename T>
S<T>& S<T>::operator=(const T& s){
    val = s;
    return *this;
}

template <typename T> void read_val(T& v){
    cin >> v;
}

template <typename T>
std::ostream& operator<<(ostream& os, vector<T>& v){
    os << "{ ";
    for (int i = 0; i < v.size(); i++)
    {
        os << v[i] << (i < v.size()-1 ? ", ": " ");
    }
    os << "}\n";
    return os;
}//cout << vec1 << vec2 << vec3;

template <typename T>
istream& operator>>(istream& is, vector<T>& v){
    char ch = 0;
    is >> ch;
    if(ch != '{'){
        is.unget();
        return is;
    }
    for(T val; is >> val;){
        v.push_back(val);
        is >> ch;
        if(ch != ',') break;
    }
    return is;
}

int main(){
    S<int> s;
    S<int>si {37};
    S<char>sc {'c'};
    S<double>sd {10.2};
    S<std::string>ss {"Hello"};
    S<std::vector<int>>svi {std::vector<int>{1,2,3,4,5,8}};

    cout << "S<int> : " <<s.get()<<"\n";
    cout << "S<int> : " <<si.get()<<"\n";
    cout << "S<char> : " <<sc.get()<<"\n";
    cout << "S<double> : " <<sd.get()<<"\n";
    cout << "S<string> : " <<ss.get()<<"\n";
    //cout << "S<vector<int>> : " <<svi.get()<<"\n";
    cout <<"S<vector<int>> : ";
    for(auto& a : svi.get()){
        cout << a << ' ';
    }
    cout<<"\n";

    si.set(19);
    cout << "S<int>(set) : " << si.get()<<"\n";

    sd = 3.1416;
    cout<< "S<double> : " << sd.get() << "\n";

    int ii;
    read_val(ii);
    S<int> si2 {ii};

    char cc;
    read_val(cc);
    S<char> sc2 {cc};

    double dd;
    read_val(dd);
    S<double> sd2 {dd};

    cout << "S<int> : " <<si2.get()<<"\n";
    cout << "S<char> : " <<sc2.get()<<"\n";
    cout << "S<double> : " <<sd2.get()<<"\n";

    cout << "S<vector<int>>: (format: {val, val, val})";
    
}