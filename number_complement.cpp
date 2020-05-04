//
//  number_complement.cpp
//
//  Created by omlenka on 04/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findComplement(int num)
    {
        int no_of_bits = floor(log2(num))+1;
        unsigned int p = (1 << no_of_bits);
        //return (int(pow(2,no_of_bits)-1)) ^ num;  //this works
        return (p-1) ^ num;
    }
};
