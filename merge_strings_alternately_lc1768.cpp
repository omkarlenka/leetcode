//
//  merge_strings_alternately_lc1768.cpp
//
//  Created by omlenka on 05/04/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;
        int i=0,j=0;
        while(i < word1.length() && j < word2.length()){
            if(res.length() & 1){
                //word2
                res += string(1,word2[j++]);
            }
            else{
                //word1
                res += string(1,word1[i++]);
            }
        }
        
        if(i < word1.length()){
            res += word1.substr(i,word1.length()-i+1);
        }
        
        if(j < word2.length()){
            res += word2.substr(j,word2.length()-j+1);
        }
        
        return res;
    }
};
