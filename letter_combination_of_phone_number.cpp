//
//  letter_combination_of_phone_number.cpp
//
//  Created by omlenka on 01/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        if(digits.length()  ==  0)
            return res;
        
        int n = digits[0]-'0';
        int len = 3;
        if(n == 7 || n == 9)
            len = 4;
        char start_letter;
        
        if(n <= 7)
        {
            start_letter = 'a' + (n-2)*3;
        }
        else
        {
            start_letter = 'a' + (n-2)*3+1;
        }
        
        int i = 0;
        while(i < len)
        {
            string s(1, + start_letter + i);
            if(digits.length() > 1)
            {
                vector<string> res_recur = letterCombinations(digits.substr(1,digits.length()-1));
                for(string s_recur : res_recur)
                {
                    res.push_back(s + s_recur);
                }
            }
            else
            {
                res.push_back(s);
            }
            i++;
        }
        return res;
    }
};
