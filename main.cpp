//
//  median_of_two_sorted_arrays.cpp
//
//  Created by omlenka on 04/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    if(nums1.size() == 1 && nums2.size() == 1)
        return (double(nums1[0])+double(nums2[0]))/2;
    vector<int> smaller;
    vector<int> larger;
    if(nums1.size() > nums2.size())
    {
        larger = nums1;
        smaller = nums2;
    }
    else
    {
        larger = nums2;
        smaller = nums1;
    }
    if(smaller.size() == 0)
    {
        if(larger.size() %2)//odd
            return larger[larger.size()/2];
        else
        {
            double a = double(larger[larger.size()/2-1]);
            double b = double(larger[larger.size()/2]);
            return (a+b)/2;
        }
    }
    
    int start = 0;
    int end = smaller.size()-1;
    int total_elem = smaller.size() + larger.size();
    
    while(true)
    {
        int x1,x2,y1,y2;
        int p1,p2;
        
        if(end < 0)
        {
            x1 = INT_MIN;
            x2 = smaller[0];
            p2 = (total_elem + 1)/2 - 1;
            y1 = larger[p2];
            if(p2 < larger.size()-1)
                y2 = larger[p2+1];
            else
                y2 = INT_MAX;
        }
        else if(start == smaller.size()-1)
        {
            if(smaller.size() == larger.size())
            {
                x1 = smaller[smaller.size()-1];
                x2 = INT_MAX;
                y1 = INT_MIN;
                y2 = larger[0];
            }
            else
            {
                
                x1 = smaller[smaller.size()-1];
                x2 = INT_MAX;
                y1 = larger[(total_elem + 1)/2 - smaller.size() - 1];
                y2 = larger[(total_elem + 1)/2 - smaller.size()];
            }
        }
        else
        {
            p1 = (start+end)/2;
            p2 = (total_elem +  1)/2 -p1-2;
            
            
            
            x1 = smaller[p1];
            x2 = smaller[p1+1];
            
            y1 = larger[p2];
            if(p2 < larger.size()-1)
                y2 = larger[p2+1];
            else
                y2 = INT_MAX;
        }
        
        if(x1 <= y2 && y1 <= x2)
        {
            if(total_elem % 2) //odd
            {
                return  max(x1,y1);
            }
            else  //even
            {
                double a = max(x1,y1);
                double b = min(x2, y2);
                
                return (a+b)/2;
            }
        }
        else if(x1 > y2)
        {
            end -= 1;
        }
        else if(y1 > x2)
        {
            start += 1;
        }
    }
}

int main()
{
    vector<int> a = {3};
    vector<int> b = {1,2,4};
	cout << findMedianSortedArrays(a,b);
    return 0;
}
