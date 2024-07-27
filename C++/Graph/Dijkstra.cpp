
/*
g is a graph
  1. vector<vector<vector<int>>> g;
  2. vector<vector<pair<int, int>> g;
  3. vector<unordered_map<int, int>> g;

using min-heap
T : O(Elog(E)), E is the number of edges
S : O(V), V is the number of vertices
*/
long long Dijkstra(int begin, int end)
{
    int n = 26;
    vector<long long> dis(n, LLONG_MAX / 2);
    dis[begin] = 0;
    
    priority_queue< pair<long long, int>, 
                    vector<pair<long long, int>>, 
                    greater<pair<long long, int>> > q;
    q.push({0, begin});        
    
    while(!q.empty())
    {
        auto [curCost, cur] = q.top();
        q.pop();
        
        //cout<<cur<<" "<<curCost<<endl;
        
        if(cur == end) return curCost;            
        if(curCost > dis[cur]) continue;
                    
        for(auto& [next, cost] : g[cur])
        {
            if(curCost + cost < dis[next])
            {
                dis[next] = curCost + cost;
                q.push({dis[next], next});
            }
        }
    }
            
    return -1LL;
}
