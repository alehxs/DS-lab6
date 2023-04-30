#include "ArgumentManager.h"
#include <fstream>
#include <iostream>
#include "queue.h"
using namespace std;

struct InCount{
    int vertex;
    int count;
    InCount() {vertex = 0; count = 0;}
    InCount(int vert, int cnt){
        vertex = vert;
        count = cnt;
    }
};

int main(int argc, char* argv[]){
    ArgumentManager am(argc, argv);
    ifstream fin("input1.txt");
    ofstream fout("output.txt");
    //ifstream fin(am.get("input"));
    //ofstream fout(am.get("output"));
    int numVerts, u, v;
    fin >> numVerts; //takes # of verticies from input file

//this creates a bool array that is intialized to false
    bool** adj = new bool*[numVerts];
    for(int i = 0; i < numVerts; i++){
        adj[i] = new bool[numVerts];
        for(int j = 0; j < numVerts; j++){
            adj[i][j] = false;
        }
    }
    
//this creates an array of structs that holds the vertex and the number of incoming edges
    InCount* incounts = new InCount[numVerts];
    for(int i = 0; i < numVerts; i++){
        incounts[i].vertex = i;
    }

//this reads in the edges from the input file and sets the corresponding adjaceny matrix values to true
    cout << numVerts << endl;
    while(fin >> u >> v){
        //cout << u << " " << v << endl;
        adj[u][v] = true;
        incounts[v].count++;
    }

//this prints the adjaceny matrix
    for(int row = 0; row < numVerts; row++){
        for(int col = 0; col < numVerts; col++){
            if(adj[row][col]){
                cout << "+ ";
            }
            else {
                cout << ". ";
            }
        }
        cout << endl;
    }

//this prints the array of structs
    cout << "Array of structs: " << endl;
    for(int i = 0; i < numVerts; i++){
        cout << incounts[i].vertex << " " << incounts[i].count << endl;
    }

//this creates a queue of vertices with no incoming edges
    queue q;
    for(int i = 0; i < numVerts; i++){
        if(incounts[i].count == 0){
            q.enqueue(incounts[i].vertex, incounts[i].count);
        }
    }
    cout << "Queue: " << endl;
    q.print();
    
    return 0;
}