//
//  largest_number_lc179.cpp
//
//  Created by omlenka on 21/01/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Comparator{
public:
    bool operator()(const int &a, const int &b) const{
        if(a == b)
            return false;
        
        string sa = to_string(a);
        string sb = to_string(b);
        
        bool res = false;
        
        if(sa+sb > sb+sa){
            res = true;
        }
        else if(sa+sb < sb+sa){
            res = false;
        }
        
        return res;
    }
};
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), Comparator());
        string res;
        for(int n:nums){
            res += to_string(n);
        }
        if(res[0] == '0'){
            res.clear();
            res = "0";
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<int> nums = {3,30,34,5,9};
    
    cout << S.largestNumber(nums) << endl;
    return 0;
}
