//
//  lemonade_change.cpp
//
//  Created by omlenka on 13/09/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills)
    {
        int five = 0, ten = 0, twenty = 0;
        
        for(int b:bills)
        {
            int ret = b-5;
            
            if(ret == 5)
            {
                if(five)
                {
                    five--;
                    ret = 0;
                }
            }
            else if(ret == 15)
            {
                if(ten)
                {
                    ten--;
                    ret -= 10;
                }
                if(five >= (ret/5))
                {
                    five -= (ret/5);
                    ret = 0;
                }
            }
            if(ret)
                return false;
            
            if(b == 5)
                five++;
            else if(b == 10)
                ten++;
            else
                twenty++;
        }
        return true;
    }
};

int main()
{
    Solution S;
    vector<int> bills = {5,5,10,20,5,5,5,5,5,5,5,5,5,10,5,5,20,5,20,5};
    cout << S.lemonadeChange(bills) << endl;
    return 0;
}
