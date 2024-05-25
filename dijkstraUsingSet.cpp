#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>>& adj, int V, int S) {

    set<pair<int, int>> st;
    vector<int> dis(V, 1e9);

    dis[S] = 0;
    
    // S DENOTES SOURCE HERE 
    st.insert({0, S});              // SHORTEST DISTANCE FROM SOURCE NODE TO SOURCE IS OBVIOUSLY 0

    while(!st.empty()) {

        auto it = *(st.begin());

        int node = it.second;
        int dist = it.first;

        st.erase(it);
        // ITERATE OVER THE ADJACENT NODE AND TRY TO FIND A SHORTER DISTANCE 

        for(auto value : adj[node]) {

            int adjnode = value.first;
            int edgewt = value.second;

            //  CHECK IF A SHORTER DISTANCE EXISTS IF EXISTS REPLACE IT AND DELETE FROM SET
            if(edgewt + dist < dis[adjnode]) {

                if(dis[adjnode] != 1e9){
                    
                    // THAT MEANS THERE EXISTS A DISTANCE THAT IS GREATER THEN THE NEWLY FIND DISTANCE 
                    // OTHER THAN 1E9

                    st.erase({dis[adjnode], adjnode});
                }

                // THERE EXISTS A SHORTER DISTANCE
            
                dis[adjnode] = edgewt + dist;

                st.insert({dis[adjnode], adjnode});
                
            }

        }
    }

    return dis;

}
int main() {

    int V = 3, E = 3, S = 2;
    vector<vector<pair<int, int>>> adj(V);

    adj[0].push_back({1, 1});
    adj[0].push_back({2, 6});
    adj[1].push_back({2, 3});
    adj[1].push_back({0, 1});
    adj[2].push_back({1, 3});
    adj[2].push_back({0, 6});

    vector<int> ans = dijkstra(adj, V, S);

    for (auto value : ans) {
        cout << value << " ";
    }

    cout << endl;

    return 0;
}