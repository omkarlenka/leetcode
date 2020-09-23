//
//  k_concatenation_maximum_sum.cpp
//
//  Created by omlenka on 23/09/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    const int MAX_LIMIT = 1000000007;
    int totalSum(vector<int> &v)
    {
        int sum = 0;
        for(int n:v)
            sum = (sum + n) % MAX_LIMIT;
        
        return sum;
    }
    
    int maxFromStart(vector<int> &v)
    {
        int cur_sum = v[0], max_sum = v[0];
        
        for(int i = 1;i<v.size();i++)
        {
            cur_sum = (cur_sum + v[i]) % MAX_LIMIT;
            max_sum = max(cur_sum, max_sum);
        }
        return max_sum % MAX_LIMIT;
    }
    int maxFromLast(vector<int> &v)
    {
        int len = v.size();
        int cur_sum = v[len-1], max_sum = v[len-1];
        
        for(int i = len-2;i>=0;i--)
        {
            cur_sum = (cur_sum + v[i]) % MAX_LIMIT;
            max_sum = max(cur_sum, max_sum);
        }
        return max_sum % MAX_LIMIT;
    }
    
    long long maxSumSubarray(vector<int> &v)
    {
        long long cur_sum = v[0], max_sum = v[0];
        
        for(int i = 1;i<v.size();i++)
        {
            if((cur_sum + v[i]) % MAX_LIMIT > v[i])
                cur_sum = (cur_sum + v[i]) % MAX_LIMIT;
            else
                cur_sum = v[i];
            
            max_sum = max(cur_sum, max_sum);
        }
        return max_sum % MAX_LIMIT;
    }
    
public:
    int kConcatenationMaxSum(vector<int>& v, int k) {
        
        long long total_sum = totalSum(v);
        int max_from_start = maxFromStart(v);
        int max_from_last = maxFromLast(v);
        
        int total_sum_k = (k*total_sum) % MAX_LIMIT;
        int max_in_one = maxSumSubarray(v);
        if(max_in_one < 0)
            return 0;
        if(k == 1)
            return max_in_one;
        
        int x = (((k-2)*total_sum) % MAX_LIMIT + max_from_start) % MAX_LIMIT;
        int y = max(max_from_start, x);
        int overlap_sum = (max_from_last + y) % MAX_LIMIT;
        return max(max(int(total_sum_k),max_in_one),overlap_sum);
    }
};

int main()
{
//    vector<int> v = {100,2,-20,3,5,-1,-5,20,10000,10000,9999,9909};
    vector<int> v = {1,-2,1};
    int k = 5;
    Solution S;
    cout << S.kConcatenationMaxSum(v, k) << endl;
    return 0;
}
