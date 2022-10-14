#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int solveMemo(int index, int capacity, vector<int>&wt, vector<int>&profit, vector<vector<int> > &dp)
{
    if (index == 0)
    {
        if (capacity >= wt[0])
            return profit[0];

        return 0;
    }

    if (dp[index][capacity] != -1)
        return dp[index][capacity];

    int include = 0;

    if (wt[index] <= capacity)
        include = profit[index] + solveMemo(index - 1, capacity - wt[index], wt, profit, dp);

    int exclude = solveMemo(index - 1, capacity, wt, profit, dp);

    return dp[index][capacity] = max(include, exclude);
}

int solve2(int n ,vector<int> wt,vector<int> val,int capacity)
    {
        vector<vector<int> >dp(n,vector<int>(capacity+1,0));
        
        for(int i = wt[0] ; i <= capacity ; i++)
        {
            if(wt[0] <= capacity)
                dp[0][i] = val[0];
                
            else
            dp[0][i] = 0;
        }
        
        for(int index = 1 ; index < n ; index++)
        {
            for(int w = 0 ; w <= capacity ; w++)
            {
                int include = 0;
                
                if(wt[index] <= w)
                include = val[index] + dp[index-1][w-wt[index]];
                
                int exclude = dp[index-1][w];
                
                dp[index][w] = max(include,exclude);
            }
        }
    
        return dp[n-1][capacity];
    }
int main()
{
    int size;
    int capacity = 0;
    cout << "Enter the max capacity of the knapsack: ";
    cin >> capacity;

    cout << "Enter the size of weight array: ";
    cin >> size;
    
    vector<int> wt(size,-1);
    vector<int> profit(size,-1);

    for (int i = 0; i < size; i++)
    {
        cout << "Enter the " << i + 1 << " weight into array: ";
        cin>>wt[i];
    }
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the " << i + 1 << " profit into array: ";
        cin>>profit[i];
    }

    // vector<vector<int>> dp(size, vector<int>(capacity + 1, -1));

//     cout << "Maximum profit that can be generated is: " << solveMemo(size-1, capacity, wt, profit, dp)
//  << endl;
    cout << "Maximum profit that can be generated is: " << solve2(size, wt, profit,capacity);
//  << endl;
    return 0;

    //  profit = {1,2,3}
    // weight[] = {4,5,1}
    // capacity = 4, size = 3

// N = 3
// W = 3
// values[] = {1,2,3}
// weight[] = {4,5,6}
}