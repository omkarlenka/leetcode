//
//  ugly_number_lc263.cpp
//
//  Created by omlenka on 14/02/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        bool res = false;
        if(num == 0)
            return res;
        while(num % 5 == 0){
            num /= 5;
        }
        while(num % 3 == 0){
            num /= 3;
        }
        while(num % 2 == 0){
            num /= 2;
        }
        if(num == 1)
            res = true;
        return res;
    }
};
