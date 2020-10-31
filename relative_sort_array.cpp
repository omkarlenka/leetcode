//
//  relative_sort_array.cpp
//
//  Created by omlenka on 31/10/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> M;
        for(int i = 0;i<arr2.size();i++){
            M[arr2[i]] = i;
        }
        sort(arr1.begin(), arr1.end(), [&](int a, int b){
            if(M.find(a) == M.end() && M.find(b) == M.end())
                return a < b;
            if(M.find(a) == M.end())
                return false;
            if(M.find(b) == M.end())
                return true;
            
            return M[a] < M[b];
        });
        return arr1;
    }
};
