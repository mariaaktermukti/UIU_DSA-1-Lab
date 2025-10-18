#include <iostream>
using namespace std;

int adj[10][10], n;
int queue[100], front=0, rear=0;

void enqueue(int x){ queue[rear++] = x; }
int dequeue(){ return queue[front++]; }
bool empty(){ return front==rear; }

int main(){
    int e, start, end;
    cin >> n >> e;
    for(int i=0;i<e;i++){
        int u,v; cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    cin >> start >> end;

    bool visited[10] = {0};
    int dist[10] = {0};

    enqueue(start);
    visited[start] = true;
    dist[start] = 0;

    while(!empty()){
        int u = dequeue();
        for(int v=1; v<=n; v++){
            if(adj[u][v] && !visited[v]){
                visited[v] = true;
                dist[v] = dist[u] + 1;
                enqueue(v);
            }
        }
    }

    if(visited[end]) cout << "Shortest distance from " << start << " to " << end << " = " << dist[end] << endl;
    else cout << "No path exists\n";
}
