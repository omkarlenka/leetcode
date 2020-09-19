//
//  maximum_subarray_sum_with_one_deletion.cpp
//
//  Created by omlenka on 19/09/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& arr)
    {
        size_t n = arr.size();
        vector<vector<int>> DP(n,vector<int>(2,INT_MIN));
        int max_sum = arr[0];
        
        DP[0][0] = arr[0]; //sum w/o drop
        DP[0][1] = arr[0]; //sum with drop
        
        for(int i = 1;i<n;i++)
        {
            //Update DP[i][0]
            if(DP[i-1][0] + arr[i] <= arr[i])
            {
                DP[i][0] = arr[i];
            }
            else
            {
                DP[i][0] = DP[i-1][0] + arr[i];
            }
            
            //Update DP[i][1]
            int sum1 = DP[i-1][0]; //Drop this element
            int sum2 = DP[i-1][1] + arr[i]; //Do not drop this element
            
            DP[i][1] = max(sum1,sum2);
            
            if(DP[i][0] > max_sum)
                max_sum = DP[i][0];
            if(DP[i][1] > max_sum)
                max_sum = DP[i][1];
        }
        return max_sum;
    }
};

int main()
{
    Solution S;
    vector<int> v = {-1,-1,-1,-1};
    cout << S.maximumSum(v) << endl;
    return 0;
}
