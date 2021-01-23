//
//  combination_II_lc40.cpp
//
//  Created by omlenka on 23/01/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> combinationSumUtil(const vector<int>& candidates, int start_index, int target){
        vector<vector<int>> res;
        if(candidates.empty() || start_index == candidates.size() || target < candidates[start_index]){
            return res;
        }
        
        for(int i = start_index;i<candidates.size();i++){
            if(i > start_index && candidates[i] == candidates[i-1])
                continue;
            if(target == candidates[i]){
                res.push_back({candidates[i]});
                break;
            }
            else{
                vector<vector<int>> res_tmp = combinationSumUtil(candidates, i+1, target-candidates[i]);
                
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
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return combinationSumUtil(candidates, 0, target);
    }
};

int main() {
    Solution S;
    vector<int> candidates = {4,4,2,1,4,2,2,1,3};
    vector<vector<int>> res = S.combinationSum2(candidates, 6);
    return 0;
}
