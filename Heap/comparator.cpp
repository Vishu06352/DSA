#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

bool should_i_swap(int a , int b)
{
    // if(a > b) // agar phele wali value badi hogi toh swap nhi kare ga but if phele wali value choti hogi toh swap kare ga in in-build sort function 
    // return true;

    // return false;

    return a > b;
}

int main()
{
   vector<int>ans = {2,1,3,5,4,6};
    int n = ans.size();

//    for(int i = 0 ; i < n ; i++)
//    for(int j = i+1 ; j < n ; j++)
//    {
//     if(should_i_swap(ans[i],ans[j]))
//         swap(ans[i],ans[j]);
    
//    }

    sort(ans.begin(),ans.end(),should_i_swap);

   for(auto i : ans)
   {
       cout << i <<" ";
   }

    return 0;

    /*
        1. agar apna normal for loops mei sort function likho gye toh yeh function swap tab kre ga jab first value badi hogi in this case asscending order will be answer
        bool should_i_swap(int a , int b)
        {
            if(a > b)
            return true;

            return false;
        }

        1. conti -> but if yeh function esse hoga toh tab swap kre ga jab phele wali value choti hogi and 2nd wali badi in this case descending order will be answer 

        bool should_i_swap(int a , int b)
        {
            if(a < b)
            return true;

            return false;
        }
        conclusion ->  the above to logic is basic and can be understand as normal logic but twist come in in-build function of sorting
---------------------------------------------------------------------------------------------------------------------------------------------------------------------

        *******ALSO REMEMBER THAT WE DO NOT REQUIRE TO PASS THE ARGUMENTS FOR FUNCTION CALL IN MAIN FUNCTION IN IN-BUILD FUNCTION LIKE SORT*******

        2. agar yeh same function in-build sort function mei use ho ga toh descending order print hoga (AS IT WORK OPPOSITE IN CASE OF IN-BUILD FUNCTION)
        bool should_i_swap(int a , int b)
        {
            if(a > b)
            return true;

            return false;
        }
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        3. Now it can be confusion so inorder to overcome the confusion just write as below
        bool should_i_swap(int a , int b)
        {
            return a > b;
        }
        the above code means that we need first value a as greater so it will swap and give a descending order as answer
        ans for asscending order just write 

        bool should_i_swap(int a , int b)
        {
            return a < b;
        }  this means that we need first element a as smaller


    */
}