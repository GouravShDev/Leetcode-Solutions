class Solution
{
    public:
        bool dfs(vector<int> graph[], int node, vector<int> &visited, int lcolor)
        {
            visited[node] = lcolor;
            for (auto &adj: graph[node])
            {
                if (!visited[adj])
                {
                    if (!dfs(graph, adj, visited, lcolor == 2 ? 1 : 2))
                    {
                        return false;
                    }
                }
                else if (visited[adj] == lcolor)
                {
                    return false;
                }
            }
            return true;
        }
    bool possibleBipartition(int n, vector<vector < int>> &dislikes)
    {
        vector<int> visited(n);
        vector<int> graph[n];
        for (auto &dislike: dislikes)
        {
            int u = dislike[0];
            int v = dislike[1];
            graph[u - 1].push_back(v - 1);
            graph[v - 1].push_back(u - 1);
        }
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if (!dfs(graph, i, visited, 1)) return false;
            }
        }
        return true;
    }
};