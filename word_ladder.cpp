//
//  word_ladder.cpp
//
//  Created by omlenka on 13/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

bool addEdges(string s, string d, unordered_set<string> &us, vector<bool> &visited, vector<string> &edges)
{
    string new_s;
    unordered_set<string>::iterator itr;
    for(int i = 0 ;i<s.length();i++)
    {
        for(char c = 'a';c<='z';c++)
        {
            if(c == s[i])
                continue;
            new_s = s.substr(0,i) + c + s.substr(i+1, s.length());
            itr = us.find(new_s);
            if(itr != us.end())
            {
                int index = distance(us.begin(), us.find(new_s));
                if(!visited[index])
                {
                    if(new_s == d)
                        return true;
                    edges.push_back(new_s);
                    visited[index] = true;
                }
            }
        }
    }
    return false;
}

int wordsBFS(string s, string d, unordered_set<string> us)
{
    queue<pair<string,int>> Q;
    vector<bool> visited(us.size(), false);
    int index = distance(us.begin(), us.find(s));
    
    Q.push(make_pair(s,1));
    visited[index] = true;
    
    string v;
    int dist;
    while(!Q.empty())
    {
        pair<string,int> p = Q.front();
        Q.pop();
        v = p.first;
        dist = p.second;
        //add Edge
        vector<string> edges;
        bool found = addEdges(v, d, us, visited, edges);
        if(found)
            return dist+1;
        
        for(int i = 0; i<edges.size();i++)
        {
            Q.push(make_pair(edges[i], dist+1));
            
        }
    }
    
    return 0;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
    unordered_set<string> us;
    for(int i = 0;i<wordList.size();i++)
        us.insert(wordList[i]);
    if(us.find(endWord) == us.end())
        return 0;
    if(us.find(beginWord) == us.end())
        us.insert(beginWord);
               
    return wordsBFS(beginWord, endWord, us);
    
}

int main()
{
    int n;
    cin >> n;
    string bw, ew;
    vector<string> v(n);
    cin >> bw >> ew;

    for(int i = 0;i<n;i++)
        cin >> v[i];

    cout << ladderLength(bw, ew, v) << endl;

    return 0;
}
