//
//  longest_repeating_char_replacement_lc424.cpp
//
//  Created by omlenka on 03/02/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int getMaxCount(vector<int> &count){
        int max = 0;
        for(int c:count){
            if(c > max)
                max = c;
        }
        return max;
    }
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        if(s.empty())
            return res;
        vector<int> count(26,0);
        int l = 0, r = 0;
        int max_count = 1;
        count[s[0]-'A']++;
        
        while(l <=r && r<s.length()){
            while((r-l+1) - max_count <= k){
                r++;
                if(r == s.length())
                    break;
                count[s[r]-'A']++;
                max_count = max(max_count, count[s[r]-'A']);
            }
            
            if(r-l > res){
                res = r-l;
            }
            count[s[l]-'A']--;
            l++;
            max_count = getMaxCount(count);
        }
        return res;
    }
};

int main() {
    Solution S;
    cout << S.characterReplacement("AABABBA", 1) << endl;
    return 0;
}
