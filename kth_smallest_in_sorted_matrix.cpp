//
//  kth_smallest_in_sorted_matrix.cpp
//
//  Created by omlenka on 17/08/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Element
{
    int val,row,col;
public:
    Element(int val, int row, int col)
    {
        this->val = val;
        this->row = row;
        this->col = col;
    }
    int getVal(){return val;}
    int getRow(){return row;}
    int getCol(){return col;}
};
class Compare
{
public:
    bool operator()(Element *a, Element *b)
    {
        return a->getVal() > b->getVal();
    }
};

class Solution {
    
public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        size_t n = matrix.size();
        vector<Element*> v(n);
        
        for(int j = 0;j<n;j++)
        {
            v[j] = new Element(matrix[0][j], 0, j);
        }
        
        priority_queue<Element*, vector<Element*>, Compare> Q;
        for(int i = 0;i<n;i++)
        {
            Q.push(v[i]);
        }
        
        while(k>1)
        {
            Element* min_elem = Q.top();
            Q.pop();
            
            int row = min_elem->getRow();
            int col = min_elem->getCol();
            if(row+1 < n)
            {
                Q.push(new Element(matrix[row+1][col],row+1,col));
            }
            else
            {
                Q.push(new Element(INT_MAX,-1,-1));
            }
            k--;
        }
        return Q.top()->getVal();
    }
};
int main()
{
    Solution S;
    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    cout << S.kthSmallest(matrix, 7) << endl;
    return 0;
}
