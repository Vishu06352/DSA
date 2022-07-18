#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

int main()
{
    queue<int>q;
    q.push(12);
    q.push(112);
    q.push(1);

   cout << q.front() << endl;
   cout << q.back() << endl;

   

    return 0;
}