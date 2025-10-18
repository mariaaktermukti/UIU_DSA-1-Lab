#include <iostream>
using namespace std;

int adj[10][10], n;
int queue[100], front=0, rear=0;

void enqueue(int x){ queue[rear++] = x; }
int dequeue(){ return queue[front++]; }
bool empty(){ return front==rear; }

int main(){
    int e, start;
    cin >> n >> e;
    for(int i=0;i<e;i++){
        int u,v; cin >> u >> v;
        adj[u][v] = adj[v][u] = 1;
    }
    cin >> start;

    bool visited[10] = {0};
    int level[10] = {0};

    enqueue(start);
    visited[start] = true;
    level[start] = 0;

    while(!empty()){
        int u = dequeue();
        for(int v=1; v<=n; v++){
            if(adj[u][v] && !visited[v]){
                visited[v] = true;
                level[v] = level[u] + 1;
                enqueue(v);
            }
        }
    }

    // print nodes at each level
    int maxLevel=0;
    for(int i=1;i<=n;i++) if(level[i]>maxLevel) maxLevel = level[i];

    for(int l=0;l<=maxLevel;l++){
        cout << "Level " << l << ": ";
        for(int i=1;i<=n;i++)
            if(level[i]==l) cout << i << " ";
        cout << endl;
    }
}
