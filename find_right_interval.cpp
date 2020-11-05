//
//  find_right_interval.cpp
//
//  Created by omlenka on 05/11/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        unordered_map<int,int> UM;
        map<int,int> M;
        int len = intervals.size();
        vector<int> res(len, -1);
        
        for(int i = 0;i<len;i++){
            UM[intervals[i][0]] = i;
        }
        for(vector<int> interval:intervals){
            M[interval[0]] = interval[1];
        }
        
        auto itr = M.begin();
        while(itr != M.end()){
            auto itr_res = M.lower_bound(itr->second);
            if(itr_res != M.end()){
                res[UM[itr->first]]  = UM[itr_res->first];
            }
            itr++;
        }
        return res;
    }
};
