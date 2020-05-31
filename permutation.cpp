//
//  permutation.cpp
//
//  Created by omlenka on 31/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void permuteUtil(vector<int> &nums, int s, int e, vector<int> v, vector<vector<int>> &res)
    {
        if(s == e)
        {
            v.push_back(nums[s]);
            res.push_back(v);
        }
        else
        {
            for(int i = s; i <=  e;i++)
            {
                swap(nums[s], nums[i]);
                v.push_back(nums[s]);
                permuteUtil(nums, s+1, e, v, res);
                v.pop_back();
                swap(nums[s], nums[i]);
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> res;
        vector<int> v;
        permuteUtil(nums, 0, nums.size()-1, v, res);
        
        return res;
    }
};
