//
//  sort_array_by_parity_lc905.cpp
//
//  Created by omlenka on 27/04/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int e = -1;
        for(int i=0;i<A.size();i++){
            if(!(A[i] & 1)){
                swap(A[++e],A[i]);
            }
        }
        return A;
    }
};
