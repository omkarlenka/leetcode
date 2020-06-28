//
//  range_sum_query_immutable.cpp
//
//  Created by omlenka on 28/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//
#include <vector>

using namespace std;

class NumArray {
    vector<int> sum;
public:
    NumArray(vector<int>& nums) {
        sum = nums;
        for(int i=1;i<sum.size();i++)
        {
            sum[i] += sum[i-1];
            
        }
    }
    int sumRange(int i, int j)
    {
        if(i == 0)
            return sum[j];
        
        return sum[j]-sum[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
