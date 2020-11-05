//
//  arranging_coins.cpp
//
//  Created by omlenka on 05/11/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        /*
         x^2+x-2*n = 0
         x = (-1 + sqrt(1+8*n))/2
         */
        int x = (sqrt(1+(double)8*n)-1)/2;
        return x;
    }
};
