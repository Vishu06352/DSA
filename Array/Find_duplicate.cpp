#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // Note we can not apply modification to given or original array
    //This approach is a brute force can be improved by the map
    vector<int> nums = {3, 1, 3, 4, 2};

    vector<int> ans(nums);

    sort(ans.begin(), ans.end());

    int low = 0, high = nums.size() - 1, x = -1;

    while (low < high)
    {
        if (ans[low] == ans[low + 1])
        {
            x = ans[low];
            break;
        }

        if (ans[high] == ans[high - 1])
        {
            x = ans[high];
            break;
        }
        low++,high--;
    }

    cout << x;

    return 0;
}