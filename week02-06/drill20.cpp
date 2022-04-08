#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <array>
#include <algorithm>
#include <stdexcept>
using namespace std;

template<typename Iter1, typename Iter2>
// requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
Iter2 ora_copy(Iter1 f1, Iter1 e1, Iter2 f2){
    for(Iter1 p = f1; p!= e1; ++p){
        *f2++ = *p;
        //f2++;
    }
    return f2;
}


template<typename C>
void print_content(const C& c){
    for(auto& i : c)
        cout << i << " ";
    cout << "\n";
}

int main()
{
    try
    {

        /*int intArray[10] = {0,1,2,3,4,5,6,7,8,9};
        vector<int> intVec = {0,1,2,3,4,5,6,7,8,9};
        list<int> intList = {0,1,2,3,4,5,6,7,8,9};*/

        constexpr int size = 10;
        int arr[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = i;
        };
        array<int, size> ai;
        copy(arr, arr + size, ai.begin());

        vector<int> vi(size);
        copy(arr, arr + size, vi.begin());

        list<int> li(size);
        copy(arr, arr + size, li.begin());

        
        print_content(ai);
        print_content(vi);
        print_content(li);

        //---------------------------------

        /*array<int, size> ai2;
        copy(begin(ai), end(ai), begin(ai2));*/
        array<int, size> ai2 = ai;

        vector<int> vi2 = vi;

        list<int> li2 = li;

        for(int& i: ai2)
            i+=2;

        for(int& i: vi2)
            i+=3;
       
        for(int& i: li2)
            i+=5;
        
        print_content(ai2);
        print_content(vi2);
        print_content(li2);

        //---------------------------------

        ora_copy(ai2.begin(), ai2.end(), vi2.begin());
        ora_copy(li2.begin(), li2.end(), ai2.begin());

        print_content(ai2);
        print_content(vi2);
        print_content(li2);

        //-------------------------------

        vector<int>::iterator vit;
        vit = find(vi2.begin(), vi2.end(), 3);
        if(vit != vi2.end()){
            cout<<"Found at: "<< distance(vi2.begin(), vit) << "\n";
        }else{
            cout<<"Not found!";
        }

        list<int>::iterator lit;
        lit = find(li2.begin(), li2.end(), 27);
        if(lit != li2.end()){
            cout<<"Found at: "<< distance(li2.begin(), lit) << "\n";
        }else{
            cout<<"Not found!\n";
        }

    }
    catch (exception &e)
    {
        cout << "Exception: " << e.what() << "\n";
        return 1;
    }
    catch (...)
    {
        cout << "Unknown exception\n";
        return 2;
    }
}