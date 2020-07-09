//
//  remove_duplicate_letters.cpp
//
//  Created by omlenka on 10/07/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <unordered_set>
#include <unordered_map>
#include <set>
#include <string>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string text)
    {
        unordered_map<char,int> last;
        stack<char> stk;
        unordered_set<char> S;
        
        for(int i = 0;i<text.length();i++)
        {
            last[text[i]] = i;
        }
        
        for(int i = 0;i<text.length();i++)
        {
            if(S.find(text[i]) != S.end())
                continue;
            
            S.insert(text[i]);
            while(!stk.empty())
            {
                char prev = stk.top();
                if(prev > text[i] && last[prev] > i)
                {
                    stk.pop();
                    S.erase(prev);
                }
                else
                    break;
            }
            stk.push(text[i]);
        }
        
        string r;
        while(!stk.empty())
        {
            char c= stk.top();
            stk.pop();
            r += string(1,c);
        }
        reverse(r.begin(),r.end());
        return r;
        
    }
};
