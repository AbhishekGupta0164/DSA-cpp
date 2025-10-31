// to print a sum of 10 natural no.
#include <iostream>
using namespace std;
int sum(int y)
{
    if (y == 0)
        return 0;,
    else
        return (y + sum(y - 1));
}
int main()
{
    int y;
    cout << "enter no: ";
    cin >> y;
    cout << "the sum of first " << y << "integer = " << sum(y) << endl;
    return 0;

}
// 