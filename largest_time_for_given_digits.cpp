//
//  largest_time_for_given_digits.cpp
//
//  Created by omlenka on 19/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution
{
    bool isValid(string s)
    {
        if(s.length() < 4)
            return false;
        
        if(s[0] != '0' && s[0] != '1' && s[0] != '2')
            return false;
        
        if(s[0]  == '2' && s[1]-'0' > 3)
            return false;
        if(s[2] - '0' > 5)
            return false;
        return true;
    }
    
    bool isGreater(string  s1, string s2)
    {
        if(stoi(s1) > stoi(s2))
            return true;
        return false;
    }
    
    void _largestTimeFromDigits(string s, int start, int end, string &res)
    {
        if(start == end)
        {
            if(isValid(s))
            {
                if(res.empty() || isGreater(s, res))
                    res = s;
            }
        }
        for(int i = start;i<= end;i++)
        {
            swap(s[i], s[start]);
            _largestTimeFromDigits(s, start+1, end, res);
            swap(s[i], s[start]);
        }
    }
public:
    string largestTimeFromDigits(vector<int>& A)
    {
        string res = "";
        string s = to_string(A[0])+to_string(A[1])+to_string(A[2])+to_string(A[3]);
        _largestTimeFromDigits(s,0, 3, res);
        
        if(!res.empty())
            res = res.substr(0,2) + ":" + res.substr(2,2);
        
        return res;
    }
};
