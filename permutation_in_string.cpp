//
//  permutation_in_string.cpp
//
//  Created by omlenka on 12/12/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> mapping(26,0);
        int len = s1.length();
        for(char c:s1){
            mapping[c-'a']++;
        }
        
        int l = 0, r = 0;
        vector<int> tmp_mapping(mapping.begin(),mapping.end());
        int to_be_compared = len;
        
        while(r < s2.length()){
            if(tmp_mapping[s2[r]-'a'] > 0){
                to_be_compared--;
                tmp_mapping[s2[r]-'a']--;
                r++;
            }
            else{
                if(to_be_compared == 0){
                    return true;
                }
                else if (to_be_compared < len){
                    tmp_mapping = mapping;
                    to_be_compared = len;
                }
                l++;
                r = l;
            }
        }
        if(to_be_compared == 0){
            return true;
        }
        return false;
    }
};

int main() {
    Solution S;
    cout << S.checkInclusion("ab", "eidbaooo") << endl;
    return 0;
}
