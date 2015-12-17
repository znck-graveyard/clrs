/*
 * Dijkstra's Algorithm, Page 658 (CLRS section 24.3)
 * @author Anup Agarwal
 */

#include <bits/stdc++.h>

using namespace std;

#define MAX_VERTICES 10

struct edge{ int to,length; };

void dijkstra(vector< vector<edge> > &graph, int source, int target){

    vector<int> dos(MAX_VERTICES, INT_MAX);
    dos[source] = 0;
    vector<int> parent(MAX_VERTICES, -1);

    set< pair<int,int> > active;
    active.insert({0,source});

    while(!active.empty()){
        int mincandidate = active.begin()->second;
        active.erase(active.begin());
        for(int i = 0; i<graph[mincandidate].size(); i++){
            edge e = graph[mincandidate][i];
            if(dos[e.to]>(dos[mincandidate]+e.length)){
                if(dos[e.to]!=INT_MAX)
                    active.erase({dos[e.to],e.to});
                dos[e.to] = dos[mincandidate]+e.length;
                parent[e.to] = mincandidate;
                active.insert({dos[e.to],e.to});
            }
        }
    }

    cout<<"\nMin Distance=\t"<<dos[target];
    list<int> path;
    int i = target;
    for(; parent[i]!=-1; i = parent[i]){
        path.push_front(i);
    }
    path.push_front(i);

    cout<<endl;

    for(list<int>::iterator j = path.begin(); j!=path.end(); j++){
        cout<<*j<<" ";
    }
}

void AddEdge(vector< vector<edge> > &graph, int u, int v, int length){
    edge e;
    e.length=length;
    e.to=v;
    graph[u].push_back(e);
}

//Test Case
int main()
{
    vector< vector<edge> > g(MAX_VERTICES);
    AddEdge(g,0,1,10);
    AddEdge(g,0,2,20);
    AddEdge(g,1,3,10);
    AddEdge(g,2,4,15);
    AddEdge(g,3,5,11);
    AddEdge(g,5,6,12);
    AddEdge(g,1,0,14);
    AddEdge(g,3,6,19);
    AddEdge(g,2,5,1);
    AddEdge(g,3,6,10);

    dijkstra(g,0,5);
    return 0;
}
