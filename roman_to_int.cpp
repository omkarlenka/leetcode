//
//  roman_to_int.cpp
//
//  Created by omlenka on 14/07/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s)
    {
        int n = 0;
        unordered_map<string, int> M;
        M["I"] = 1;
        M["V"] = 5;
        M["X"] = 10;
        M["L"] = 50;
        M["C"] = 100;
        M["D"] = 500;
        M["M"] = 1000;
        M["IV"] = 4;
        M["IX"] = 9;
        M["XL"] = 40;
        M["XC"] = 90;
        M["CD"] = 400;
        M["CM"] = 900;
        
        int i = 0;
        while(i < s.length())
        {
            string tmp;
            if(i!=s.length()-1)
            {
                tmp = s.substr(i,2);
                if(M.find(tmp) != M.end())
                {
                    n += M[tmp];
                    i+=2;
                    continue;
                }
            }
            tmp = string(1,s[i]);
            n += M[tmp];
            i++;
        }
        return n;
    }
};
