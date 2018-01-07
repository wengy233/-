#ifndef tp_h
#define tp_h
#include <string>
extern int maxVertices;
extern int maxWeight;
using namespace std;
struct Router{
    int number;
    string address;
};
class Graphmtx{
protected:
    int numVertices;
    int numEdges;
    string *VerticesList;
    int *p;
    int **Edge;
public:
    Graphmtx();
    int search(int v);//查找路由器所在邻接矩阵位置 
    bool insertVertex(int n,const string vertex);
    bool insertEdge(int v1,int v2,int cost);
    bool removeVertex(int v);//删除顶点 
    bool removeEdge(int v1,int v2);//删除边 
    void remove(int v);//删除某路由器 
    void remove2(int v1,int v2);//删除两路由器间的链路 
    void Shortest(int n);
    void printPath(int v,int dist[],int path[]);
    void shuchu();
};

#endif /* tp_h */
