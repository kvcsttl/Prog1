#include <iostream>
#include <string>

using namespace std;

class B1{
    public:
    virtual void vf(){cout << "B1::vf()\n";} //a virtuális függvény számít arra, hogy később át lesz írva
    void f() {cout << "B1::f()\n";}
    virtual void pvf() = 0; /*tisztán virtuális függvény, absztrakt függvénynek felel meg-> nincsen implementációja, 
                              ha meghívjuk nem tudja mit csináljon vele, 
                              absztrakt osztály lett, absztrakt osztályt nem lehet példányosítani,
                              ezért a main() függvényben nem fog működni semmi -> thats fucked up*/

};

class D1 : public B1{
    public:
        virtual void vf(){cout << "D1::vf()\n";}
        void f() {cout << "D1::f()\n";}
        //virtual void pvf() = 0; ezt is megkapja
};

class D2 : public D1{
    public:
        void pvf() {cout << "D2::pvf()\n";} /*átírtuk a tisztán virtuális függvényt,
                                              adtunk neki értéket, hogy mit csináljon
                                              így már nincs absztrakt függvény, 
                                              ezért a D2 osztály sem számít már absztraktnak 
                                              és működik minden tovább*/
};

class B2{
    public:
        virtual void pvf()=0;
};

class D21 : public B2{
    public:
        string s;
        void pvf() {cout << s << "\n";}
};

class D22 : public B2{
    public:
        int i;
        void pvf() {cout << i << "\n";}
        void f(B2& b2bref) {b2bref.pvf();} /* Define a function f() that
                                              takes a B2& argument and calls pvf() for its argument. */
};

int main(){
    /*
    B1 b1;
    b1.vf();
    b1.f();
    cout<<"---\n";

    D1 d1;
    d1.vf();
    d1.f();
    cout<<"---\n";

    B1& bref = d1; //referencia, a nem virtuális függvény(f) B1 tipusú értékét veszi fel, hiába d1-et adtunk meg
    bref.vf();
    bref.f();
    cout<<"---\n";*/

    D2 d2;
    d2.f();
    d2.vf();
    d2.pvf();
    cout<<"---\n";

    D21 d21;
    d21.s = "D21::pvf()";
    d21.pvf();
    cout<<"---\n";
    //drill utolsó feladatának első fele
    D22 d22;
    d22.i = 10;
    d22.f(d21);
    d22.f(d22);
}