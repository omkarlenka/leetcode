//
//  minimum_knight_moves.cpp
//
//  Created by omlenka on 08/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
class pair_hash {
public:
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};
class Solution {
public:
    int minKnightMoves(int X, int Y)
    {
        queue<vector<int>> Q;  //x,y,d
        
        unordered_set<pair<int,int>, pair_hash> visited;
        
        Q.push(vector<int> {0,0,0});
        visited.insert(make_pair(0,0));
        
        while(!Q.empty())
        {
            vector<int> v = Q.front();
            Q.pop();
            int x = v[0],  y = v[1];
            
            if(x == X && y == Y)
                return v[2];
            
            if((x-1 == X && y-2 == Y) || (x-2 == X && y-1 == Y) || (x-1 == X && y+2 == Y) || (x-2 == X && y+1 == Y) || (x+1 == X && y-2 == Y) || (x+2 == X && y-1 == Y) || (x+1 == X && y+2 == Y) || (x+2 == X && y+1 == Y))
                return v[2]+1;
            if((x+2 == X && y == Y) || (x+1 == X && y+1 == Y) || (x+1 == X && y-1 == Y) || (x == X && y+2 == Y) || (x == X && y-2 == Y) || (x-1 == X  && y-1 == Y) || (x-1 == X && y+1 == Y) || (x-2 == X && y== Y))
                return v[2]+2;
            // if((x == X && y+1 == Y) || (x == X && y-1 == Y) || (x+1 == X && y == Y) || (x-1 == X && y == Y))
            //     return v[2]+3;
            
            if(X < x)
            {
                if(Y < y)
                {
                    if(visited.find(make_pair(x-1,y-2))  == visited.end())
                    {
                        Q.push(vector<int> {x-1,y-2,v[2]+1});
                        visited.insert(make_pair(x-1,y-2));
                    }
                    if(visited.find(make_pair(x-2,y-1))  == visited.end())
                    {
                        Q.push(vector<int> {x-2,y-1,v[2]+1});
                        visited.insert(make_pair(x-2,y-1));
                    }
                }
                else
                {
                    if(visited.find(make_pair(x-1,y+2))  == visited.end())
                    {
                        Q.push(vector<int> {x-1,y+2,v[2]+1});
                        visited.insert(make_pair(x-1,y+2));
                    }
                    if(visited.find(make_pair(x-2,y+1))  == visited.end())
                    {
                        Q.push(vector<int> {x-2,y+1,v[2]+1});
                        visited.insert(make_pair(x-2,y+1));
                    }
                }
            }
            else
            {
                if(Y < y)
                {
                    if(visited.find(make_pair(x+1,y-2))  == visited.end())
                    {
                        Q.push(vector<int> {x+1,y-2,v[2]+1});
                        visited.insert(make_pair(x+1,y-2));
                    }
                    if(visited.find(make_pair(x+2,y-1))  == visited.end())
                    {
                        Q.push(vector<int> {x+2,y-1,v[2]+1});
                        visited.insert(make_pair(x+2,y-1));
                    }
                }
                else
                {
                    if(visited.find(make_pair(x+1,y+2))  == visited.end())
                    {
                        Q.push(vector<int> {x+1,y+2,v[2]+1});
                        visited.insert(make_pair(x+1,y+2));
                    }
                    if(visited.find(make_pair(x+2,y+1))  == visited.end())
                    {
                        Q.push(vector<int> {x+2,y+1,v[2]+1});
                        visited.insert(make_pair(x+2,y+1));
                    }
                }
            }
            
        }
        
        return -1;
    }
};
