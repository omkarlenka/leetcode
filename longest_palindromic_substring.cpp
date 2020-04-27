//
//  longest_palindromic_substring.cpp
//
//  Created by omlenka on 27/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestPalindrome(string s)
{
    int l = int(s.length());
    vector<vector<int>> v(l);
    for(int i = 0;i<l;i++)
    {
        vector<int> tmp(l);
        for(int j = 0;j<l;j++)
        {
            if(i == j)
                tmp[j] = 1;
            else
                tmp[j] = 0;
        }
        v[i] = tmp;
    }
    
    string res = s.substr(0,1);
    
    for(int i = l-2;i>=0;i--)
    {
        for(int j = i+1;j<l;j++)
        {
            if(s[i] == s[j])
            {
                if(v[i+1][j-1] || j-i == 1)
                {
                    v[i][j] = v[i+1][j-1]+2;
                    if(j-i+1 > res.length())
                        res = s.substr(i,j-i+1);
                }
            }
        }
    }
    return res;
}

int main()
{
    string s = "abacab";
    cout << longestPalindrome(s) << endl;
    return 0;
}
