#include <iostream>
using namespace std;
  // pass arr to function
int a[10], i, sum = 0;
int main()
{
    int funarr(int p[], int n);
    cout << "enter 10 elements of arr : ";

    for (i = 0; i <= 9; i++)
    {
        cin >> a[i];
    }
    sum = funarr(a, 9);
    cout << "the sum of arr element is : " << sum;
    cin >> sum;
}
int funarr(int p[], int n)
{
    int i, s = 0;
    for (i = 0; i <= n; i++)
    {
        s = s + p[i];
    }
    return(s);
}