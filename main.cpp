#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <unordered_map>
#include "ArgumentManager.h"
using namespace std;

const int MAXN = 10000;
int a, b; 
vector<int> adjacent[MAXN];
int inLevel[MAXN];

void topSort() {
    int count = 0;
    vector<int> seq;
    queue<int> c; 
    for(int i = 0; i < a; i++){
        if(inLevel[i] == 0)
            c.push(i);
    }
    while(!c.empty()){
        int d = c.front();
        c.pop();
        seq.push_back(d);
        for(int v : adjacent[d]){
            if(--inLevel[v] == 0)
                c.push(v);
        }
        count++;
    }
    if(count != a)
        cout << "No Topological Sorting Exists!" << endl;
    else{
        for(int i = 0; i < a; i++){
            cout << seq[i];
            if(i != a-1)
                cout << " ";
        }
        cout << endl;
    }
}

int main(int argc, char* argv[]){
    ArgumentManager am(argc, argv);
    ifstream fin(am.get("input"));
    ofstream fout(am.get("output"));

    // ifstream fin("input.txt");
    // ofstream fout("output.txt");

    int num, x, y;
    fin >> num;

    queue<int> c;
    unordered_map<int, vector<int> > adjacentList;
    unordered_map<int, int> inEdges;
    vector<int> sortedVertices;

    while(fin >> x >> y){
        adjacentList[x].push_back(y);
        inEdges[y]++;
    }
    for(int i = 0; i < num; i++){
        if (inEdges[i] == 0) {
            c.push(i);
        }
    }
    while(!c.empty()){
        int currentVertex = c.front();
        c.pop();
        sortedVertices.push_back(currentVertex);
        for (int nextTo : adjacentList[currentVertex]) {
            inEdges[nextTo]--;
            if (inEdges[nextTo] == 0) {
                c.push(nextTo);
            }
        }
    }
    if(sortedVertices.size() != num){
        fout << "No Topological Sorting Exists!" << endl;
        return 0;
    }
    for(int vert : sortedVertices)
        fout << vert << " ";
    fout << endl;

    fin.close();
    fout.close();
    return 0;
}