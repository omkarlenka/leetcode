//
//  main.cpp
//  next_closest_time
//
//  Created by omlenka on 21/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <string>
#include <set>

using namespace std;

char nextGreater(char c, set<char> s)
{
    set<char>::iterator pos = s.find(c);
    if(pos == s.end())
        return char(0);
    else
    {
        pos++;
        if(pos == s.end())
            return char(0);
        return *pos;
    }
}

bool checkMin(string time)
{
    //    time is in HH:MM format
    
    if(time[3] < '6')
        return true;
    else
        return false;
}

bool checkHour(string time)
{
    //    time is in HH:MM format
    
    if(time[0] < '2')
    {
        return true;
    }
    else if(time[0] == '2')
    {
        if(time[1] < '4')
            return true;
    }
    
    return false;
}

string nextClosestTime(string time)
{
    set<char> s;
    s.insert(time[0]);
    s.insert(time[1]);
    s.insert(time[3]);
    s.insert(time[4]);
    
    for(int i = 4;i>=0;i--)
    {
        if(i == 2)
            continue;
        char n = nextGreater(time[i],s);
        if(n == '\0')
        {
            time[i] = *(s.begin());
        }
        else
        {
            bool valid = false;
            time[i] = n;
            
            if(i > 2)
                valid = checkMin(time);
            else
                valid = checkHour(time);
            
            if(valid)
                return time;
            else
                time[i] = *(s.begin());
        }
    }
    return time;
}

int main()
{
    string s = "01:37";
    cout << nextClosestTime(s) << endl;
    return 0;
}
