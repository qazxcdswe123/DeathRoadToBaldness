#include <iostream>
#include <iomanip>

using namespace std;
#define PI 3.14

int main(void)
{
    double r;
    cout << "Gime the radius of the ball: ";
    cin >> r;
    double area, volume;
    area = PI * 4 * r * r;
    volume = PI * r * r * r * 4 / 3;
    cout << fixed << setprecision(2) << "The area and volume of the ball are: " << '\n'
         << area << '\t' << volume << '\n';
}