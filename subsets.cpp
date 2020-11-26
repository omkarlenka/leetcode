//
//  subsets.cpp
//
//  Created by omlenka on 26/11/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    void subsetsUtil(vector<int> &nums, unordered_map<int, vector<vector<int>>> &M, int len){
        vector<vector<int>> V = M[len-1];
        for(int i = 0;i<nums.size();i++){
            for(int j = V.size()-1;j>=0;j--){
                auto itr = find(V[j].begin(), V[j].end(), nums[i]);
                if(itr == V[j].end()){
                    vector<int> V_tmp;
                    V_tmp = V[j];
                    V_tmp.push_back(nums[i]);
                    
                    if(M.find(len) == M.end()){
                        vector<vector<int>> value;
                        value.push_back(V_tmp);
                        M[len] = value;
                    }
                    else{
                        M[len].push_back(V_tmp);
                    }
                }
                else{
                    break;
                }
            }
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_map<int, vector<vector<int>>> M;
        int len = nums.size();
        M[0] = {{}};
        vector<vector<int>> tmp;
        for(int n:nums){
            vector<int> v_tmp;
            v_tmp.push_back(n);
            tmp.push_back(v_tmp);
        }
        M[1] = tmp;
        for(int i = 2;i<=len;i++){
            subsetsUtil(nums, M, i);
        }
        auto itr = M.begin();
        while(itr != M.end()){
            res.insert(res.end(), itr->second.begin(), itr->second.end());
            itr++;
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1,2,3,4};
    Solution S;
    vector<vector<int>> res = S.subsets(nums);
    return 0;
}
