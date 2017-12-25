#include"tp.h"
#include<iostream>
using namespace std;
int Graphmtx::search(int v){
    int i;
    for(i=0;i<numVertices;i++){
        if(p[i]==v){
            break;
        }
    }
    return i;
}
bool Graphmtx::removeVertex(int v)
{
    if(v < 0 && v>= numVertices)
        return false;
    if(numVertices == 1)
        return false;
    int i,j;
    VerticesList[v] = VerticesList[numVertices - 1];
    p[v]=p[numVertices-1];
    for(i = 0;i<numVertices;i++)
    {
        if( Edge[i][v] >0 && Edge[i][v] <maxWeight )
            numEdges --;
    }
    for(i = 0;i<numVertices;i++)
    {
        Edge[i][v] = Edge[i][numVertices-1];
    }
    numVertices --;
    for(j= 0;j<numVertices;j++)
        Edge[v][j] =Edge[numVertices][j];
    return true;
}
bool Graphmtx::removeEdge(int v1,int v2)
{
    if (v1 > -1 && v1< numVertices && v2>-1 && v2<numVertices && Edge[v1][v2] > 0 && v1 != v2 && Edge[v1][v2]< maxWeight)
    {
        Edge[v1][v2] = Edge[v2][v1]=maxWeight;
        numEdges --;
        return true;
    }
    else
    {
        return false;
    }
}
void Graphmtx::remove(int v){
    int i;
    i=search(v);
    removeVertex(i);
}
void Graphmtx::remove2(int v1,int v2){
    int i,j;
    i=search(v1);
    j=search(v2);
    removeEdge(i,j);
}
