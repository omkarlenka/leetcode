//
//  defanging_an_ip_address_lc1108.cpp
//
//  Created by omlenka on 25/02/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        string res;
        for(char c:address){
            if(c == '.'){
                res += "[.]";
            }
            else{
                res += string(1,c);
            }
        }
        return res;
    }
};
