//
//  intersection_of_two_arrays.cpp
//
//  Created by omlenka on 03/11/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> arr;
        set<int> res;
        for(int n:nums1){
            arr.insert(n);
        }
        for(int n:nums2){
            if(arr.find(n) != arr.end()){
                res.insert(n);
            }
        }
        return vector<int>(res.begin(),res.end());
    }
};
