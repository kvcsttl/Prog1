using namespace std;
#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <numeric>

template<typename K, typename V> //kiíratáshoz szükséges
void print(const map<K, V>& m){
    for (const auto& a : m) // auto -> std::pair<K,V> lesz
    {
        cout << a.first << "\t" << a.second <<"\n";
    }
    
}

void read_map(map<string, int>& m){
    string s;
    int i=0;

    while (m.size() < 10)
    {
        cin >> s >> i;
        //m[s] = i;
        m.insert(make_pair(s,i));
    }
    
}

void sum(map<string, int>& m){
    int res = 0;
    for (auto &&a : m)
    {
        res += a.second;
    }
    
    cout << res << "\n";
}

int main()
{
    try
    {
        map<string, int> msi;

        msi["a"] = 42;
        msi["e"] = 21;
        msi["ughjk"] = 2;
        msi["key"] = 3;
        msi["ab"] = 17;
        msi["cd"] = 93;
        msi["po"] = 62;
        msi["tt"] = 37;
        msi["x"] = 11;
        msi["k"] = 1;
        msi["a"] = 1; 
        //unique kulcsok, ezért ha kétszer ugyanarra veszünk fel értéket, az utóbbit fogja használni, felülírja
        //már rendezi is a kulcs szerint
        print(msi);

        cout << "\nTörlés:\n";
        msi.erase("a");
        print(msi);

        cout << "\negész törlése:\n";
        msi.erase(msi.begin(), msi.end());

        cout << "\nAdj meg 10 kulcs érték párt!\n";
        read_map(msi);
        cout << "\nA megadott párok: \n";
        print(msi);

        cout << "\nAz elemek összege: \n";
        sum(msi);

        map<int, string> mis;

        for (const auto& a : msi)
        {
            mis[a.second] = a.first;
        }

        cout << "\nA megcserélt map: \n";
        print(mis);
        

    }
    catch (exception &e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    catch (...)
    {
        cerr << "Exception" << "\n";
        return 2;
    }
}