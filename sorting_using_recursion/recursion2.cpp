#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int func(int n) // Head recursion
{
    //Base case
    if(n == 0)
    return 1;

    //function call 
    func(n-1);

    //Processing
    cout << n << endl;
}

int main()
{
    
    int n;
    cin >> n;
    cout << endl;
    //To print number in same order
    func(n);
    return 0;
}