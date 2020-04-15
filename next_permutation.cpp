//
//  next_permutation.cpp
//
//  Created by omlenka on 15/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> v, int s, int e, int val)
{
    if(s>e)
        return -1;
    int m = s+(e-s)/2; // to avoid int overflow
    if(val < v[m])
    {
        if(m == e || v[m+1] < val)
            return m;
        return binarySearch(v, s+1, e, val);
    }
    else if(val > v[m])
    {
        if(m == s || v[m-1] > val)
            return m-1;
        return binarySearch(v, s, e-1, val);
    }
    else
        return m-1;
}

void nextPermutation(vector<int>& v)
{
    int n = int(v.size());
    int i;
    for(i = n-1;i>0;i--)
    {
        if(v[i] > v[i-1])
            break;
    }
    
    if(i > 0)
    {
        int swap_index = binarySearch(v, i, n-1, v[i-1]);
        if(swap_index != -1)
            swap(v[i-1], v[swap_index]);
    }
    reverse(v.begin()+i, v.end());
}

int main()
{
    vector<int> v = {3,1,4,4,2,3,4,0,0};
    nextPermutation(v);
    return 0;
}
