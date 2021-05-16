#include<bits/stdc++.h>
using namespace std;
#define MAX 100
void BFS(map<int, vector<int>> graph, int start){
    queue<int> vertices;
    int vis[MAX] = {0};
    int cur;
    vertices.push(start);
    while(!vertices.empty()){
        cur = vertices.front();
        vis[cur]=1;
        cout << cur << " ";
        vertices.pop();
        for(auto vert : graph[cur]) {
            if(!vis[vert]) vertices.push(vert);
            vis[vert]=1;
        }
    }
}
// O(V) space
// O(V+E) time

// vertices = [6 7]
// visited 1 4 5 0 2 3
// cur 3
int main(){
    map<int, vector<int>> graph;
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[0].push_back(3);

    graph[1].push_back(4);
    graph[1].push_back(5);
    graph[1].push_back(0);
    
    graph[2].push_back(6);
    graph[2].push_back(7);
    graph[2].push_back(0);
    
    graph[3].push_back(0);
    graph[3].push_back(7);
    
    graph[4].push_back(1);
    
    graph[5].push_back(1);
    
    graph[6].push_back(2);
    
    graph[7].push_back(2);
    graph[7].push_back(3);
    BFS(graph, 1);
}