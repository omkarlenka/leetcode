//
//  excel_sheet_column_title_lc168.cpp
//
//  Created by omlenka on 14/04/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        while(columnNumber > 26){
            int  r = columnNumber % 26;
            if(r == 0){
                res += string(1,'Z');
                columnNumber /= 26;
                columnNumber--;
            }
            else{
                res += string(1,'A'+(r-1));
                columnNumber /= 26;
            }
            
        }
        res += string(1,'A'+(columnNumber-1));
        reverse(res.begin(),res.end());
        return res;
    }
};

