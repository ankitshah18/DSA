#include "bits/stdc++.h"//header file   
using namespace std; //standard c++ namespace

bool balance(string str)
{
    int n = str.length() ; 
    stack <char> s ; 
    for(int i = 0 ; i < n; i++)
    {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            s.push(str[i]) ; 
        }
        if(str[i] == ')')
        {
            if(s.empty() || s.top() != '(')
            {
                return false ; 
            }
            s.pop() ; 
        }
        if(str[i] == '}')
        {
            if(s.empty() || s.top() != '{')
            {
                return false ; 
            }
            s.pop() ; 
        }
        if(str[i] == ']')
        {
            if(s.empty() || s.top() != '[')
            {
                return false ; 
            }
            s.pop() ; 
        }
    }
    if(s.empty() == true)
    {
        return true ; 
    }
    else
    {
        return false ; 
    }
}
int main() 
{
    string str ; 
    cin>>str ; 
    bool p = balance(str) ; 
    if(p)
    {
        cout<<"Yes" ; 
    }
    else
    {
        cout<<"No" ; 
    }
}