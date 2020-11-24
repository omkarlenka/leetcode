//
//  add_binary.cpp
//
//  Created by omlenka on 24/11/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string res;
        int l1 = a.length(), l2 = b.length();
        
        int i = l1-1, j = l2-1;
        while(i >= 0 || j >=0){
            int n1,n2;
            if(i >= 0){
                n1 = a[i]-'0';
            }
            else{
                n1 = 0;
            }
            if(j >= 0){
                n2 = b[j]-'0';
            }
            else{
                n2 = 0;
            }
            
            int res_tmp = n1+n2+carry;
            if(res_tmp == 0){
                res += string(1,'0');
                carry = 0;
            }
            else if(res_tmp == 1){
                res  += string(1,'1');
                carry = 0;
            }
            else if(res_tmp == 2){
                res += string(1,'0');
                carry = 1;
            }
            else{//res_tmp == 3
                res += string(1,'1');
                carry = 1;
            }
            i--;
            j--;
        }
        if(carry){
            res += string(1,'1');
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
