//
//  replace_elements_with_greatest_on_right_lc1299.cpp
//
//  Created by omlenka on 07/04/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        unordered_map<int,int> UM;
        int max = INT_MIN;
        for(int i = arr.size()-1;i>=0;i--){
            if(arr[i] > max){
                max = arr[i];
            }
            UM[i] = max;
        }
        
        for(int i = 0;i<arr.size()-1;i++){
            arr[i] = UM[i+1];
        }
        arr[arr.size()-1] = -1;
        return arr;
    }
};

