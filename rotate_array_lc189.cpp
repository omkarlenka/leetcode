//
//  rotate_array_lc189.cpp
//
//  Created by omlenka on 09/04/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void reverse(vector<int> & v, int start,int end){
        while(start < end){
            swap(v[start++],v[end--]);
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if(k == 0){
            return;
        }
        
        reverse(nums, 0, n-1);
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);
    }
};
