//
//  count_items_matching_a_rule_lc1773.cpp
//
//  Created by omlenka on 11/03/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int res = 0;
        for(auto item:items){
            if(ruleKey == "type" && ruleValue == item[0])
                res++;
            else if(ruleKey == "color" && ruleValue == item[1])
                res++;
            else if(ruleKey == "name" && ruleValue == item[2])
                res++;
        }
        
        return res;
    }
};
