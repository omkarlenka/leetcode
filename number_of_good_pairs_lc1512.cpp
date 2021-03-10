//
//  number_of_good_pairs_lc1512.cpp
//
//  Created by omlenka on 10/03/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> M;
        int res = 0;
        
        for(int n: nums){
            if(M.find(n) != M.end()){
                res += M[n];
            }
            M[n]++;
        }
        
        return res;
    }
};
