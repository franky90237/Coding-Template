/*

S : O(n)
query
  T : O(logn)
  S : O(1)
update
  T : O(logn)
  S : O(1)
  
*/
class FenickTree
{
private:
    vector<long long> nodes;

    int lowbit(int i)
    {
        return i & (-i); 
    }
    
public:
    FenickTree() = default;
    
    FenickTree(int n) : nodes(n, 0)
    {
        
    }
    
    ~FenickTree() = default;        
    
    void update(int i, long long val)
    {
        int n = nodes.size();
        while(i < n)
        {
            nodes[i] += val;
            i += lowbit(i);
        }
    }
    
    long long query(int i)
    {
        long long res = 0;
        while(i > 0)
        {
            res += nodes[i];
            i -= lowbit(i);
        }
        
        return res;
    }        
};
