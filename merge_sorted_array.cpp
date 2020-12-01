//
//  merge_sorted_array.cpp
//
//  Created by omlenka on 01/12/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> merged;
        int i =0,j=0;
        while(i < m  && j < n){
            if(nums1[i] < nums2[j]){
                merged.push_back(nums1[i++]);
            }
            else{
                merged.push_back(nums2[j++]);
            }
        }
        while(i < m){
            merged.push_back(nums1[i++]);
        }
        while(j < n){
            merged.push_back(nums2[j++]);
        }
        
        nums1.clear();
        nums1 = merged;
    }
};
