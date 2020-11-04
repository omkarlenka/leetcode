//
//  intersection_of_two_arrays_II.cpp
//
//  Created by omlenka on 03/11/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> M;
        vector<int> res;
        for(int n:nums1){
            M[n]++;
        }
        for(int n:nums2){
            if(M.find(n) != M.end()){
                if(M[n])
                {
                    M[n]--;
                    res.push_back(n);
                }
            }
        }
        return res;
    }
};
