//
//  range_sum_query_mutable_2D.cpp
//
//  Created by omlenka on 14/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
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
    SegmentTree(vector<int>& nums)
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

class NumMatrix {
    vector<SegmentTree*> st;
    // vector<vector<int>> matrix;
public:
    NumMatrix(vector<vector<int>>& matrix)
    {
        // this->matrix = matrix;
        int r = matrix.size();
        if(r == 0)
            return;
        int c = matrix[0].size();
        if(c == 0)
            return;
        st.resize(r);
        
        for(int i = 0;i<r;i++)
        {
            st[i] = new SegmentTree(matrix[i]);
        }
    }
    
    void update(int row, int col, int val)
    {
        st[row]->update(col, val);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int res = 0;
        for(int i = row1;i<=row2;i++)
        {
            res += st[i]->sumRange(col1, col2);
        }
        
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
