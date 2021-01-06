//
//  subarray_product_less_than_k_lc713.cpp
//
//  Created by omlenka on 06/01/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1)
            return 0;
        int l = 0, r = 0;
        int prod = 1;
        int res = 0;
        while(r < nums.size()){
            prod *= nums[r];
            while(prod >= k){
                prod /= nums[l];
                l++;
            }
            res += r-l+1;
            r++;
        }
        return res;
    };
    
};

int main() {
    Solution S;
    vector<int> nums = {10,5,2,6};
    cout << S.numSubarrayProductLessThanK(nums, 100) << endl;
    return 0;
}
