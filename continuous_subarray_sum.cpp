//
//  continuous_subarray_sum.cpp
//
//  Created by omlenka on 13/12/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    inline bool hasConsecutiveZero(vector<int>& nums){
        for(int i = 1;i<nums.size();i++){
            if(nums[i-1] == 0 && nums[i] == 0){
                return true;
            }
        }
        return false;
    }
    inline bool handleZero(vector<int>& nums){
        if(hasConsecutiveZero(nums)){
            return true;
        }
        return false;
    }
    
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(k == 0){
            return handleZero(nums);
        }
        if(hasConsecutiveZero(nums))
            return true;
        unordered_set<int> prefix;
        for(int &n : nums){
            n = n%k;
        }
        
        int sum;
        
        for(int i = 0;i < nums.size();i++){
            if(prefix.empty()){
                prefix.insert(nums[i]);
                sum = nums[i];
                continue;
            }
            sum += nums[i];
            sum = sum % k;
            if(nums[i] != 0 && prefix.find(sum) != prefix.end()){
                return true;
            }
            else{
                prefix.insert(sum);
            }
            if(sum == 0 && i > 0)
                return true;
        }
        if(sum == 0 && nums.size() > 1)
            return true;
        return false;
    }
};

int main() {
    Solution S;
    vector<int> nums = {1,0};
    
    int k = 15;
    cout << S.checkSubarraySum(nums, 12) << endl;
    return 0;
}
