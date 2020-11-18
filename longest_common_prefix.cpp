//
//  longest_common_prefix.cpp
//
//  Created by omlenka on 18/11/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    string getCommonPrefix(string s1, string s2){
        string res = "";
        int i = 0;
        int limit = min(s1.length(), s2.length());
        while(i < limit){
            if(s1[i] == s2[i]){
                res += string(1,s1[i]);
            }
            else
                return res;
            i++;
        }
        return res;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if(strs.empty()){
            return res;
        }
        res = strs[0];
        for(int i = 1;i<strs.size();i++){
            res = getCommonPrefix(res, strs[i]);
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<string> strs = {"flower","flow","flight"};
    cout << S.longestCommonPrefix(strs) << endl;
    
    return 0;
}
