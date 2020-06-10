//
//  reorganize_string.cpp
//
//  Created by omlenka on 11/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Compare
{
public:
    bool operator()(const pair<char,int> &a, const pair<char,int> &b) const
    {
        if(a.second >= b.second)
            return true;
        
        return false;
    }
};
class Solution {
public:
    string reorganizeString(string str)
    {
        set<pair<char,int>,Compare> S;
        
        unordered_map<char,int> M;
        for(char c:str)
            M[c]++;
        
        unordered_map<char,int>::iterator itr;
        for(itr = M.begin();itr != M.end();itr++)
            S.insert(make_pair(itr->first,itr->second));
        
        string res;
        set<pair<char,int>, Compare>::iterator itr1,itr2;
        
        while(!S.empty())
        {
            itr1 = S.begin();
            itr2 = next(itr1,1);
            char c1 = (*itr1).first;
            int count1 = (*itr1).second;
            
            if(!res.empty() && c1 == res[res.size()-1])
                return "";
            res+=string(1,c1);
            
            if(itr2!=S.end())
            {
                char c2 = (*itr2).first;
                int count2 = (*itr2).second;
                
                if(!res.empty() && c2 == res[res.size()-1])
                    return "";
                
                res+= string(1,c2);
                S.erase(itr2);
                if(count2 > 1)
                    S.insert(make_pair(c2,count2-1));
            }
            S.erase(itr1);
            if(count1 > 1)
                S.insert(make_pair(c1,count1-1));
        }
        
        return res;
    }
};
int main()
{
    Solution S;
    string s = S.reorganizeString("aaabbbbbbbcc");
    cout << s << endl;
    return 0;
}
