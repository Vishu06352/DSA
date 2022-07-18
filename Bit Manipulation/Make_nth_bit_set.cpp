#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
#define e endl

void represent_binary(int n)
{
    if(n == 0)
    return;

    int bit = (n & 1);
    n = n>>1;

    represent_binary(n);
    cout<<bit;
}

int main()
{
    int n,i;
    cout<<"Enter the number: "<<e;
    cin>>n;

    represent_binary(n);
    cout<<e;

    cout<<"Enter the ith position for set bit: "<<e;
    cin>>i;

    n = n | (1<<i);

    represent_binary(n);
    cout<<e;

    return 0;
}