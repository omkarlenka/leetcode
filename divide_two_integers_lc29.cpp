//
//  divide_two_integers_lc29.cpp
//
//  Created by omlenka on 05/01/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
    int divideUtil(int dividend, int divisor, int &remainder){
        if(dividend < 0){
            //this is INT_MIN
            dividend = INT_MAX;
            remainder += 1;
        }
        if(dividend == divisor)
            return 1;
        if(dividend < divisor){
            remainder += dividend;
            return 0;
        }
        int m = dividend >> 1;
        int res;
        if(m >= divisor){
            if(dividend & 1){
                int even = divideUtil(m,divisor,remainder);
                int odd = divideUtil(m+1,divisor,remainder);
                res = even + odd;
            }
            else{
                int tmp_rem = 0;
                int tmp_res = divideUtil(m,divisor,tmp_rem);
                res = tmp_res + tmp_res;
                remainder += tmp_rem + tmp_rem;
            }
        }
        else{
            res = 1;
            remainder += dividend - divisor;
        }
        return res;
    }
public:
    int divide(int dividend, int divisor) {
        if(dividend < INT_MIN  || dividend > INT_MAX)
            return INT_MAX;
        if(divisor < INT_MIN  || divisor > INT_MAX)
            return INT_MAX;
        if(dividend ==  0)
            return 0;
        if(divisor == 1){
            return dividend;
        }
        if(divisor == -1){
            long tmp_res = 0-long(dividend);
            if(tmp_res > INT_MAX || tmp_res < INT_MIN)
                return INT_MAX;
        }
        int remainder = 0;
        bool negative = false;
        if(divisor <  0 && dividend < 0){
            negative = false;
        }
        else if(divisor <  0 || dividend < 0){
            negative = true;
        }
        int res = divideUtil(abs(dividend), abs(divisor), remainder);
        while(remainder >= abs(divisor)){
            int tmp_rm = 0;
            res += divideUtil(remainder, abs(divisor), tmp_rm);
            remainder = tmp_rm;
        }
        if(negative){
            res = 0-res;
        }
        return res;
    }
};


int main() {
    Solution S;
    cout << S.divide(-2147483648, 2) << endl;
    return 0;
}
