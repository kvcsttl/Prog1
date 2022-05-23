#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>
#include "Matrix.h"
#include "MatrixIO.h"

using namespace std;
using namespace Numeric_lib;

int main()
{
    try
    {
        cout << "sizeof: \n";
        cout << "char\t" << sizeof(char) << "\n";
        cout << "short\t" << sizeof(short) << "\n";
        cout << "int\t" << sizeof(int) << "\n";
        cout << "long\t" << sizeof(long) << "\n";
        cout << "float\t" << sizeof(float) << "\n";
        cout << "double\t" << sizeof(double) << "\n";
        cout << "int*\t" << sizeof(int *) << "\n";
        cout << "double*\t" << sizeof(double *) << "\n";

        cout << "\nMatrix sizes: \n";
        Matrix<int> a(10);
        Matrix<int> b(100);
        Matrix<double> c(10);
        Matrix<int, 2> d(10, 10);
        Matrix<int, 3> e(10, 10, 10);
        cout << "1D int, 10 elem \t\t" << sizeof(a) << "\n";
        cout << "1D int, 100 elem \t\t" << sizeof(b) << "\n";
        cout << "1D double, 10 elem \t\t" << sizeof(c) << "\n";
        cout << "2D int, 10x10 elem \t\t" << sizeof(d) << "\n";
        cout << "3D int, 10x10x10 elem \t\t" << sizeof(e) << "\n";

        cout << "\nNumber of elementes: \n";
        cout << "a: \t" << a.size() << "\n";
        cout << "b: \t" << b.size() << "\n";
        cout << "c: \t" << c.size() << "\n";
        cout << "d: \t" << d.size() << "\n";
        cout << "e: \t" << e.size() << "\n";

        cout << "\n";
        int i;
        cout << "Give me a numbers(int)!\n";
        while(cin >> i){
            errno = 0;
            double res = sqrt(i);
            if(errno == EDOM){ //hiba típusa --> illegal x
                cout << "no square root\n";
            }
            else{ 
                cout << "sqrt(" << i << ") = " << res << "\n";
            }
        }

        cin.clear();
        cin.ignore();
        cout << "Enter 10 floats!: ";
        Matrix<double> m(10);
        double y;
        for (int i = 0; i < m.size(); i++)
        {
            cin >> y;
            if(!cin) throw runtime_error("Problem reading from cin");
            m[i] = y;
        }
        cout << "Matrix: \n" << m << "\n";

        cout << "\nMultip. table\nEnter n: ";
        int n;
        cin >> n;
        cout << "Enter m: ";
        int m2; 
        cin >> m2;
        Matrix<int, 2> mtable(n,m2);
        for(Index i = 0; i<mtable.dim1(); ++i){
            for(Index j=0; j<mtable.dim2();++j){
                mtable(i,j) = (i+1)*(j+1);
                cout << setw(5) << mtable(i, j);
            }
            cout << "\n";
        }

        Matrix<complex<double>> m3(10);
        cout << "\nEnter 10 complex numbers! (Re, Im): ";
        complex<double> comp;
        for (int i = 0; i < 10; i++)
        {
            cin >> comp;
            if(!cin) throw runtime_error("baj van tes");
            m3[i] = comp;
        }
        cout << m3;
        complex<double> sum;
        for (Index i = 0; i < m3.size(); i++)
        {
            sum += m3[i];
        }
        cout << "Sum: "<< sum << "\n";

        Matrix<int,2> m4(2,3);
        cout <<"\nEnter six ints: ";
        int num;
        for (int i = 0; i < m4.dim1(); i++)
        {
            for (int j = 0; j < m4.dim2(); j++)
            {
                cin >> num;
                m4(i,j) = num;
            }
            
        }
        cout <<"Matrix: \n" << m4 <<"\n";

    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (...)
    {
        cout << "Unknown exception\n";
    }
}