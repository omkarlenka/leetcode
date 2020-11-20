//
//  remove_duplicates_from_sorted_array.cpp
//
//  Created by omlenka on 20/11/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        
        int curr_max = nums[0];
        int swap_index = 1;
        for(int i = 1;i<nums.size();i++){
            if(nums[i] > curr_max){
                curr_max = nums[i];
                swap(nums[i],nums[swap_index++]);
            }
        }
        nums.erase(nums.begin()+swap_index, nums.end());
        return nums.size();
    }
};

int main() {
    Solution S;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    cout << S.removeDuplicates(nums) << endl;
    return 0;
}
