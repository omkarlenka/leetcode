//
//  unique_occur_lc1207.cpp
//
//  Created by omlenka on 29/04/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> M;
        for(int a:arr){
            M[a]++;
        }
        
        unordered_set<int> S;
        bool res = true;
        for(auto itr = M.begin();itr != M.end();itr++){
            if(S.find(itr->second) == S.end()){
                S.insert(itr->second);
            }
            else{
                res = false;
                break;
            }
        }
        return res;
    }
};
