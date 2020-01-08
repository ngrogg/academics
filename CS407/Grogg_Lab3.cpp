#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
    int m = 0;
    
    while(pow(2,m) + 1 > 1)
    {
        --m;
    }
    ++m;
    cout << pow(2,m) << endl;
    return 0;
}
