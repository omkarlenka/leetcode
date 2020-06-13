//
//  flood_fill.cpp
//
//  Created by omlenka on 12/06/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    void floodFillUtil(vector<vector<int>> &image, int r, int c, int sr, int sc, int newColor)
    {
        if(image[sr][sc] == -1)
            return;
        
        int color = image[sr][sc];
        image[sr][sc] = -1;
        if(sr-1 >= 0 && image[sr-1][sc] == color)
            floodFillUtil(image,r,c,sr-1,sc,newColor);
        
        if(sr+1 < r && image[sr+1][sc] == color)
            floodFillUtil(image,r,c,sr+1,sc,newColor);
        
        if(sc+1 < c && image[sr][sc+1] == color)
            floodFillUtil(image,r,c,sr,sc+1,newColor);
        
        if(sc-1 >= 0 && image[sr][sc-1] == color)
            floodFillUtil(image,r,c,sr,sc-1,newColor);
        
        image[sr][sc] = newColor;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        int r = image.size();
        int c = image[0].size();
        
        floodFillUtil(image,r,c,sr,sc,newColor);
        return image;
    }
};
