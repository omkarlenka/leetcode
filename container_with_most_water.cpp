//
//  container_with_most_water.cpp
//
//  Created by omlenka on 13/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height)
{
    int left = 0,right = height.size()-1;
    int tmp_left = left, tmp_right = right;
    int area = 0, max_area = 0;
    
    while(left < right && tmp_left <tmp_right)
    {
        if(height[tmp_left] < height[left])
        {
            tmp_left++;
            continue;
        }
        if(height[tmp_right] < height[right])
        {
            tmp_right--;
            continue;
        }
        
        left = tmp_left;
        right = tmp_right;
        
        area = min(height[left],height[right]) * (right-left);
        if(area > max_area)
            max_area = area;
        
        if(height[left] < height[right])
            tmp_left++;
        else
            tmp_right--;
    }
    return max_area;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0;i<n;i++)
        cin >> v[i];
    cout << maxArea(v);
    return 0;
}
