//
//  positions_of_large_groups.cpp
//
//  Created by omlenka on 02/12/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> res;
        int l=0, r=0;
        int count = 0;
        while(r < S.length()){
            if(S[l] == S[r]){
                count++;
                r++;
            }else{
                if(count >= 3){
                    vector<int> v;
                    v.push_back(l);
                    v.push_back(r-1);
                    res.push_back(v);
                }
                count = 0;
                l = r;
            }
        }
        if(count >= 3){
            vector<int> v;
            v.push_back(l);
            v.push_back(r-1);
            res.push_back(v);
        }
        return res;
    }
};
