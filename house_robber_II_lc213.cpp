//
//  house_robber_II_lc213.cpp
//
//  Created by omlenka on 12/02/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        
        int include = 0,exclude = 0;
        int res1 = 0, res2 = 0;
        for(int i = 0;i<n-1;i++){
            int tmp = max(include,exclude);
            include = exclude + nums[i];
            exclude = tmp;
        }
        
        res1 = max(include, exclude);
        include = 0,exclude = 0;
        for(int i = 1;i<n;i++){
            int tmp = max(include,exclude);
            include = exclude + nums[i];
            exclude = tmp;
        }
        res2 = max(include, exclude);
        
        return max(res1,res2);
    }
};

int main() {
    Solution S;
    vector<int> nums = {2,3,2};
    cout << S.rob(nums) << endl;
    
    return 0;
}
