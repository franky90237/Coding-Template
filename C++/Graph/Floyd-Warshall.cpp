
/*
dis is the minnumum distance from i to j
  vector<vector<long long>> dis;

T : O(V*V*V), V is the number of vertices
S : O(V*V)
*/
void Floyd()
{
    int n = 26;
    
    for(int k = 0; k < n; ++k)
    {
        dis[k][k] = 0;
        
        for(int i = 0; i < n; ++i)
        {
            if(dis[i][k] >= INF) continue;
            
            for(int j = 0; j < n; ++j)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}
