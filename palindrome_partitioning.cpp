//
//  palindrome_partitioning.cpp
//
//  Created by omlenka on 15/08/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
    bool isPalindrome(string s, int l, int r)
    {
        while(l <= r)
        {
            if(s[l++] != s[r--])
                return false;
        }
        return true;
    }
    
    void getPalinSubstrings(string &s, int index, vector<string> &cur, vector<vector<string>> &res)
    {
        for(int i = index; i < s.length();i++)
        {
            if(isPalindrome(s, index, i))
            {
                cur.push_back(s.substr(index, i-index+1));
                if(i == s.length()-1)
                {
                    res.push_back(cur);
                }
                else
                {
                    getPalinSubstrings(s, i+1, cur, res);
                }
                cur.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s)
    {
        vector<string> curr;
        vector<vector<string>> res;
        
        getPalinSubstrings(s, 0, curr, res);
        
        return res;
    }
};

int main()
{
    Solution S;
    vector<vector<string>> res = S.partition("ababa");
    return 0;
}
