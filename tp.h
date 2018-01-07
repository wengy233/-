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
    int search(int v);//����·���������ڽӾ���λ�� 
    bool insertVertex(int n,const string vertex);
    bool insertEdge(int v1,int v2,int cost);
    bool removeVertex(int v);//ɾ������ 
    bool removeEdge(int v1,int v2);//ɾ���� 
    void remove(int v);//ɾ��ĳ·���� 
    void remove2(int v1,int v2);//ɾ����·���������· 
    void Shortest(int n);
    void printPath(int v,int dist[],int path[]);
    void shuchu();
};

#endif /* tp_h */
