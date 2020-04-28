//
//  coin_change.cpp
//
//  Created by omlenka on 28/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int getLesserCoins(vector<int> &coins, int c)
{
    return lower_bound(coins.begin(), coins.end(), c)-coins.begin()-1;
}

int coinChange_Util(vector<int> &coins, int amount, vector<int> &v)
{
    if(amount <= 0)
        return 0;
    if(v[amount] == -1 || v[amount] != 0)
        return v[amount];
    
    int c_index = getLesserCoins(coins, amount);
    v[amount]  = -1;
    while(c_index >=0)
    {
        int res = 0;
        int coin_value = coins[c_index];
        if(v[coin_value] != -1)
        {
            res = 1;
            int res1 = coinChange_Util(coins, amount-coin_value, v);
            if(res1 != -1)
            {
                res += res1;
                if(v[amount] == -1 || res < v[amount])
                    v[amount] = res;
            }
        }
        c_index--;
    }
    return v[amount];
}
int coinChange(vector<int>& coins, int amount)
{
    if(coins.size() == 0 || amount == 0)
        return 0;
    
    sort(coins.begin(),coins.end());
    
    vector<int> v(amount+1, 0);
    for(int c:coins)
    {
        if(c < v.size())
            v[c] = 1;
    }
    
    return coinChange_Util(coins, amount, v);
}

int main()
{
    vector<int> v= {186,419,83,408};
    cout << coinChange(v, 6249);
    
//    vector<int> v= {2};
//    cout << coinChange(v, 1);
    return 0;
}
