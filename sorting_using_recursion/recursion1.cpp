#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int func(int n) // Tail recursion
{
    //Base case
    if(n == 0)
    return 1;

    //Processing
    cout << n << endl;

    //function call 
    func(n-1);
}

int main()
{
    //To print number in reverse order
    int n;
    cin >> n;
    cout << endl;
    func(n);
    return 0;
}