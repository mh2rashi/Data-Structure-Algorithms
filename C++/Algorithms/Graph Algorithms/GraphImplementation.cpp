
//4. Graph class consists of two data members:
   // i. The total number of `vertices` in the graph.
   // ii. A list of linked list to store adjacent vertices.

#include<iostream> 
#include <list> 
#include <vector>
using namespace std; 


class Graph { 
	int vertices;
	list<int> *adjacencyList; 

  public:
    Graph(int V);
    ~Graph();
    void addEdge(int v, int w);
}; 

Graph::Graph(int V=0) 
{ 
	this->vertices = V; 
	adjacencyList = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) 
{ 
  if (v < vertices && w < vertices) {
    adjacencyList[v].push_back(w);
    //adjacencyList[w].push_back(v); only for undirected graph
    //where reverse also allowed
  }
} 

Graph::~Graph() { //destructor
  delete[] adjacencyList;
}

/* Driver Program */
int main() {
    Graph myGraph(5);
    return 0;
}

// The variable vertices contains an integer specifying the total number of vertices.
// The second component is a pointer adjacencyList, which is assigned memory when graph constructor
// called according to the number of nodes we want to create. We have to run a loop and create a list for each vertex.



// Another implementation using unordered_map

#include <unordered_map>
#include <vector>

using namespace std;

class Graph {
private:
    unordered_map<int, vector<int>> adjacencyList;

public:
    // Constructor
    Graph() {}

    // Destructor (optional)
    ~Graph() {}

    // Method to add a vertex to the graph
    void addVertex(int v) {
        if (adjacencyList.find(v) == adjacencyList.end()) {
            // If vertex v doesn't exist, add it with an empty vector
            adjacencyList[v] = vector<int>();
        }
    }

    // Method to add an undirected edge between two vertices
    void addEdge(int u, int v) {
        // Add vertex u if it doesn't exist
        addVertex(u);

        // Add vertex v if it doesn't exist
        addVertex(v);

        // Add edge between u and v (undirected graph)
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }

    // Method to get neighbors of a vertex
    vector<int> getNeighbors(int v) {
        if (adjacencyList.find(v) != adjacencyList.end()) {
            // Return the vector of neighbors of vertex v
            return adjacencyList[v];
        }
        return vector<int>(); // Return empty vector if vertex v doesn't exist
    }
};