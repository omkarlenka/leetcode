//
//  longest_substring_without_repeating_chars.cpp
//
//  Created by omlenka on 12/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    map<char, int> m;
    int res = 0, max_res = 0;
    int  start = 0;
    
    for(int i =0;i<s.length();i++)
    {
        map<char,int>::iterator itr = m.find(s[i]);
        if(itr == m.end())
        {
            m[s[i]] = i;
            res++;
        }
        else
        {
            if(itr->second < start)
            {
                res++;
                itr->second = i;
            }
            else
            {
                start = itr->second+1;
                res = i-start+1;
                itr->second = i;
            }
        }
        if(res > max_res)
            max_res = res;
    }
    return max_res;
}

int main()
{
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s);
    return 0;
}
