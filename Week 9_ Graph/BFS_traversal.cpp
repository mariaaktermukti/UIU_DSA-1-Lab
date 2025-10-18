#include <iostream>
using namespace std;

int queue[100], front = 0, rear = 0;

void enqueue(int x){ queue[rear++] = x; }
int dequeue(){ return queue[front++]; }
bool empty(){ return front == rear; }

int main(){
    int n,e;
    cin >> n >> e;
    int adj[10][10] = {0};
    for(int i=0;i<e;i++){
        int u,v; cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    bool visited[10] = {0};
    int start = 1;
    enqueue(start);
    visited[start] = true;

    cout << "BFS Order: ";
    while(!empty()){
        int u = dequeue();
        cout << u << " ";
        for(int v=1;v<=n;v++){
            if(adj[u][v] && !visited[v]){
                enqueue(v);
                visited[v] = true;
            }
        }
    }
}
