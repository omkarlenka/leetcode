//
//  find_k_closest_elements.cpp
//
//  Created by omlenka on 26/01/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto itr = lower_bound(arr.begin(), arr.end(),x);
        int index ;
        if(itr == arr.end()){
            index = arr.size()-1;
        }
        else{
            index = itr-arr.begin();
        }
        vector<int> left;
        vector<int> right;
        int l,r;
        if(arr[index] == x){
            left.push_back(arr[index]);
            k--;
            l = index-1,r = index+1;
        }else{
            l = index-1;
            r = index;
        }
        
        while(k>0){
            if(r == arr.size() || l < 0)
                break;
            
            if(arr[r] - x >= x - arr[l]){
                left.push_back(arr[l]);
                l--;
            }
            else if(arr[r] - x < x - arr[l]){
                right.push_back(arr[r]);
                r++;
            }
            k--;
        }
        
        while(k>0 && l >= 0){
            left.push_back(arr[l]);
            l--;
            k--;
        }
        while(k > 0 && r < arr.size()){
            right.push_back(arr[r]);
            r++;
            k--;
        }
        
        vector<int> res(left.rbegin(),left.rend());
        res.insert(res.end(),right.begin(),right.end());
        return res;
    }
};

int main() {
    Solution S;
    vector<int> v = {0,1,1,1,2,3,6,7,8,9};
    
    vector<int> res = S.findClosestElements(v, 9, 4);
    
    return 0;
}
