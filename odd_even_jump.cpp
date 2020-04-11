//
//  main.cpp
//  odd_even_jump.cpp
//
//  Created by omlenka on 11/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <tuple>

using namespace std;

class PairComparator
{
public:
    bool operator()(const pair<int,int> &a, const pair<int,int> &b) const
    {
        if(a.first < b.first)
            return true;
        else if(a.first == b.first)
            return a.second < b.second;
        
        return false;
    }
};

tuple<int,int> makeJump(int elem, map<pair<int, int>, pair<bool,bool>, PairComparator> &m, pair<int,int> key)
{
    bool odd = false, even = false;

    map<pair<int, int>, pair<bool,bool>, PairComparator>::iterator mp_itr;
    mp_itr = m.find(key);
    
    //Make Odd Jump
    if(next(mp_itr,1) != m.end())
    {
        pair<int,int> next_key = (next(mp_itr,1))->first;
        if(m[next_key].second)
            odd = true;
        //Try to make even jump here  for duplicate elements
        if(next_key.first == elem)
        {
            if(m[next_key].first)
                even = true;
            
            //delete the rightmost duplicate
            m.erase(next_key);
            
            return (make_tuple(odd,even));
        }
    }
    
    //Make Even Jump
    if(mp_itr != m.begin())
    {
        pair<int,int> prev_key = (prev(mp_itr,1))->first;
        if(m[prev_key].first)
            even = true;
    }
    return (make_tuple(odd,even));
}



int oddEvenJumps(vector<int> &A)
{
    map<pair<int, int>, pair<bool,bool>,PairComparator> m;
    
    int res = 0;
    
    vector<int>::iterator itr;
    for(itr = A.end()-1; itr >= A.begin();itr--)
    {
        int elem = *itr;
        int index = int(itr - A.begin());
        pair<int, int> key = make_pair(elem,  index);
        
        if(itr == A.end()-1)
        {
            m[key] = make_pair(true, true);
            res++;
            continue;
        }
        
        m[key] = make_pair(false, false);
        
        tuple<bool, bool> jumpRes = makeJump(elem, m, key);
        bool odd = get<0>(jumpRes);
        bool even = get<1>(jumpRes);
        
        m[key] = make_pair(odd, even);
        if(odd)
            res++;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0;i<n;i++)
        cin >> v[i];
    
    cout <<  oddEvenJump(v);
    return 0;
}
