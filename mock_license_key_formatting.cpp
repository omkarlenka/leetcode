//
//  mock_license_key_formatting.cpp
//
//  Created by omlenka on 15/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K)
    {
        string res = "";
        int i = S.length()-1;
        
        while(i>=0)
        {
            int k = 0;
            bool done = false;
            while(i >= 0 && k<K)
            {
                if(S[i] != '-')
                {
                    res += string(1, toupper(S[i]));
                    k++;
                    done = true;
                }
                i--;
            }
            if(done)
                res += "-";
        }
        if(res.empty())
            return res;
        if(res[res.length()-1] == '-')
            res = res.substr(0,res.length()-1);
        reverse(res.begin(), res.end());
        return res;
    }
};
