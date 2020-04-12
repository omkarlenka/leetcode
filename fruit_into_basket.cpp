//
//  fruit_into_basket.cpp
//
//  Created by omlenka on 12/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int totalFruit(vector<int>& tree)
{
    int max_fruits = 1;
    int same_res = 1, diff_val  = -1, diff_res = 1;
    
    for(int i = tree.size()-2;i>=0;i--)
    {
        if(tree[i] != tree[i+1] && tree[i] != diff_val)
        {
            diff_res = same_res+1;
            diff_val = tree[i+1];
            same_res = 1;
        }
        else if(tree[i] == diff_val)
        {
            same_res = 1;
            diff_val  = tree[i+1];
            diff_res += 1;
        }
        else //tree[i] == tree[i+1];
        {
            same_res += 1;
            diff_res += 1;
        }
        
        if(same_res > max_fruits)
            max_fruits = same_res;
        if(diff_res > max_fruits)
            max_fruits = diff_res;
    }
    
    return max_fruits;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0;i<n;i++)
        cin >>  v[i];
    
    cout << totalFruit(v);
    
    return 0;
}
