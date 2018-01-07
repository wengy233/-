//
//  翁月.cpp
//  3
//
//  Created by 翁月 on 2017/12/25.
//  Copyright © 2017年 翁月. All rights reserved.
//

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
    int w1=-1,w2=-1;
    for(int i=0;i<numVertices;i++){
        if(p[i]==v1){
            w1=i;
        }
        if(p[i]==v2){
            w2=i;
        }
        if(w1!=-1&&w2!=-1){
            break;
        }
    }
    cout<<w1<<" "<<w2<<endl;
    if(w1 > -1 && w2< numVertices && w1>-1 && w2<numVertices && Edge[w1][w2] == maxWeight)
    {
        Edge[w1][w2] = Edge[w2][w1] = cost;
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
            cout <<"下一跳："<<p[d[--k]]<<" ";
            cout << "权值：" << dist[i] <<" |"<< endl;
        }
    }
    delete[] d;
}
int Graphmtx::re(int q){
    int v;
    for(int h=0;h<numVertices;h++){
        if(p[h]==q){
            v=h;
            break;
        }
    }
    return v;
}
void Graphmtx::shuchu(){
    cout<<"     ";
    for(int i=0;i<numVertices;i++){
        cout<<p[i]<<"  ";
    }
    cout<<endl;
    for(int i=0;i<numVertices;i++){
        cout<<p[i]<<" | ";
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
