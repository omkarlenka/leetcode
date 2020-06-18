//
//  missing_number.cpp
//
//  Created by omlenka on 19/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int sum = 0;
        int n = nums.size();
        for(int n:nums)
            sum+= n;
        
        return (n*(n+1)/2)-sum;
    }
};
