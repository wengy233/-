#ifndef tp_h
#define tp_h
const int maxVertices 10;
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
    ～Graphmtx();     //析构函数
    int search(int v);
    bool insertVertex(int n, const string vertex);
    bool insertEdge(int v1, int v2, int cost);
    bool removeVertex(int v);      //删除点
    bool removeEdge(int v1, int v2);    //删除边
    void remove(int v);
    void remove2(int v1, int v2); 
    void Shortest(int n);      //最短路径的计算
    void printPath(int v, int dist[], int path[]);    //输出最短路径
    void shuchu(); //输出邻阶矩阵
};
#endif /* tp_h */
