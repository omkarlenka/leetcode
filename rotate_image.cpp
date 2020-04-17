//
//  rotate_image.cpp
//
//  Created by omlenka on 18/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void printMatrix(vector<vector<int>>& v)
{
    int n = v.size();
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---------------------------" << endl;
}

void rotate_util(vector<vector<int>>& v, int row, int col, int n)
{
//    printMatrix(v);
    for(int j = 0;j<n-2*col-1;j++)
    {
        //Top to Right
        int src_row =  row;
        int src_col  = col+j;
        int dst_row = src_col;
        int dst_col = n-col-1;
        
        int tmp1 = v[dst_row][dst_col];
        v[dst_row][dst_col] = v[src_row][src_col];
//        printMatrix(v);
        
        //Right to Bottom
        src_row = dst_row;
        src_col = dst_col;
        dst_row = n-row-1;
        dst_col = n-src_row-1;
        
        int tmp2;
        tmp2 = v[dst_row][dst_col];
        v[dst_row][dst_col] = tmp1;
        tmp1 = tmp2;
//        printMatrix(v);
        
        //Bottom to Left
        src_row = dst_row;
        src_col = dst_col;
        dst_row = src_col;
        dst_col = col;
        
        tmp2 = v[dst_row][dst_col];
        v[dst_row][dst_col] = tmp1;
        tmp1 = tmp2;
//        printMatrix(v);
        
        //Left to Top
        src_row = dst_row;
        src_col = dst_col;
        dst_row = row;
        dst_col = n-src_row-1;
        tmp2 = v[dst_row][dst_col];
        v[dst_row][dst_col] = tmp1;
//        printMatrix(v);
    }
//    printMatrix(v);
}

void rotate(vector<vector<int>>& matrix)
{
    int n = matrix.size();
    int row = 0,col = 0;
    for(int i = 0;i<n/2;i++)
    {
        rotate_util(matrix, row, col, n);
        row++;
        col++;
    }
}

int main()
{
    vector<vector<int>> v = {{1,2,3},
                            {4,5,6},
                            {7,8,9}};
    
    rotate(v);
    return 0;
}
