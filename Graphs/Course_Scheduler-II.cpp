#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> findOrder(int numCourses,
                      vector<vector<int>>& prerequisites)
{
    vector<vector<int>> adj(numCourses);

    for(auto it : prerequisites)
    {
        int course = it[0];
        int prereq = it[1];

        adj[prereq].push_back(course);
    }

    vector<int> indegree(numCourses,0);

    for(int i=0;i<numCourses;i++)
    {
        for(auto neighbour:adj[i])
        {
            indegree[neighbour]++;
        }
    }

    queue<int> q;

    for(int i=0;i<numCourses;i++)
    {
        if(indegree[i]==0)
            q.push(i);
    }

    vector<int> topo;

    while(!q.empty())
    {
        int node=q.front();
        q.pop();

        topo.push_back(node);

        for(auto neighbour:adj[node])
        {
            indegree[neighbour]--;

            if(indegree[neighbour]==0)
                q.push(neighbour);
        }
    }

    if(topo.size()==numCourses)
        return topo;

    return {};
}

int main()
{
    int numCourses, p;
    cin >> numCourses >> p;

    vector<vector<int>> prerequisites;

    for(int i=0;i<p;i++)
    {
        int course, prereq;
        cin >> course >> prereq;

        prerequisites.push_back({course, prereq});
    }

    vector<int> ans = findOrder(numCourses, prerequisites);

    if(ans.empty())
    {
        cout << "No valid ordering exists.\n";
    }
    else
    {
        cout << "One valid order:\n";
        for(int course : ans)
            cout << course << " ";
        cout << endl;
    }

    return 0;
}