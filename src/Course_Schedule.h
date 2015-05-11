class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int> > graph(numCourses, vector<int>());
        queue<int> zero_in;
        for(int i = 0; i < prerequisites.size(); i++){
            indegree[prerequisites[i][1]]++;
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0){
                zero_in.push(i);
            }
        }
        while(!zero_in.empty()){
            int cur = zero_in.front();
            zero_in.pop();
            for(int i = 0; i < graph[cur].size(); i++){
                indegree[graph[cur][i]]--;
                if(indegree[graph[cur][i]] == 0){
                    zero_in.push(graph[cur][i]);
                }
            }
            vector<int> tmp;
            graph[cur] = tmp;
        }
        for(int i = 0; i < numCourses; i++){
            if(graph[i].size()!=0){
                return false;
            }
        }
        return true;
    }
};