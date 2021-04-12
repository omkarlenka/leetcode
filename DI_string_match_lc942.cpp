//
//  DI_string_match_lc942.cpp
//
//  Created by omlenka on 12/04/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.length();
        int inc = 0, dec = n;
        vector<int> perm;
        if(s[0] == 'I'){
            perm.push_back(inc++);
        }
        else{
            perm.push_back(dec--);
        }
        
        for(int i = 0;i<n;i++){
            if(s[i] == 'I'){
                if(i+1<n && s[i+1] == 'I'){
                    perm.push_back(inc++);
                }
                else{
                    perm.push_back(dec--);
                }
            }
            else{
                if(i+1<n && s[i+1] == 'D'){
                    perm.push_back(dec--);
                }
                else{
                    perm.push_back(inc++);
                }
            }
        }
        return perm;
    }
};

