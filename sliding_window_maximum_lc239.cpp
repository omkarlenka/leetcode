//
//  sliding_window_maximum_lc239.cpp
//
//  Created by omlenka on 18/01/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template<typename T>
class custom_priority_queue : public std::priority_queue<T, std::vector<T>>
{
public:
    
    bool remove(const T& value) {
        auto it = std::find(this->c.begin(), this->c.end(), value);
        if (it != this->c.end()) {
            this->c.erase(it);
//            std::make_heap(this->c.begin(), this->c.end(), this->comp);
            return true;
        }
        else {
            return false;
        }
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int start = 0;
        custom_priority_queue<int> pq;
        for(int i = start;i<k;i++){
            pq.push(nums[i]);
        }
        while(start <= nums.size()-k){
            int top = pq.top();
            res.push_back(top);
            pq.remove(nums[start]);
            pq.push(nums[start+k]);
            start++;
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<int> res =  S.maxSlidingWindow(nums, 3);
    return 0;
}
