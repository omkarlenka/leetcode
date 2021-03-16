//
//  cheapest_flights_within_k_stops_lc_787.cpp
//
//  Created by omlenka on 16/03/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    int dfs(unordered_map<int,vector<pair<int,int>>> &flight_map, int src, int dst, int K, vector<bool> &visited, int &price_res, int curr_price){
        
        if(src == dst && K >= -1){
            return curr_price;
        }
        
        if(K < 0){
            return INT_MAX;
        }
        
        if(curr_price > price_res){
            return INT_MAX;
        }
        
        if(visited[src]){
            return INT_MAX;
        }
        
        vector<pair<int,int>> dest_cities = flight_map[src];
        
        visited[src] = true;
        int price_local = INT_MAX;
        
        for(auto city:dest_cities){
            int dst_city = city.first;
            int price = city.second;
            
            int price_tmp = dfs(flight_map,dst_city,dst,K-1,visited,price_res,price+curr_price);
            if(price_tmp != INT_MAX){
                price_local = min(price_local,price_tmp);
            }
        }
        price_res = min(price_res, price_local);
        visited[src] = false;
        return price_res;
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        unordered_map<int,vector<pair<int,int>>> flight_map;
        vector<bool> visited(n,false);
        
        for(auto flight:flights){
            int src = flight[0];
            int dst = flight[1];
            int price = flight[2];
            
            if(flight_map.find(src) == flight_map.end()){
                flight_map[src] = vector<pair<int,int>>();
            }
            flight_map[src].push_back(make_pair(dst,price));
        }
        int price_res = INT_MAX;
        dfs(flight_map,src,dst,K,visited,price_res, 0);
        if(price_res == INT_MAX){
            return -1;
        }
        return price_res;
    }
};

int main() {
    Solution S;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{0,2,500}};
    int n = 3;
    int src = 0;
    int dst = 2;
    int k = 1;
    
    cout << S.findCheapestPrice(n, flights, src, dst, k) << endl;
    return 0;
}
