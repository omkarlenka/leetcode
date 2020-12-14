//
//  find_all_anagrams_in_string.cpp
//
//  Created by omlenka on 14/12/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(p.empty()){
            return res;
        }
        vector<int> mapping(26,0);
        for(const char &c: p){
            mapping[c-'a']++;
        }
        
        int l=0, r=l;
        int len = p.length();
        int to_be_matched = len;
        vector<int> tmp_mapping(mapping.begin(), mapping.end());
        
        while(r < s.length()){
            if(tmp_mapping[s[r]-'a']){
                tmp_mapping[s[r]-'a']--;
                to_be_matched--;
                r++;
            }
            else{
                if(to_be_matched == 0){
                    res.push_back(l);
                }
                if(to_be_matched < len){
                    tmp_mapping = mapping;
                    to_be_matched= len;
                }
                l++;
                r = l;
            }
        }
        if(to_be_matched == 0){
            res.push_back(l);
        }
        return res;
    }
};
