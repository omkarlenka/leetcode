//
//  evaluate_division.cpp
//
//  Created by omlenka on 23/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

void printMatrix(vector<vector<double>> &G)
{
    for(int i = 0;i<26;i++)
    {
        for(int j = 0;j<26;j++)
        {
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "---------------------------------------------" << endl;
}

double solveEquation(unordered_map<string,vector<pair<string,double>>> &M, string src, string dst,  unordered_map<string,bool> visited)
{
    if(M.find(src) == M.end() || M.find(dst) == M.end())
        return -1;
    if(src == dst)
        return 1;

    queue<pair<string,double>> Q;
    Q.push(make_pair(src,1));
    visited[src] = true;
    while(!Q.empty())
    {
        pair<string, double> p = Q.front();
        Q.pop();
        string s = p.first;
        double w = p.second;
        unordered_map<string,vector<pair<string,double>>>::iterator itr =  M.find(s);
        vector<pair<string,double>> v = itr->second;
        for(int j = 0;j<v.size();j++)
        {
            if(!visited[v[j].first])
            {
                if(v[j].first == dst)
                    return w * v[j].second;
                else
                {
                    Q.push(make_pair(v[j].first, w*v[j].second));
                    visited[v[j].first] = true;
                }
            }
        }
    }
    return -1;
}

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
{
    unordered_map<string, vector<pair<string,double>>> M;
    
//    printMatrix(G);
    unordered_map<string,bool> visited;
    for(int i = 0;i<equations.size();i++)
    {
        string s1  = equations[i][0];
        string s2 = equations[i][1];
        M[s1].push_back(make_pair(s2, values[i]));
        M[s2].push_back(make_pair(s1, 1/values[i]));
        visited[s1] = false;
        visited[s2]  = false;
    }
    
    vector<double> res(queries.size());
    for(int i = 0;i<queries.size();i++)
    {
        res[i] = solveEquation(M, queries[i][0], queries[i][1], visited);
    }
    return res;
}

int main()
{
    vector<vector<string>> equations = { {"a", "b"}, {"b", "c"} };
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = { {"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"} };
    
//    vector<vector<string>> equations = {{"a","b"},{"b","c"},{"bc","cd"}};
//    vector<double> values = {1.5,2.5,5.0};
//    vector<vector<string>> queries = {{"a","c"},{"c","b"},{"bc","cd"},{"cd","bc"}};
    
//    vector<vector<string>> equations = {{"a","b"}};
//    vector<double> values = {0.5};
//    vector<vector<string>> queries = {{"a","b"},{"b","a"},{"a","c"},{"x","y"}};
    
    vector<double> res = calcEquation(equations, values, queries);
    return 0;
}
