//
//  verifying_alien_dictionary.cpp
//
//  Created by omlenka on 27/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
    unordered_map<char,int> M;
    //returns true if w1 > w2
    bool isGreater(string w1, string w2)
    {
        int i1=0, i2=0;
        while(i1 < w1.length() && i2 < w2.length())
        {
            if(M[w1[i1]] < M[w2[i2]])
                return true;
            else if(M[w1[i1]] > M[w2[i2]])
                return false;
            i1++;
            i2++;
        }
        if(i1 == w1.length())
            return true;
        return false;
    }
public:
    bool isAlienSorted(vector<string>& words, string order)
    {
        for(int i = 0;i<order.length();i++)
        {
            M[order[i]] = i;
        }
        
        for(int i = 1;i<words.size();i++)
        {
            if(!isGreater(words[i-1],words[i]))
            {
                return false;
            }
        }
        M.clear();
        return true;
    }
};


