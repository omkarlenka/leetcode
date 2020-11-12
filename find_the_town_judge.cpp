//
//  find_the_town_judge.cpp
//
//  Created by omlenka on 10/11/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if(trust.empty() && N == 1)
            return 1;
        unordered_map<int,pair<int,int>> M;   //people_label : <count_in,count_out>
        for(vector<int> v: trust){
            if(M.find(v[0]) == M.end()){
                M[v[0]] = make_pair(0,1);
            }
            else{
                M[v[0]].second++;
            }
            if(M.find(v[1]) == M.end()){
                M[v[1]] = make_pair(1,0);
            }
            else{
                M[v[1]].first++;
            }
        }
        auto itr = M.begin();
        while(itr != M.end()){
            if(itr->second.first == N-1 && itr->second.second == 0)
                return itr->first;
            itr++;
        }
        return -1;
    }
};
