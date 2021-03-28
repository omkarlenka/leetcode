//
//  number_of_steps_to_reduce_to_zero_lc1342.cpp
//
//  Created by omlenka on 28/03/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int numberOfSteps (int num) {
        int res = 0;
        while(num != 0){
            if(num & 1){
                num--;
            }
            else{
                num /= 2;
            }
            
            res++;
        }
        return res;
    }
};
