//
//  find_and _replace_in_string.cpp
//
//  Created by omlenka on 24/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets)
{
    if(indexes.size() == 0)
        return  S;
    
    map<int,pair<string,string>> M;
    for(int i = 0;i<indexes.size();i++)
    {
        M[indexes[i]] = make_pair(sources[i], targets[i]);
    }
    
    vector<string> V;
    int covered = -1;
    int idx, len;
    string sub;
    map<int,pair<string,string>>::iterator itr;
    
    for(itr = M.begin();itr != M.end();itr++)
    {
        if(itr->first > covered)
        {
            idx = covered+1;
            len = itr->first - idx;
            if(len > 0)
            {
                string sub = S.substr(idx, len);
                V.push_back(sub);
                covered += len;
            }
        }
        
        len = itr->second.first.length();
        idx = itr->first;
        sub = S.substr(idx, len);
        if(sub == itr->second.first)
        {
            V.push_back(itr->second.second);
            covered += len;
        }
    }
    if(covered != S.length())
    {
        idx = covered+1;
        len = S.length() - idx;
        if(len > 0)
        {
            string sub = S.substr(idx, len);
            V.push_back(sub);
            covered += len;
        }
    }
    string res;
    for(string r : V)
        res += r;
    
    return res;
}

int main()
{
//    string  S = "abcd";
//    vector<int> indexes = {0,2};
//    vector<string> sources = {"a","cd"};
//    vector<string> targets = {"eee","ffff"};
    
//    string  S = "abcdef";
//    vector<int> indexes = {1,2};
//    vector<string> sources = {"bcd","cdef"};
//    vector<string> targets = {"eee","pqrs"};
    
    string  S  = "vmokgggqzp";
    vector<int> indexes = {3,5,1};
    vector<string> sources = {"kg","ggq","mo"};
    vector<string> targets = {"s","so","bfr"};
    
    cout << findReplaceString(S, indexes, sources, targets) << endl;
    return 0;
}
