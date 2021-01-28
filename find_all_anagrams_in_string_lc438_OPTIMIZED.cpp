//
//  find_all_anagrams_in_string_lc438_OPTIMIZED.cpp
//
//  Created by omlenka on 28/01/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
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
                if(mapping[s[r]-'a']){
                    while(s[r] != s[l]){
                        tmp_mapping[s[l]-'a']++;
                        l++;
                        to_be_matched++;
                    }
                    tmp_mapping[s[l]-'a']++;
                    l++;
                    to_be_matched++;
                }
                else{
                    tmp_mapping = mapping;
                    to_be_matched= len;
                    r++;
                    l = r;
                }
            }
        }
        if(to_be_matched == 0){
            res.push_back(l);
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<int> res = S.findAnagrams("cbaebca", "abc");
    
    return 0;
}
