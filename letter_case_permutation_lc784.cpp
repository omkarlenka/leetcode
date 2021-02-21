//
//  main.cpp
//  letter_case_permutation_lc784.cpp
//
//  Created by omlenka on 21/02/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void util(string S, int start, vector<string> &res){
        if(start == S.length())
            return;
        util(S, start+1, res);
        if(isalpha(S[start])){
            char c = tolower(S[start]);
            if(res.empty()){
                res.push_back(string(1,c));
                res.push_back(string(1,toupper(c)));
            }
            else{
                vector<string> res_tmp = res;
                for(string &s:res){
                    s = string(1,c) + s;
                }
                for(string s:res_tmp){
                    res.push_back(string(1,toupper(c))+s);
                }
            }
        }
        else{
            char c = S[start];
            if(res.empty()){
                res.push_back(string(1,c));
            }
            else{
                for(string &s:res){
                    s = string(1,c) + s;
                }
            }
        }
    }
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        util(S,0,res);
        return res;
    }
};


int main() {
    Solution S;
    vector<string> res = S.letterCasePermutation("ab12");
    return 0;
}
