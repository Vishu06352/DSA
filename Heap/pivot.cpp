#include <iostream>
#include<vector>
using namespace std;


  int findPivotIndex(vector<int>nums,int start,int end)
    {
        while(start < end)
        {
            int mid = start +(end-start)/2;
            
            if(nums[0] <= nums[mid])
                start = mid+1;
            
            else
                end = mid;
        }
        return end;
    }

int main()
{
    vector<int>nums = {4,5,6,7,9,0,1,2};
    
    cout << findPivotIndex(nums,0,nums.size()-1);
    return 0;
}
