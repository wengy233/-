#include <iostream>
#include "tp.h"
using namespace std;
Graphmtx::Graphmtx(){
    numVertices = 0;
    numEdges = 0;
    int i,j;
    VerticesList = new string[maxVertices];
    p=new int[maxVertices];
    Edge = (int **) new int*[maxVertices];
    for(i = 0;i<maxVertices;i++)
        Edge[i] = new int[maxVertices];
    for(i=0;i<maxVertices;i++)
        for(j = 0;j<maxVertices;j++)
            Edge[i][j] = (i==j) ?0:maxWeight;
}
bool Graphmtx::insertVertex(int n,const string vertex)
{
    if(numVertices == maxVertices)
        return false;
    VerticesList[numVertices] = vertex;
    p[numVertices]=n;
    numVertices++;
    return true;
}
bool Graphmtx::insertEdge(int v1, int v2,int cost)
{
    if(v1 > -1 && v1< numVertices && v2>-1 && v2<numVertices && Edge[v1][v2] == maxWeight)
    {
        Edge[v1][v2] = Edge[v2][v1] = cost;
        numEdges ++;
        return true;
    }
    else return false;
}
void Graphmtx::printPath(int v, int dist[], int path[])
{
    cout << "| 路由器" << p[v] <<"路由表：" <<"           |"<< endl;
    int i, j, k, n =numVertices;
    int * d = new int[n];
    for (i = 0; i<n; i++)
    {
        if (i != v)
        {
            j = i;
            k = 0;
            while (j != v)
            {
                d[k++] = j;
                j = path[j];
            }
            cout <<"| 目的路由"<<p[i]<<" ";
            cout <<"下一跳："<<d[--k]+1<<" ";
            cout << "权值：" << dist[i] <<" |"<< endl;
        }
    }
    delete[] d;
}
void Graphmtx::shuchu(){
    for(int i=0;i<numVertices;i++){
        for(int j=0;j<numVertices;j++){
            if(Edge[i][j]==INT_MAX){
                cout<<"Max ";
            }
            else
                cout<<Edge[i][j]<<" ";
        }
        cout<<endl;
    }
}
