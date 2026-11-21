class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // it is also very easy first create the graph and then apply dijkstra and count stops also

        // create graph
        vector<vector<pair<int, int>>>adj(n);
        for (int i=0;i<flights.size();i++){
            int from = flights[i][0];
            int to = flights[i][1];
            int price = flights[i][2];
            adj[from].push_back({to, price});
        }
        
        // q will store {stops,{price, city}}
        queue<pair<int, pair<int, int>>>q;
        vector<int>cost(n, 1e5);
        q.push({0, {0, src}});
        cost[src]=0;

        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int stop = top.first;
            int city_price = top.second.first;
            int city = top.second.second;

            for (auto it: adj[city]){
                int price = it.second;
                int to_city = it.first;
                int new_cost = city_price+price;
                if (new_cost<cost[to_city] && stop<=k){
                    q.push({stop+1, {new_cost, to_city}});
                    cost[to_city] = new_cost;
                }
            }
        }
        
        if (cost[dst]==1e5) return -1;
        return cost[dst];
    }
};