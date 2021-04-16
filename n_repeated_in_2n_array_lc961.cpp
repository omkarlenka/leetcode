//
//  n_repeated_in_2n_array_lc961.cpp
//
//  Created by omlenka on 16/04/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_set<int> S;
        int res;
        for(int a: A){
            if(S.find(a) != S.end()){
                res = a;
                break;
            }
            S.insert(a);
        }
        return res;
    }
};
