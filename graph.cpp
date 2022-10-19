/*-----------------CODED BY NISHCHAY-----------------*/
#include <bits/stdc++.h>
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define REP(i, j, k) FOR(i, j, k, 1)
typedef std::vector<int> VI;
using namespace std;

///*------------------------FUNCTIONS-----------------------*///

void addEdge(VI adjList[],int u,int v){
    
    if(u==v){
        adjList[u].push_back(v);
    }
    else{
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

}

void deleteEdge(VI adjList[], int u, int v){

    if(u == v){
        for(int i = 0; i < adjList[u].size(); i++){

            if(adjList[u][i] == v){
                adjList[u].erase(adjList[u].begin() + i);
                break;
            }
        }
    }
    else{
        for(int i = 0; i < adjList[u].size(); i++){
            if(adjList[u][i] == v){
                adjList[u].erase(adjList[u].begin() + i);
                break;
            }
        }
        for(int i = 0; i < adjList[v].size(); i++){
            if(adjList[v][i] == u){
                adjList[v].erase(adjList[v].begin() + i);
                break;
            }
        }
    }
}

void print(VI adjList[], int vert){

    REP(i,0,vert){
        int k = adjList[i].size();
        REP(j,0,k){
            if(j==k-1){
                cout << adjList[i][j];
            }
            else{
                cout<<adjList[i][j] << "-->";
            }
        }
        cout << endl;
    }

}

void checkTree(VI adjList[]){

    int t = 0;
    for(int i = 0; i < (*adjList).size(); i++){
        t = t + adjList[i].size();
    }
    if(t == 2 * ((*adjList).size() - 1)){
        cout << "\nYES it is a tree\n";
    }
    else{
        cout << "\nNO it is not a tree\n";
    }  
}

void BFS(VI adjList[], VI visited, int start){

    cout << "\nBFS : ";
    queue <int> q; 
    int v;
    q.push(start);
    while (!q.empty()){
        v = q.front();
        visited.at(v) = 1;
        q.pop();
        cout << v << " "; 
        for (auto it = adjList[v].begin(); it != adjList[v].end(); it++){ 
            if (!visited.at(*it)){
                q.push(*it); 
                visited.at(*it) = 1;
            }
        }
    } 
    cout << endl;

}

void DFS(VI adjList[], VI visited, int start){

    visited.at(start) = 1;
    cout << start << " "; 
    for (auto it = adjList[start].begin(); it != adjList[start].end(); it++){
        if (!visited[*it]){
            DFS(adjList, visited, *it); 
        }
    }
} 

VI dfsConnect( VI adjList[], VI visited, int start){

    visited[start] = 1;
    for (int i = 0; i < adjList[start].size(); i++){
        int x = adjList[start][i];
        if (visited[x] == 0){
            cout << x << " ";
            visited = dfsConnect(adjList, visited, x);
        }
    }
    return visited;

}

void connected(VI adjList[], VI visited, int vert){

    cout << "\nConnected components are :-\n";
    for(int v = 0; v < vert; v++) 
    {
        if (visited[v] == 0) 
        {
            cout << v << " ";

            visited = dfsConnect(adjList, visited, v);

            cout << "\n";
        }
    }

}

///*--------------------CODE BEGINS HERE--------------------*///

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
cout << endl;

int vert=8;

int start = 0;


VI adjList[vert];

REP(i,0,vert){
    adjList[i].push_back(i);
}
VI visited(vert,0);


addEdge(adjList, 0, 1);
addEdge(adjList, 0, 2);
addEdge(adjList, 1, 3);
addEdge(adjList, 1, 4);
addEdge(adjList, 3, 3);
addEdge(adjList, 4, 4);
addEdge(adjList, 2, 2);
addEdge(adjList, 5, 6);
addEdge(adjList, 6, 7);

cout << "Adj List :- \n";

print(adjList, vert);
deleteEdge(adjList, 0, 2);
cout << "\nAfter deleting edge between 0 and 2:-\n";
print(adjList, vert);

checkTree(adjList);

BFS(adjList, visited, start);

cout << "DFS : ";
DFS(adjList, visited, start);
cout << endl;

connected(adjList, visited, vert);

cout << endl;
return 0;
}
