#include <iostream>
#include <vector>
using namespace std;

// adjacency matrix :
// TIME TO ADD EDGE -> O(1);
// SPACE COMPLEXITY -> O(N2);
int main() {

  int edges;
  cout << "ENTER THE NUMBER OF EDGES = ";
  cin >> edges;
  
  // declaring a 2d array
  vector<vector<int>> adjMatrix(edges, vector<int>(edges, 0));

  // ADDING EDGES
  int v, w;
  cout << "ENTER THE EDGES TO CONNECT : "<<endl;
  cin >> v >> w;

  adjMatrix[v][w] = 1;
  // in case of undirected graph
  adjMatrix[w][v] = 1;
  
  
}