#include <iostream>
#include <vector>
using namespace std;

class graph{
 
    public:
    int node;
    vector<int> *l;

    graph(int node) {

        this->node = node;
        l = new vector<int>[node];
    }

    void addEdge(int v, int w) {

        l[v].push_back(w);
        l[w].push_back(v);
    }

    void print() {

        for(int i=0; i<node; i++) {
            
            cout << i << " -> ";
            for(auto value : l[i]) {

                cout << value << " ";
            }
            cout << endl;
        }
    } 

};

int main() {

    graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    g.print();

    return 0;
}

