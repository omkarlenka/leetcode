//
//  longest_string_chain.cpp
//
//  Created by omlenka on 07/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
class Comparator
{
public:
    bool operator()(const string &l, const string &r) const
    {
        return (l.length() < r.length());
    }
};

class Solution {
public:
    int longestStrChain(vector<string>& words)
    {
        sort(words.begin(), words.end(), Comparator());
        map<string, int> m;
        for(int i = 0;i<words.size();i++)
        {
            m[words[i]] = 1;
        }
        
        // map<string,int>::iterator itr = m.begin();
        int max_chain = 1;
        for(string word: words)
        {
            if(word.length() == 1)
                continue;
            if(word == "rfcv")
                word = word;
            map<string, int>::iterator itr;
            for(int i = 0;i < word.length();i++)
            {
                string s(word);
                s.erase(i,1);
                itr = m.find(s);
                if(itr != m.end())
                {
                    m[word] = max(itr->second+1, m[word]);
                    if(m[word] > max_chain)
                        max_chain = m[word];
                }
            }
        }
        return max_chain;
    }
};
