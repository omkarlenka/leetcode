//
//  contains_duplicate_lc217.cpp
//
//  Created by omlenka on 13/01/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> S;
        for(int n : nums){
            if(S.find(n) != S.end())
                return true;
            S.insert(n);
        }
        return false;
    }
};

int main() {
    Solution S;
    vector<int> nums = {1,2,3,4};
    cout << S.containsDuplicate(nums) << endl;
    return 0;
}
