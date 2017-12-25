#ifndef tp_h
#define tp_h
#include<string>
const int maxVertices=10;
const int maxWeight=INT_MAX;
using namespace std;
struct Router{
    int number;    //路由表编号
    string address;   //路由表地址
};
class Graphmtx{
protected:
    int numVertices;    //当前顶点数
    int numEdges;      //当前边数
    string *VerticesList;    //对应address
    int *p;          //对应number
    int **Edge;      //权值
public:
    Graphmtx();   //初始化
<<<<<<< HEAD
    ~Graphmtx();
    bool removeVertex(int v);//ɾ���� 
    bool removeEdge(int v1,int v2);//ɾ���� 
    void remove(int v);//ɾ��ĳ·�ɱ� 
    void remove2(int v1,int v2);//ɾ��ĳ�� 
=======
    ～Graphmtx();
	void Shortest(int n);   //最短路径计算
>>>>>>> 76c401b8714e6484f30af79eca4601ffdeb4c789
};
#endif /* tp_h */
