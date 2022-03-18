/*
g++ drill15_classDef.cpp -o drill15
*/
#include <string>
#include <iostream>
#include <functional>
#include <vector>
using namespace std;

// class definition drill

struct Person
{
public:
    Person(){};
    /*konstruktor, person függvény, vár egy nevet és egy évet, majd egyenlővé teszi az oszály adatiaval*/
    //Person(string n, int a) : n{n}, a{a}
    Person(string fn, string ln, int a) : fn{fn}, ln{ln}, a{a}
    {
        if (a < 0 || a >= 150)
        {
            throw runtime_error("Invalid age in Person");
        }

        string n = fn + ln;

        for(char c : n){
            switch(c){
                case ';':
                case ':':
                case '"':
                //case "'":
                case '[':
                case ']':
                case '*':
                case '&':
                case '@':
                case '$':
                case '^':
                case '!':
                case '%':
                throw runtime_error("Invalid character in Person name.");
            }
        }
    };
    //string name() const { return n; } // getter
    string first_name() const { return fn; } // getter
    string last_name() const { return ln; } // getter
    int age() const { return a; }     // getter
private:
    string fn;
    string ln;
    int a;
};

ostream &operator<<(ostream &os, const Person &p)
{
    return os << p.first_name() << p.last_name() << " " << p.age(); // a getter-t (függvényt) hívjuk meg, nem pedig az adattagot
}

istream &operator>>(istream &is, Person &p)
{
    string fn;
    string ln;
    int a;

    //is >> n >> a;
    is >> fn >> ln >>a;
    p = Person(fn, ln, a); // konstruktorral új personba küldte bele

    return is;
}

int main()
{
    //Person p1 = Person("Goofy", 63);
    Person p1 = Person("Goofy", "a", 63);
    // cout << p1.name << " " << p1.age << "\n";
    cout << p1 << "\n";
    cout << p1 << p1 << p1 << "\n";
    Person p2;
    cin >> p2;
    Person p3;
    cout << p2 << p3 << "\n";

    vector<Person> vec;
    for(Person p; cin >> p;){  //while(cin >> p)
        if(p.first_name() == "end") break;
        vec.push_back(p);
    }
    for(Person p: vec)
        cout << p << "\n";
}