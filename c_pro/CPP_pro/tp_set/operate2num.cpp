#include <iostream>

using namespace std;

int main(void)
{
    int a, b;
    cin >> a >> b;

    int n_max = max(a, b);
    int n_min = min(a, b);
    //int n_max = (a > b ? a : b);
    //int n_min = (a > b ? b : a);

    cout << n_max + n_min << " " << n_max - n_min << " " << n_max * n_min << " " << n_max / n_min << " " << n_max % n_min << endl;

    return 0;
}
