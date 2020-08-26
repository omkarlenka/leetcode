//
//  simply_path.cpp
//
//  Created by omlenka on 26/08/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

class Solution {
    int i = 0;
    string my_strtok(string s, char delimiter)
    {
        int len = s.length();
        string res;
        if(i == len-1)
        {
            i = 0;
            return "";
        }
        
        for(int j = i+1;j<len;j++)
        {
            if(j == s.length()-1)
            {
                int l = 0;
                if(s[j] == '/')
                    l = j-i-1;
                else
                    l = j-i;
                res = s.substr(i+1, l);
                i=j;
                break;
            }
            else if(s[j] == '/')
            {
                if(j > i+1)
                {
                    res = s.substr(i+1, j-i-1);
                    i = j;
                    break;
                }
                else
                {
                    i = j;
                }
            }
        }
        return res;
    }
public:
    string simplifyPath(string path)
    {
        if(path.empty())
            return path;
        stack<string> stk;
        int len = path.length();
        string res,sub;
        while(true)
        {
            sub = my_strtok(path, '/');
            if(sub.empty())
            {
                break;
            }
            if(sub == "..")
            {
                if(!stk.empty())
                {
                    stk.pop();
                }
            }
            else if(sub != ".")
            {
                stk.push(sub);
            }
        }
        
        while(!stk.empty())
        {
            string s = stk.top();
            stk.pop();
            
            if(!res.empty())
            {
                res += "/";
            }
            reverse(s.begin(),s.end());
            res += s;
        }
        res += "/";
        reverse(res.begin(),res.end());
        return res;
    }
};

int main()
{
    Solution S;
    cout << S.simplifyPath("/.././GVzvE/./xBjU///../..///././//////T/../../.././zu/q/e") << endl;
    return 0;
}
