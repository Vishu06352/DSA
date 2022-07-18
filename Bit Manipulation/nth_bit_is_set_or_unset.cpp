#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
#define e endl

void represent_binary(int n)
{
    if (n == 0)
        return;

    int bit = (n & 1);
    n = n >> 1;

    represent_binary(n);
    cout << bit;
}

int main()
{
    int n = 7;
    int i;
    represent_binary(n);
    cout<<e;

    cout << "Enter the ith position: " << e;
    cin >> i;

    if ((n & (1 << i)))
        cout << "Set bit" << e;

    else
        cout << "Unset bit" << e;

    return 0;
}