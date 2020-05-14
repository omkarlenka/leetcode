//
//  split_array_argest_sum.cpp
//
//  Created by omlenka on 14/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class NumArray {
    vector<int> st;
    int n;
    vector<int> nums;
    int buildSegmentTree(vector<int> &nums, int root, int s, int e)
    {
        int sum = 0;
        if(s != e)
        {
            int mid = s+(e-s)/2;
            sum += buildSegmentTree(nums, 2*root+1, s, mid);
            sum += buildSegmentTree(nums, 2*root+2, mid+1, e);
            
            st[root] = sum;
        }
        else
        {
            st[root] = nums[s];
        }
        return st[root];
    }
    
    int sumRangeUtil(int curr, int l, int r, int ql, int qr)
    {
        if(l > r)
            return 0;
        
        //complete overlap
        if(ql <= l && qr >= r)
            return st[curr];
        
        //no overlap
        if(ql > r || qr < l)
            return 0;
        
        //partial overlap
        int mid = l+(r-l)/2;
        int left_sum = sumRangeUtil(2*curr+1, l, mid, ql, qr);
        int right_sum = sumRangeUtil(2*curr+2, mid+1, r, ql, qr);
        
        return left_sum + right_sum;
    }
    
    void updateUtil(int curr, int l, int r, int ui, int delta)
    {
        if(l > r)
            return;
        
        if(ui >= l && ui <= r)
        {
            st[curr] += delta;
            if(l != r)
            {
                int mid = l+(r-l)/2;
                if(ui <= mid)
                    updateUtil(2*curr+1, l, mid,ui, delta);
                else
                    updateUtil(2*curr+2, mid+1, r, ui, delta);
            }
        }
    }
    
public:
    NumArray(vector<int>& nums)
    {
        if(nums.empty())
            return;
        this->nums = nums;
        n = nums.size();
        double p = double(log2(n));
        int x = ceil(p);
        st.resize(2*pow(2,double(x))-1);
        buildSegmentTree(nums, 0, 0, n-1);
    }
    
    void update(int i, int val)
    {
        updateUtil(0, 0, n-1, i, val - nums[i]);
        nums[i] = val;
    }
    
    int sumRange(int i, int j)
    {
        int lo = 0;
        int hi = n-1;
        int curr = 0;
        return sumRangeUtil(curr,lo,hi,i,j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */

// ["NumArray","sumRange","sumRange","sumRange","update","update","update","sumRange","update","sumRange","update"]
// [[[0,9,5,7,3]],[4,4],[2,4],[3,3],[4,5],[1,7],[0,8],[1,2],[1,9],[4,4],[3,4]]
