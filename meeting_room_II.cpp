//
//  meeting_room_II.cpp
//
//  Created by omlenka on 21/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class StartTimeCompare
{
public:
    bool operator()(const vector<int> &v1, const vector<int> &v2) const
    {
        if(v1[0] < v2[0])
            return true;
        else if(v1[0] == v2[0])
        {
            return (v1[1] < v2[1]);
        }
        return false;
    }
};


void allocateMeeting(set<vector<int>> &S, int p)
{
    if(S.size() == 0)
        return;
    vector<int> v = {p,INT_MIN};
    set<vector<int>>:: iterator itr =  lower_bound(S.begin(), S.end(), v);
    
    if(itr != S.end())
    {
        v = *itr;
        p = (*itr)[1];
        S.erase(itr);
        allocateMeeting(S,p);
    }
}

int minMeetingRooms(vector<vector<int>>& v)
{
    int m = int(v.size());
    if(m <= 1)
        return m;
    set<vector<int>> S;
    sort(v.begin(),v.end(),StartTimeCompare());
    for(int i = 0;i<m;i++)
    {
        S.insert(v[i]);
    }
    
    int res = int(v.size()-S.size());  //handled duplicates
    set<vector<int>>::iterator itr = S.begin();
    while(!S.empty())
    {
        itr = S.begin();
        res++;
        int p = (*itr)[1];
        S.erase(itr);
        allocateMeeting(S,p);
    }
    return res;
}

int main()
{
    vector<vector<int>> v = {{765,989},{466,472},{860,996},{338,932},{618,639},{616,936},{832,864},{92,758}};
    cout << minMeetingRooms(v);
    return 0;
}
