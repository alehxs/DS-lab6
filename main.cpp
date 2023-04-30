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

//what up zack!!


int main(int argc, char* argv[]){
    ArgumentManager am(argc, argv);
    ifstream fin(am.get("input"));
    ofstream fout(am.get("output"));

    // ifstream fin("input3.txt");
    // ofstream fout("output.txt");

    int numVerts, u, v;
    queue q;
    queue q2;
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
        q.enqueue(u, v);
    }

//this prints the array of structs
    cout << "Array of structs: " << endl;
    for(int i = 0; i < numVerts; i++){
        cout << incounts[i].vertex << " " << incounts[i].count << endl;
    }
    cout << endl;

//until all struct values are 0, this will find the first struct with a count of 0 and enqueue it
    for (int i = 0; i < numVerts; i++){
        for(int j = 0; j < numVerts; j++){
            if(incounts[j].count == 0){
                // cout << incounts[j].vertex << " ";
                q2.enqueue(incounts[j].vertex, 0);
                incounts[j].count = -1;
                for(int k = 0; k < numVerts; k++){
                    if(adj[j][k] == true){
                        incounts[k].count--;
                    }
                }
            }
        }
    }
    if (q2.isEmpty()){
        fout << "No Topological Sorting Exists!" << endl;
    }
    else
    {
        q2.printToFile(fout);
        fout << endl;
    }
    return 0;
}