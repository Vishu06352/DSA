#include <iostream>
using namespace std;

void convert(string &str , int i)
{
    if(i >= str.length()/2) //if we do not divide the length by 2 then it always give back the original string
    return ;
    
    swap(str[i] , str[str.length()-1-i]);
    i++;
    
    convert(str,i);
}

int main()
{
    string str = "harshbeniwal";
    convert(str,0);
    cout<<str;
    return 0;
}
