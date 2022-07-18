#include <iostream>
using namespace std;

bool check(string &str , int i)
{
    if(i >= str.length()/2) 
    return true;
    
   if(str[i] != str[str.length() -1 -i])
    return false;
    
    i++;

    return check(str,i);
}

int main()
{
    string str = "aabbaaa";
    
    if(check(str,0))
    {
        cout<<"Strings are equal"<<endl;
    }
    else
    {
        cout<<"String are not equal"<<endl;
    }
   
    return 0;
}
