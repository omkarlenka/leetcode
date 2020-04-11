//
//  license_key_formatting.cpp
//
//  Created by omlenka on 11/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

string licenseKeyFormatting(string S, int K)
{
    string new_s;
    int i = S.length()-1;
    while(i>=0)
    {
        int tmp_k = K;
        while(tmp_k--)
        {
            if(S[i] == '-')
            {
                tmp_k++;
                i--;
                if(i<0)
                    break;
                continue;
            }
            if(tmp_k == K-1 && !new_s.empty())
                new_s += '-';
            new_s += toupper(S[i]);
            i--;
            if(i < 0)
                break;
        }            
    }
    reverse(new_s.begin(), new_s.end());
    return new_s;
}

int main()
{
    string s;
    int k;
    cin >> s >> k;
    cout << licenseKeyFormatting(s,k);
    return 0;
}
