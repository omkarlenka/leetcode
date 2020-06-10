//
//  subarray_sum_equals_k.cpp
//
//  Created by omlenka on 10/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        unordered_map<int,int> M;
        int sum = 0;
        int res = 0;
        M[0] = 1;
        for(int i = 0;i<nums.size();i++)
        {
            sum += nums[i];
            if(M.find(sum-k) != M.end())
            {
                res += M[sum-k];
            }
            M[sum]++;
        }
        return res;
    }
};
