//
//  target_sum_lc494.cpp
//
//  Created by omlenka on 22/01/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        unordered_map<int,int> prev;
        
        prev[nums[0]] = 1;
        if(nums[0] == 0){
            prev[nums[0]] *= 2;
        }
        else{
            prev[-nums[0]] = 1;
        }
        auto itr = prev.begin();
        for(int i = 1;i<nums.size();i++){
            unordered_map<int,int> curr;
            itr = prev.begin();
            while(itr != prev.end()){
                curr[itr->first+nums[i]] += itr->second;
                if(nums[i] == 0){
                    curr[itr->first+nums[i]] *= 2;
                }
                else{
                    curr[itr->first-nums[i]] += itr->second;
                }
                itr++;
            }
            prev = curr;
        }
        itr = prev.begin();
        int res = 0;
        while(itr != prev.end()){
            if(itr->first == S){
                res += itr->second;
            }
            itr++;
        }
        
        return res;
    }
};

int main() {
    Solution S;
    vector<int> nums = {1,1,1,1,1};
    int s = 3;
    cout << S.findTargetSumWays(nums, s) << endl;
    return 0;
}
