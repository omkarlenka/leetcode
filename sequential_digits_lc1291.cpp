//
//  sequential_digits_lc1291.cpp
//
//  Created by omlenka on 22/12/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
    int noOfDigits(int n){
        int d = 0;
        while(n){
            n /= 10;
            d++;
        }
        return d;
    }
    
    int getSequentialNumber(int start_digit, int digits){
        int d = 0;
        int num  = 0;
        
        while(d < digits){
            if(start_digit > 9){
                return -1;
            }
            num = (num*10)+start_digit;
            start_digit++;
            d++;
        }
        return num;
    }
    
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        int digits = noOfDigits(low);
        int start_digit = low / (pow(10,(digits-1)));
        
        int next_num = getSequentialNumber(start_digit, digits);
        if(next_num == -1){
            start_digit = 0;
            digits++;
        }
        if(next_num < low)
            next_num = -1;
        
        while(next_num == -1 || (next_num >= low && next_num <= high)){
            if(digits > 9)
                break;
            if(next_num != -1)
                res.push_back(next_num);
            next_num = getSequentialNumber(++start_digit, digits);
            
            if(next_num == -1){
                start_digit = 0;
                digits++;
            }
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<int> res = S.sequentialDigits(58, 155);
    
    return 0;
}
