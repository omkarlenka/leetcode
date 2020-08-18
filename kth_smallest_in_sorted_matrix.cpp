//
//  kth_smallest_in_sorted_matrix.cpp
//
//  Created by omlenka on 17/08/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        int res = matrix[0][0];
        
        if(k == 1)
            return res;
        
        pair<int,int> down = make_pair(1,0);
        pair<int,int> right = make_pair(0,1);
        k--;
        
        while(k--)
        {
            if(down.first != -1 && right.first != -1)
            {
                if(matrix[down.first][down.second] < matrix[right.first][right.second])
                {
                    res = matrix[down.first][down.second];
                    if(down.first == row-1)
                    {
                        if(right.second - down.second > 1)
                            down = make_pair(down.first, down.second+1);
                        else
                            down = make_pair(-1,-1);
                    }
                    else
                    {
                        down = make_pair(down.first+1, down.second);
                    }
                }
                else
                {
                    res = matrix[right.first][right.second];
                    if(right.second == col-1)
                    {
                        if(down.first - right.first > 1)
                            right = make_pair(right.first+1, right.second);
                        else
                            right = make_pair(-1,-1);
                    }
                    else
                    {
                        right = make_pair(right.first, right.second+1);
                    }
                }
            }
            else if(down.first == -1)
            {
                res = matrix[right.first][right.second];
                if(right.first < row-1)
                    down = make_pair(right.first+1,right.second);
                if(right.second < col-1)
                    right = make_pair(right.first, right.second+1);
                else
                    right = make_pair(-1,-1);
                
            }
            else
            {
                res = matrix[down.first][down.second];
                if(down.second < col-1)
                    right = make_pair(down.first, down.second+1);
                if(down.first < row-1)
                    down = make_pair(down.first+1, down.second);
                else
                    down = make_pair(-1,-1);
            }
        }
        return res;
    }
};

int main()
{
    Solution S;
    vector<vector<int>> matrix = {{1,5,9},{10,11,13},{12,13,15}};
    cout << S.kthSmallest(matrix, 3) << endl;
    return 0;
}
