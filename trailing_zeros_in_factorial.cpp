#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int ans = 0;
    for (int i = 5; i <= n; i *= 5)
    {
        ans += n / i;
    }
    cout<<ans;

    return 0;
}