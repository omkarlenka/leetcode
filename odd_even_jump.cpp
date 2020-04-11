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

tuple<int,int> makeJump(int elem, multimap<int,int> &m, multimap<int, int>::iterator mp_itr, vector<vector<bool>> v)
{
    bool odd = false, even = false;
    int index = -1;
    
    multimap<int, int>::iterator itr1;
    multimap<int, int>::iterator itr2;
    //Make Odd Jump
    if(mp_itr != m.begin() && (prev(mp_itr)->first == elem))  //duplicate elemenet getting inserted again
    {
        itr1 = m.lower_bound(elem);
        index = itr1->second;
    }
    else if(next(mp_itr,1) != m.end())
    {
        int next_elem  = (next(mp_itr,1))->first;
        itr1 = m.lower_bound(next_elem);
        itr2 = m.upper_bound(next_elem);
        if(itr1->first == itr2->first)    //got a upper bound of the key
            index = itr2->second;
        else
            index = itr1->second;
    }
    if(v[index][1])
        odd = true;
    
    //Make Even Jump
    if(mp_itr != m.begin())
    {
        int index = (prev(mp_itr,1))->second;
        if(v[index][0])
            even = true;
    }
    return (make_tuple(odd,even));
}

int oddEvenJump(vector<int> &A)
{
    multimap<int, int> m;
    multimap<int, int>::iterator mp_itr;
    vector<vector<bool>> v(A.size());
    int res = 0;
    
    for(int i =0;i<A.size();i++)
    {
        vector<bool> tmp(2,false);
        v[i] = tmp;
    }
    
    vector<int>::iterator itr;
    for(itr = A.end()-1; itr >= A.begin();itr--)
    {
        int elem = *itr;
        int index = int(itr - A.begin());
        mp_itr = m.insert({elem, index});
        
        if(itr == A.end()-1)
        {
            v[index][0] = true;
            v[index][1] = true;
            res++;
            continue;
        }
        
        tuple<bool, bool> jumpRes = makeJump(elem, m, mp_itr, v);
        bool odd = get<0>(jumpRes);
        bool even = get<1>(jumpRes);
        
        v[index][0] = odd;
        v[index][1] = even;
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
