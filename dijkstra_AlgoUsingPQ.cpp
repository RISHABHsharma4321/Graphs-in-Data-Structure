#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> solve(int V, vector<vector<int>> adj[], int S) {

    // HERE S DENOTES SOURCE NODE

    vector<int> dis(V, 1e9);
    
    // DECLARING A MIN HEAP
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0,S});
    dis[S] = 0;

    while(!pq.empty()) {

        int dist = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        for(auto value : adj[node]) {

            // calculate the shortest path from the source node
            int edgewt = value[1];
            int adjnode = value[0];

            if(edgewt + dist < dis[adjnode]) {

                // we got a short path from source to node to adjnode
                dis[adjnode] = edgewt + dist;
                // push the new distance to the Pqueue
                pq.push({dis[adjnode], adjnode});

            }
        }
    }

    return dis;
}
int main() {

    int V = 3, E = 3, S = 2;
    vector<vector<int>> adj[V];
    vector<vector<int>> edges;

    vector<int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};

    int i = 0;
    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);

    vector<int> ans = solve(V, adj, S);

    for(auto value : ans) {

        cout << value << " ";
    }

    cout << endl;

    return 0;
}
