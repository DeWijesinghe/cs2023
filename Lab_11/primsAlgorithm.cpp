#include <cstring>
#include <iostream>
using namespace std;
#include<vector>


vector<vector<int>> findMinTree(vector<vector<int>> graph, int noOfVertices, int startVertex){
    vector<vector<int>> MinSpanTree ;
    bool visited[noOfVertices];
    memset(visited,false,sizeof(visited));
    visited[startVertex]=true;
    int currVertices=0;
    int x;
    int y;
    while (currVertices<noOfVertices-1){
        int minimum=INT_MAX;
        for (int i=0 ; i < noOfVertices; i++){
            if (visited[i]){
                for (int j=0;j< noOfVertices;j++){
                    if (graph[i][j]!=0 && !visited[j]){
                        if (minimum > graph[i][j]){
                            minimum = graph[i][j];
                            x=i;
                            y=j;

                        }
                    }
                }
            }
        }
        visited[y]=true;
        currVertices++;
        MinSpanTree.push_back({x,y,graph[x][y]});
    }
    return MinSpanTree;
}

int main(){
    vector<vector<int>> graph = {{0,3,0,0,0,1},{3,0,2,1,10,0},{0,2,0,3,0,5},{0,1,3,0,5,0},{0,10,0,5,0,4},{1,0,5,0,4,0}};
    vector<vector<int>> MST = findMinTree(graph,6,0);
    for (auto edge:MST ){
        cout<< edge[0] <<","<< edge[1]<<" => " << edge[2]<< endl;
    }
}