//
//  4sum_lc18.cpp
//
//  Created by omlenka on 20/02/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> getTwoSum(vector<int> &nums, int start, int target){
        int l = start;
        int r = nums.size()-1;
        vector<vector<int>> res;
        while(l < r){
            if(l-1 >= start && nums[l] == nums[l-1]){
                l++;
                continue;
            }
            if(r+1 < nums.size() && nums[r] == nums[r+1]){
                r--;
                continue;
            }
            if(nums[l] + nums[r] == target)   {
                res.push_back({nums[l],nums[r]});
                l++;
                r--;
            }
            else if(nums[l] + nums[r] < target){
                l++;
            }
            else{
                r--;
            }
        }
        return res;
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        
        
        int i = 0;
        int len = nums.size();
        
        while(i < len-3){
            if(i-1>=0 && nums[i] == nums[i-1]){
                i++;
                continue;
            }
            int j  = i+1;
            while(j < len-2){
                vector<vector<int>> res_tmp;
                if(j > i+1 && nums[j] == nums[j-1]){
                    j++;
                    continue;
                }
                
                res_tmp = getTwoSum(nums, j+1, target-nums[i]-nums[j]);
                for(vector<int> &v:res_tmp){
                    if(!v.empty()){
                        v.push_back(nums[j]);
                        v.push_back(nums[i]);
                        res.push_back(v);
                    }
                }
                j++;
            }
            
            i++;
        }
        
        return res;
    }
};

int main() {
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    Solution S;
    vector<vector<int>> res = S.fourSum(nums, target);
    return 0;
}
