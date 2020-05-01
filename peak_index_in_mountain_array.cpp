//
//  peak_index_in_mountain_array.cpp
//
//  Created by omlenka on 01/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int binSearch(vector<int> &A, int s, int e)
    {
        if(s > e)
            return -1;
        int m = (s+e)/2;
        if(m-1 >= 0 && A[m] > A[m-1] && m+1<=A.size() && A[m] > A[m+1])
            return m;
        else if(m-1>=0 && A[m] > A[m-1])
            return binSearch(A, m+1, e);
        else if(m+1 <= A.size() && A[m] > A[m+1])
            return binSearch(A, s,m-1);
        
        return -1;
    }
    int peakIndexInMountainArray(vector<int>& A)
    {
        return binSearch(A, 0, A.size()-1);
    }
};
