//
//  decode_string.cpp
//
//  Created by omlenka on 18/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <stack>

using namespace std;

map<int, int> getBrackets(string s)
{
    stack<int> stk;
    map<int, int> m;
    
    for(int i = 0;i<s.length();i++)
    {
        if(s[i] == '[')
            stk.push(i);
        else if(s[i] == ']')
        {
            int j = stk.top();
            stk.pop();
            m[j] = i;
        }
    }
    
    return m;
}

string decodeString_Util(string s, int start, int len, map<int, int> brackets)
{
    string res = "";
    int i = 0;
    string repeat = "";
    for(i = start;i<start+len;i++)
    {
        if(isalpha(s[i]))
            res += s[i];
        else if(isdigit(s[i]))
        {
            repeat += s[i]; // handle multidigit numbers here
        }
        else if(s[i] == '[')
        {
            int r = stoi(repeat);
            repeat = "";
            string res_recur = decodeString_Util(s, i+1, brackets[i]-i-1, brackets);
            i = brackets[i];
            for(int j = 0;j<r;j++)
                res += res_recur;
        }
        else if(s[i] == ']')
            return res;
    }
    
    return res;
}

string decodeString(string s)
{
    if(s.empty())
        return s;
    
    map<int, int> brackets = getBrackets(s);
    
    return decodeString_Util(s, 0, int(s.length()), brackets);
    
    
}

int main(int argc, const char * argv[])
{
    string s = "10[a]";
    cout << decodeString(s);
    return 0;
}
