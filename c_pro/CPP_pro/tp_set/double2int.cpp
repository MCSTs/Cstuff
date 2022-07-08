#include <iostream>

using namespace std;

int main(void)
{
    double d;
    cin >> d;

    if (d > 0) 
        d += 0.5;
    else 
        d -= 0.5;
    
    cout << (int)d << endl;

    return 0;
}
