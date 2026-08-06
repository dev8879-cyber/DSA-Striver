#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
{
    vector<vector<int>> adj(numCourses);

    // Build graph
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

    int count=0;

    while(!q.empty())
    {
        int node=q.front();
        q.pop();

        count++;

        for(auto neighbour:adj[node])
        {
            indegree[neighbour]--;

            if(indegree[neighbour]==0)
                q.push(neighbour);
        }
    }

    return count==numCourses;
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

    if(canFinish(numCourses, prerequisites))
        cout << "Yes, all courses can be completed.";
    else
        cout << "No, cycle exists.";

    return 0;
}