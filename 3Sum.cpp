//
//  3Sum.cpp
//
//  Created by omlenka on 14/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <tuple>

using namespace std;

class Triplet
{
public:
    int a,b,c;
    Triplet(int a, int b, int c)
    {
        this->a = min(min(a,b),c);
        this->c = max(max(a,b),c);
        this->b = (a+b+c) - (this->a + this->c);
            
    }
};
bool operator==(const Triplet& lhs, const Triplet& rhs)
{
    
    if(lhs.a == rhs.a && lhs.b == rhs.b && lhs.c == rhs.c)
        return true;
    return false;
}

struct MyHash
{
    std::size_t operator()(Triplet const& s) const noexcept
    {
        std::size_t h1 = std::hash<int>{}(s.a);
        std::size_t h2 = std::hash<int>{}(s.b);
        std::size_t h3 = std::hash<int>{}(s.c);
        return h1 ^ (h2 << 1) ^ h3;
    }
};

vector<vector<int>> threeSum(vector<int>& nums)
{
    vector<vector<int>> res;
    unordered_set<Triplet, MyHash> us;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size()-2;i++)
    {
        int left = i+1, right = int(nums.size()-1);

        while(left < right)
        {
            if(left == i)
            {
                left++;
                continue;
            }
            if(right == i)
            {
                right--;
                continue;
            }
            
            if(nums[i] + nums[left] + nums[right] == 0)
            {
                Triplet t = {nums[i], nums[left], nums[right]};
                us.insert(t);
                left++;
                right--;
            }
            else if(nums[i] + nums[left] + nums[right] < 0)
                left++;
            else
                right--;
        }
    }
    unordered_set<Triplet, MyHash>::iterator itr;
    for(itr = us.begin();itr != us.end();itr++)
    {
        vector<int> tmp;
        tmp.push_back(itr->a);
        tmp.push_back(itr->b);
        tmp.push_back(itr->c);
        res.push_back(tmp);
    }
    return res;
}

int main()
{
    vector<int> v = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = threeSum(v);
    return 0;
}
