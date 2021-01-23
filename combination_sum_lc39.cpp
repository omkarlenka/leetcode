//
//  combination_sum_lc39.cpp
//
//  Created by omlenka on 23/01/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> combinationSumUtil(vector<int>& candidates, int start_index, int target){
        vector<vector<int>> res;
        if(candidates.empty() || target < candidates[start_index]){
            return res;
        }
        for(int i = start_index;i<candidates.size();i++){
            if(target == candidates[i]){
                res.push_back({candidates[i]});
            }
            else{
                vector<vector<int>> res_tmp = combinationSumUtil(candidates, i, target-candidates[i]);
                if(!res_tmp.empty()){
                    for(vector<int> &v: res_tmp){
                        v.push_back(candidates[i]);
                        res.push_back(v);
                    }
                }
            }
        }
        
        return res;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return combinationSumUtil(candidates, 0, target);
    }
};
