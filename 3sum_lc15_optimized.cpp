//
//  3sum_optimized.cpp
//
//  Created by omlenka on 03/02/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() < 3){
            return res;
        }
        
        sort(nums.begin(),nums.end());
        
        for(int i = 0;i<nums.size()-2;i++){
            if(i-1 >= 0 && nums[i] == nums[i-1]){
                continue;
            }
            int l = i+1;
            int r = nums.size()-1;
            int target = -nums[i];
            
            while(l < r){
                if(nums[l] + nums[r] < target){
                    l++;
                }
                else if(nums[l]+nums[r] > target){
                    r--;
                }
                else{
                    res.push_back({nums[i], nums[l], nums[r]});
                    while(l<r && nums[l] == nums[l+1])
                        l++;
                    while(l<r && nums[r] == nums[r-1])
                        r--;
                    l++;
                    r--;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> res = S.threeSum(nums);
    return 0;
}
