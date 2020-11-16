//
//  binary_watch.cpp
//
//  Created by omlenka on 16/11/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>

using namespace std;

class Solution {
    vector<int> getHour(int num_bits, int start){
        vector<int> res;
        if(num_bits == 0){
            res.push_back(0);
            return res;
        }
        for(int i = start;i<4;i++){
            int h = pow(2,4-i-1);
            vector<int> h_recur = getHour(num_bits-1,i+1);
            for(int hour:h_recur){
                if(h + hour < 12)
                    res.push_back(h + hour);
            }
        }
        return res;
    }
    
    vector<int> getMinute(int num_bits, int start){
        vector<int> res;
        if(num_bits == 0){
            res.push_back(0);
            return res;
        }
        
        for(int i = start;i<6;i++){
            int m = pow(2,6-i-1);
            vector<int> m_recur = getMinute(num_bits-1,i+1);
            for(int minute:m_recur){
                if(m + minute < 60)
                    res.push_back(m + minute);
            }
        }
        return res;
    }
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        int h = 0;
        int limit = min(3, num);
        while (h <= limit){
            vector<int> hours = getHour(h,0);
            vector<int> mins = getMinute(num-h,0);
            
            for(int hour:hours){
                for(int min:mins){
                    string hour_res = to_string(hour);
                    string min_res;
                    if(min < 10)
                        min_res = "0" + to_string(min);
                    else
                        min_res = to_string(min);
                    res.push_back(hour_res + ":" + min_res);
                }
            }
            h++;
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<string> res = S.readBinaryWatch(2);
    
    return 0;
}
