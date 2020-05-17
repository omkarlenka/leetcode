//
//  height_checker.cpp
//
//  Created by omlenka on 17/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights)
    {
        vector<int> heights_sorted(heights.begin(), heights.end());
        sort(heights_sorted.begin(),  heights_sorted.end());
        int res = 0;
        
        for(int i = 0;i<heights.size();i++)
        {
            if(heights_sorted[i] != heights[i])
                res++;
        }
        return res;
    }
};
