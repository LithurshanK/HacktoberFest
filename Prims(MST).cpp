#include <bits/stdc++.h>
#include <queue>
using namespace std;


string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'prims' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY edges
 *  3. INTEGER start
 */

// create class for an edge
class Edge{
    public:
        int u,v,wt;
};

// compare condition to sort edgelist
bool sort_condition(Edge x, Edge y)
{
    return x.wt < y.wt;
}

int prims(int n, vector<vector<int>> edges, int start) {
    int m = edges.size();
    
    vector<bool> inMST(n+1); // inMST[x] = true if node x is in already connected to MST
    vector<Edge> edgeList(m); // vector list for all the edges in the graph
    
    for (int i=0; i<m; i++){
        edgeList[i].u = edges[i][0];
        edgeList[i].v = edges[i][1];
        edgeList[i].wt = edges[i][2];
    }
    
    // sort the edgelist to have weights in ascending order
    sort(edgeList.begin(),edgeList.end(),sort_condition);

    for(int i=0; i<=n; i++){

        inMST[i] = false;
    }

    inMST[start] = true;

    int weight = 0; // weight of MST
    int vertices = 1;
    
    // by prims algorithm we will traverse through edges and when some nodes are visted(they are in MST) we will add the adjacent nodes of the visited nodes in the order of having less edge weight.
    
    // loop while not all the nodes are not in MST
    while(vertices<n){
        
        for(Edge e: edgeList){
            // check for an edge if one node is in the MST and other node is not
            if((inMST[e.u]==true && inMST[e.v]==false)||(inMST[e.v]==true && inMST[e.u]==false)){
                // add the node to MST 
                inMST[e.v] = true;
                inMST[e.u] = true;
                
                // add the edge weight to MST weight
                weight+=e.wt;
                vertices++; // increment the MST vertices count
                break; // break after a node is added to check wether all the nodes are added.
            }
        }    
    
    }

    return weight;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<vector<int>> edges(m);

    for (int i = 0; i < m; i++) {
        edges[i].resize(3);

        string edges_row_temp_temp;
        getline(cin, edges_row_temp_temp);

        vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int edges_row_item = stoi(edges_row_temp[j]);

            edges[i][j] = edges_row_item;
        }
    }

    string start_temp;
    getline(cin, start_temp);

    int start = stoi(ltrim(rtrim(start_temp)));

    int result = prims(n, edges, start);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
