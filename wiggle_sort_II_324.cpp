//
//  wiggle_sort_II.cpp
//
//  Created by omlenka on 28/12/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.rbegin(), sorted.rend());
        
        int i = nums.size()/2;
        
        int j = 0, k = 0;
        while(k < nums.size()){
            if(k & 1){
                nums[k++] = sorted[j++];
            }
            else{
                nums[k++] = sorted[i++];
            }
        }
    }
};

int main() {
    Solution S;
    vector<int> nums = {1,1,1,2,2};
    S.wiggleSort(nums);
    return 0;
}
