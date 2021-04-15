//
//  max_chunks_to_make_sorted_lc769.cpp
//
//  Created by omlenka on 15/04/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int left = 0, right = 0;
        int res = 0;
        while(right < arr.size()){
            if(arr[left] == left){
                res++;
                left++;
                right++;
            }
            else{
                if(right == left){
                    right = arr[left];
                }
                int n = right-left+1;
                int expected_sum = n*(left+right)/2;
                int curr_sum = 0;
                for(int i = left;i<=right;i++){
                    curr_sum += arr[i];
                }
                if(expected_sum == curr_sum){
                    res++;
                    right++;
                    left = right;
                    
                }
                else{
                    right++;
                }
            }
        }
        return res;
    }
};

// 1,2,0,3,4

// 0,1,2,3,4


// 3,1,0,4,2,5

// 0,1,2,3,4,5

int main() {
    Solution S;
    vector<int> arr = {3,1,0,4,2,5};
    cout << S.maxChunksToSorted(arr) << endl;
    return 0;
}
