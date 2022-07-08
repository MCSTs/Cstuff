#include <iostream>

using namespace std;

void pp()
{
    cout << sizeof (int) << endl;
}

int main(void)
{
    char a;
    int b;  
    long c;
    double d;
    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl;
    cout << sizeof(c) << endl;
    cout << sizeof(d) << endl;

    return 0;
}

