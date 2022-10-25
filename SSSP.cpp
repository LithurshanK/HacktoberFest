#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define INF 100000

// Struct for the edges of the graph
struct Edge {
    int u;  // source vertex of the edge
    int v;  // destination vertex of the edge
    int w;  // weight of the edge
};

// Graph 
struct Graph {
    int V;        // Total number of vertices in the graph
    int E;        // Total number of edges in the graph
    struct Edge* edge;  // Array of edges
};

// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = new Graph;
    graph->V = V;  // Total Vertices
    graph->E = E;  // Total edges

    // Array of edges for graph
    graph->edge = new Edge[E];
    return graph;
}

vector<int> preNode; //list for predecessor of nodes in the shortest path.
//initializing the shortest path for each vertices
void initialize(int vertices, int dist[], int u){
    preNode.resize(vertices);
    for(int i=0; i<vertices; i++){
        dist[i]=INF;
        preNode[i]=-1;
    }
    //for source distance is 0
    dist[u]=0;  
}

//relaxing all edges for no of vertices - 1 times
void relax(struct Graph* graph,int vertices,int edges,int dist[]){
        for (int i=0; i<vertices; i++){
            for(int e=0; e<edges; e++){
                int src = graph->edge[e].u;
                int des = graph->edge[e].v;
                int wt = graph->edge[e].w;
                
                //check if the new distance by adding the edge is less than previous distance
                if (dist[des]>dist[src]+wt){
                    //update the distance and predecessor
                    dist[des]=dist[src]+wt;
                    preNode[des]=src;
            }
        }
    }

}



void BellmanFord(struct Graph* graph, int u, int dist[], int vertices, int edges) {
    
    initialize(vertices,dist,u);
    relax(graph,vertices,edges,dist);
    // weights given are positive. No need to check negative cycles.
}

// Printing the solution
void printSSSP(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main() {
    int V; // Total vertices
    int E; // Total edges
    std::cin >> V >> E;

    struct Graph* graph = createGraph(V, E);

    int u, v, w;
    for (int i=0; i<E; i++) {
        cin >> u >> v >> w;
        graph->edge[i].u = u;
        graph->edge[i].v = v;
        graph->edge[i].w = w;
    }

    int dist[V];
    
    BellmanFord(graph, 0, dist,V,E);  //0 is the source vertex

    printSSSP(dist, V);

    return 0;
}
