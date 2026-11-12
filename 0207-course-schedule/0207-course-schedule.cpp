class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // simple logic is that you can only finish courses if they don't have cycles

        // create adjacency list first
        vector<vector<int>>adj(numCourses);

        for (int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            adj[v].push_back(u);
        }

        // try to find a cycle using toposort
        vector<int>inDegree(numCourses, 0);
        for (int i=0;i<numCourses;i++){
            for (auto it: adj[i]){
                inDegree[it]++;
            }
        }

        queue<int>q;
        for (int i=0;i<numCourses;i++){
            if (inDegree[i]==0) q.push(i);
        }
        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            for (auto it:adj[node]){
                inDegree[it]--;
                if (inDegree[it]==0) q.push(it);
            }
        }
        return count==numCourses;
    }   
};