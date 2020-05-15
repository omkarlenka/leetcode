//
//  bulls_and_cows.cpp
//
//  Created by omlenka on 15/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess)
    {
        int A = 0, B = 0;
        
        vector<int> v(256,0);
        
        for(int i = 0;i<secret.length();i++)
        {
            if(secret[i] == guess[i])
            {
                A++;
            }
            else
                v[secret[i]]++;
        }
        
        for(int i = 0;i<secret.length();i++)
        {
            if(secret[i] != guess[i] && v[guess[i]])
            {
                B++;
                v[guess[i]]--;
            }
        }
        return to_string(A) + "A" + to_string(B) + "B";
    }
};
