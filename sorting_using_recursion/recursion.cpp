#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int fact(int n)
{
    //Base Case
    if( n == 1)
    return n;

    //Recursive function with base case
    return n*fact(n-1);
}

int main()
{
    int n;
    cin >> n;
    cout << fact(n);

    return 0;
}