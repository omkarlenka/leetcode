//
//  generate_paranthesis.cpp
//
//  Created by omlenka on 29/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        if(n == 0)
            return res;
        unordered_set<string> S;
        if(n == 1)
        {
            S.insert("()");
            res.resize(S.size());
            std::copy(S.begin(),S.end(),res.begin());
            return res;
        }
        res = generateParenthesis(n-1);
        for(string p:res)
        {
            for(int i = 0;i<=p.length();i++)
            {
                S.insert(p.substr(0,i) + "()" + p.substr(i,p.length()-i));
            }
        }
        res.resize(S.size());
        copy(S.begin(),S.end(),res.begin());
        return res;
    }
};
