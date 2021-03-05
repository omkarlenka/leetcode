//
//  last_stone_weight_lc1046.cpp
//
//  Created by omlenka on 05/03/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>> pq;
        for(int n: stones){
            pq.push(n);
        }
        int res = 0;;
        
        while(!pq.empty()){
            int top1 = pq.top();
            pq.pop();
            
            int top2;
            if(!pq.empty()){
                top2 = pq.top();
                pq.pop();
            }
            else{
                res = top1;
                break;
            }
            
            if(top1 != top2){
                pq.push(abs(top1-top2));
            }
        }
        return res;
    }
};
