//
//  house_robber.cpp
//
//  Created by omlenka on 22/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums)
    {
        int include = 0;
        int exclude = 0;
        
        for(int n : nums)
        {
            int tmp = max(include,exclude);
            include = exclude + n;
            exclude = tmp;
        }
        return max(include, exclude);
    }
};
