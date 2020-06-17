//
//  mock_fruit_into_basket.cpp
//
//  Created by omlenka on 17/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& tree)
    {
        int b1=-1,b2=-1, total = 0;
        int b1_count = 0, b2_count = 0;
        int res = 0;
        for(int i = 0;i<tree.size();i++)
        {
            int t = tree[i];
            if(b1 == -1 || t == b1)
            {
                b1 = t;
                if(i-1>= 0 && b1== tree[i-1])
                    b1_count++;
                else
                    b1_count = 1;
                total++;
            }
            else if(b2 == -1 || t == b2)
            {
                b2 = t;
                if(i-1>= 0 && b2== tree[i-1])
                    b2_count++;
                else
                    b2_count = 1;
                total++;
            }
            else
            {
                if(tree[i-1] == b1)
                {
                    b2 = t;
                    b2_count = 1;
                    
                }
                else if(tree[i-1] == b2)
                {
                    b1 = t;
                    b1_count = 1;
                }
                total = b1_count + b2_count;
            }
            
            if(total > res)
                res = total;
        }
        return res;
    }
};
