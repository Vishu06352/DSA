#include <iostream>
using namespace std;

int power(int a , int b)
{
    if(b < 1)
    return 1;

    return power(a*a,b-1);
}

int main()
{
    int a, b;
    cout << "Enter the base and the power" << endl;
    cin >> a >> b;

    cout<<power(a,b);
    return 0;
}