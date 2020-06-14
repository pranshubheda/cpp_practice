#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double circumfrence, area, radius;
    const double PI = 2.0 * acos(0);
    cout << "Enter a radius" << endl;
    cin >> radius;
    circumfrence = 2.0 * PI * radius;
    area = PI * pow(radius, 2.0);
    cout << "Area: " << area << endl << "Circumfrence: " << circumfrence << endl; 
}