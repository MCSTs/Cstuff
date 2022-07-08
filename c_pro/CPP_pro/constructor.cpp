#include <iostream>

using namespace std;

class Line {
    public:
        int a;
        int b;
        int c;
        Line();
};

Line::Line(void)
{
    cout << "This is a constructor function\n" << endl;
}

int main(void)
{
    Line demo;
    return 0;
}
