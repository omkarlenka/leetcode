//
//  int_to_roman.cpp
//
//  Created by omlenka on 14/07/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
#include <cmath>

using namespace std;

class Solution {
    string util(string n, int s, int l, map<int,string> &M)
    {
        //127
        string res = "";
        if(l == 0)
            return res;
        int d = (n[s]-'0')*pow(10,l-1);
        
        if(d != 0)
        {
            auto itr = M.lower_bound(d);
            if(itr->first == d)
            {
                res = itr->second;
            }
            else
            {
                itr = prev(itr);
                int q = d/(itr->first);
                while(q--)
                {
                    res += itr->second;
                }
                int r = d%(itr->first);
                if(r != 0)
                {
                    string reminder = to_string(d - (itr->first));
                    res += util(reminder, 0, reminder.length(),M);
                }
            }
        }
        
        res += util(n,s+1,l-1,M);
        
        return res;
        
    }
public:
    string intToRoman(int num)
    {
        string res;
        if(num > 3999)
            return res;
        map<int, string> M;
        M[1] = "I";
        M[2] = "II";
        M[3] = "III";
        M[4] = "IV";
        M[5] = "V";
        M[6] = "VI";
        M[7] = "VII";
        M[8] = "VIII";
        M[9] = "IX";
        M[10] = "X";
        M[40] = "XL";
        M[50] = "L";
        M[90] = "XC";
        M[100] = "C";
        M[400] = "CD";
        M[500] = "D";
        M[900] = "CM";
        M[1000] = "M";
        
        string n = to_string(num);
        res = util(n, 0, n.length(), M);
        return res;
    }
};

int main()
{
    Solution S;
    cout << S.intToRoman(1123)<< endl;
    return 0;
}
