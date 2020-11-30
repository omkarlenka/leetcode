//
//  permutations_II.cpp
//
//  Created by omlenka on 30/11/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void permuteUtil(vector<int> &nums, int start, int &len, vector<vector<int>> & res){
        if(start == len){
            res.push_back(nums);
            return;
        }
        
        
        for(int j = start; j < len;j++){
            bool dup = false;
            for(int i = start;i<j;i++){
                if(nums[i] == nums[j]){
                    dup = true;
                    break;
                }
            }
            if(dup)
                continue;
            swap(nums[start], nums[j]);
            permuteUtil(nums, start+1, len, res);
            swap(nums[start], nums[j]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        int len = nums.size();
        permuteUtil(nums,0,len,res);
        return res;
    }
};

int main() {
    Solution S;
    vector<int> nums =  {2,1,1};
    vector<vector<int>> res = S.permuteUnique(nums);
    
    return 0;
}
