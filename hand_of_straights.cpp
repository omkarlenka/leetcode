//
//  hand_of_straights.cpp
//
//  Created by omlenka on 09/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W)
    {
        if(hand.size() % W)
            return false;
        if(W == 1)
            return true;
        sort(hand.begin(), hand.end());
        vector<pair<int,int>> v;
        int start = -1;
        
        for(int i = 0;i<hand.size();i++)
        {
            if(start == v.size()-1)
            {
                v.push_back(make_pair(hand[i],1));
            }
            else
            {
                int j;
                for(j = start+1;j<v.size();j++)
                {
                    int val = v[j].first;
                    int size = v[j].second;
                    
                    if(hand[i] == val)
                    {
                        continue;
                    }
                    else if(hand[i] == val+1)
                    {
                        val = hand[i];
                        size++;
                        v[j] = make_pair(val,size);
                        if(size == W)
                            start++;
                        break;
                    }
                    else
                    {
                        if(start != v.size()-1)
                            return false;
                    }
                }
                if(j == v.size())
                    v.push_back(make_pair(hand[i],1));
            }
        }
        if(start == v.size()-1)
            return true;
        else
            return false;
    }
};

