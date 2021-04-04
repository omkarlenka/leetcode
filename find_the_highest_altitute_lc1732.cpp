//
//  find_the_highest_altitute_lc1732.cpp
//
//  Created by omlenka on 04/04/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0;
        int curr_alt = 0;
        for(int n:gain){
            curr_alt += n;
            res = max(res,curr_alt);
        }
        return res;
    }
};
