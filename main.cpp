#include "ArgumentManager.h"
#include <fstream>

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
    fin >> numVerts;

    bool** adj = new bool*[numVerts];
    for(int i = 0; i < numVerts; i++){
        adj[i] = new bool[numVerts];
        for(int j = 0; j < numVerts; j++){
            adj[i][j] = false;
        }
    }
    

    InCount* incounts = new InCount[numVerts];
    for(int i = 0; i < numVerts; i++){
        incounts[i].vertex = i;
    }
    
    cout << numVerts << endl;
    while(fin >> u >> v){
        //cout << u << " " << v << endl;
        adj[u][v] = true;
        incounts[v].count++;
    }

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

    
    for(int i = 0; i < numVerts; i++){
        cout << incounts[i].vertex << " " << incounts[i].count << endl;
    }
    
    
    return 0;
}