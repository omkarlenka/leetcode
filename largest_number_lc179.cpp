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
    bool operator()(const string &sa, const string &sb) const{
        return (sa+sb > sb+sa);
    }
};
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> res;
        for(int n:nums){
            res.push_back(to_string(n));
        }
        
        sort(res.begin(), res.end(), Comparator());
        string res_string;
        for(string s:res){
            res_string += s;
        }
        if(res_string[0] == '0'){
            res_string.clear();
            res_string = "0";
        }
        return res_string;
    }
};


int main() {
    Solution S;
    vector<int> nums = {3,30,34,5,9};
    
    cout << S.largestNumber(nums) << endl;
    return 0;
}
