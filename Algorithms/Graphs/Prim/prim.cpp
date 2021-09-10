#include<bits/stdc++.h>

using namespace std;

const int MAX = 1e4 + 5;
bool visited[MAX];
vector<pair<long long, int>> graph[MAX];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> priorityQueue;

long long primMST(int x) {
    int vecinos; 
    long long pesoTotal = 0;
    pair<long long, int> nodoActual; 

    priorityQueue.push(make_pair(0, x)); 
    while(!priorityQueue.empty()) { 
        nodoActual = priorityQueue.top(); 
        priorityQueue.pop(); 
        x = nodoActual.second; 
        if(visited[x]) { 
            continue;
        }
        pesoTotal+= nodoActual.first; 
        visited[x] = true;

        for(int i = 0; i<graph[x].size(); i++) { 
            vecinos = graph[x][i].second; 
            if(!visited[vecinos]) { 
                priorityQueue.push(graph[x][i]);
            }
        }
    }
    return pesoTotal;
}

int main() {

    int n, m;
    cin>>n>>m;
    int x, y, wieght;
    for(int i = 0; i<m; i++) {
        cin>>x>>y>>wieght;
        graph[x].push_back(make_pair(wieght,y));
        graph[y].push_back(make_pair(wieght,x));
    }

    long long costoMinimo = primMST(0); 
    cout<<costoMinimo<<endl;
    return 0;
}
