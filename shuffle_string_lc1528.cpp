//
//  shuffle_string_lc1528.cpp
//
//  Created by omlenka on 27/03/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        size_t len = s.length();
        string res(len,' ');
        
        for(int i = 0;i<len;i++){
            res[indices[i]] = s[i];
        }
        return res;
    }
};
