//
//  min_increments_to_form_target.cpp
//
//  Created by omlenka on 10/12/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int res = 0;
        int min = INT_MAX;
        int min_index;
        for(int i = 0;i<target.size();i++){
            if(target[i] < min){
                min = target[i];
                min_index = i;
            }
        }
        
        res += min;
        //Traverse left of min
        int i = min_index - 1;
        int prev = min;
        while(i >= 0){
            if(target[i] > prev){
                res += target[i]-prev;
            }
            prev = target[i];
            i--;
        }
        
        //Traverse right of min
        i = min_index+1;
        prev = min;
        while(i < target.size()){
            if(target[i] > prev){
                res += target[i]-prev;
            }
            prev = target[i];
            i++;
        }
        return res;
    }
};
