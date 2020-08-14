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
    bool isPalindrome(string s, int i, int len)
    {
        int l = i, r = i+len-1;
        
        while(l <= r)
        {
            if(s[l] != s[r])
                return false;
            
            l++;
            r--;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s)
    {
        int l = s.length();
        unordered_map<int, vector<vector<string>>> M;
        M[-1] = {{}};
        for(int i = 0;i<l;i++)
        {
            vector<vector<string>> res;
            for(int j = 1;j<=i+1;j++)
            {
                if(isPalindrome(s, i-j+1, j)) //string, index, length
                {
                    vector<vector<string>> prev = M[i-j];
                    for(vector<string> v_prev : prev)
                    {
                        vector<string> v = v_prev;
                        v.push_back(s.substr(i-j+1,j));
                        res.push_back(v);
                    }
                }
            }
            
            M[i] = res;
            
        }
        return M[l-1];
    }
};

int main()
{
    Solution S;
    vector<vector<string>> res = S.partition("ababa");
    return 0;
}
