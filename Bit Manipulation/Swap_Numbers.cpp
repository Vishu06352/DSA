#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
#define e endl

int main()
{
    int a = 10 , b =4;

    cout << "Value of a before swap: " << a << "                 Value of b before swap: "<<b<<e;

    a = a^b;
    b = a^b;
    a = a^b;

    cout << "Value of a after swap: "<< a <<"                   Value of b after swap: "<<b<<e;

    return 0;
}