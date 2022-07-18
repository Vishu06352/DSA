#include <iostream>
#include<climits>
#include<vector>
#include<queue>
using namespace std;

vector<int> find(int *arr,int k,int n)
{
    deque<int>q;
    vector<int>ans;
    for(int i = 0 ; i < k ; i++)
    {
        if(q.empty()){
            q.push_back(i);
        }
        
        else if(!q.empty() && arr[q.front()] > arr[i])
        {
            q.pop_front();
            q.push_back(i);
        }
    }
    
    if(!q.empty())
    ans.push_back(arr[q.front()]);
    
    for(int i = k ; i < n ;i++)
    {
        if(i-q.front() >= k) // used to delete element outside window of k
        q.pop_front();
        
        if(q.empty()){
            q.push_back(i);
        }
        
        else if(!q.empty() && arr[q.front()] > arr[i])
        {
            q.pop_front();
            q.push_back(i);
        }
        
        if(!q.empty())
            ans.push_back(arr[q.front()]);
    }
    return ans;
}

vector<int> find2(int *arr,int k ,int n)
{
    
    deque<int>q;
    vector<int>ans2;
    for(int i = 0 ; i < k ; i++)
    {
        if(q.empty()){
            q.push_back(i);
        }
        
        else if(!q.empty() && arr[q.front()] < arr[i])
        {
            q.pop_front();
            q.push_back(i);
        }
    }
    
    if(!q.empty())
    ans2.push_back(arr[q.front()]);
    
    for(int i = k ; i < n ;i++)
    {
        if(i-q.front() >= k) // used to delete element outside window of k
        q.pop_front();
        
        if(q.empty()){
            q.push_back(i);
        }
        
        else if(!q.empty() && arr[q.front()] < arr[i])
        {
            q.pop_front();
            q.push_back(i);
        }
        
        if(!q.empty())
            ans2.push_back(arr[q.front()]);
    }
    
    return ans2;
}

int main()
{
    //it can further we minimised by using the same function and use a single variable instead of vector 
    // i had done using vector for testing purpose and it is working fine.
    int arr[] = {2,5,-1,7,-3,-1,-2};
    int k = 4;
    
    vector<int>ans,ans2;
    
    ans = find(arr,k,7);
    ans2 = find2(arr,k,7);
    
    for (int i : ans) {
        cout << i <<" ";
    }cout<<endl;
    
    for (int i : ans2) {
        cout << i <<" ";
    }
    return 0;
}
