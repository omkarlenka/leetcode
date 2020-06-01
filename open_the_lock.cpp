//
//  open_the_lock.cpp
//
//  Created by omlenka on 02/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    
    int openLockUtil(unordered_set<string> &visited, string target)
    {
        string source = "0000";
        int dist = 0;
        queue<pair<string,int>> Q;
        Q.push(make_pair(source, dist));
        visited.insert(source);
        while(!Q.empty())
        {
            pair<string, int> p = Q.front();
            Q.pop();
            source = p.first;
            dist = p.second;
            if(source == target)
                return dist;
            for(int i = 0;i<4;i++)
            {
                string tmp = source;
                if(tmp[i] == '9')
                {
                    tmp[i] = '0';
                }
                else
                    tmp[i] += 1;
                if(visited.find(tmp) == visited.end())
                {
                    Q.push(make_pair(tmp, dist+1));
                    visited.insert(tmp);
                }
                tmp = source;
                if(tmp[i] == '0')
                {
                    tmp[i] = '9';
                }
                else
                    tmp[i] -= 1;
                if(visited.find(tmp) == visited.end())
                {
                    Q.push(make_pair(tmp, dist+1));
                    visited.insert(tmp);
                }
            }
        }
        return -1;
    }
public:
    int openLock(vector<string>& deadends, string target)
    {
        unordered_set<string> S;
        for(string s:deadends)
        {
            S.insert(s);
        }
        
        if(S.find("0000") != S.end())
            return -1;
        return openLockUtil(S, target);
    }
};

