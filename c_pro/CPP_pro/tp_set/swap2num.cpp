#include <iostream>

using namespace std;


void swap_reference(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main(void)
{
    int a, b;
    cin >> a >> b;

    //swap(a, b);
/*   
    int temp = a;  
    a = b;
    b = temp;
*/ 
    swap_reference(a, b);

    cout << a << " " << b << endl;
    return 0;
}
