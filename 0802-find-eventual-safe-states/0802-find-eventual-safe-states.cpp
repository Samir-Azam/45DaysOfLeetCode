class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // in topo sort we always solve in terms of indegree that is why reverse the graph
        int n = graph.size();
        vector<vector<int>>graphReverse(n);
        for (int i=0;i<n;i++){
            for (auto adj: graph[i]){
                graphReverse[adj].push_back(i);
            }
        }

        vector<int>indegree(n, 0);

        for (int i=0;i<n;i++){
            for (auto adj: graphReverse[i]){
                indegree[adj]++;
            }
        }

        queue<int>q;
        for (int i=0;i<n;i++){
            if (indegree[i]==0){
                q.push(i);
            }
        }

        vector<int>ans;
        while(!q.empty()){
            int ele = q.front();
            q.pop();
            ans.push_back(ele);
            for (auto it: graphReverse[ele]){
                indegree[it]--;
                if (indegree[it]==0) q.push(it);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};