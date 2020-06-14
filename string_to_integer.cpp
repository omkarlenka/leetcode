//
//  string_to_integer.cpp
//
//  Created by omlenka on 14/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int myAtoi(string str)
    {
        int res = 0;
        bool neg = false;
        int i = 0;  //starting index after whitespace
        while(i < str.length() && str[i] == ' ')
            i++;
        if(i == str.length())
            return res;
        
        if(str[i] == '-')
        {
            i++;
            neg = true;
        }
        bool int_max = false;
        while(i < str.length() && isdigit(str[i]))
        {
            int digit = str[i]-'0';
            if(res > (INT_MAX-digit)/10)
            {
                int_max = true;
                res = INT_MAX;
                break;
            }
            res = (res*10) +(str[i]-'0');
            i++;
        }
        if(neg)
        {
            if(int_max)
                res = INT_MIN;
            else
                res *= -1;
        }
        return res;
    }
};


int main()
{
    Solution S;
    cout << S.myAtoi("-2147483648");
    return 0;
}
