//
//  excel_sheet_column_number.cpp
//
//  Created by omlenka on 07/12/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
    inline int charToNum(char c){
        return (c-'A')+1;
    }
public:
    int titleToNumber(string s) {
        int m = 0;
        int res = 0;
        for(int i = s.length()-1;i>=0;i--){
            res += pow(26,m++)*charToNum(s[i]);
        }
        return res;
    }
};
