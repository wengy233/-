#ifndef tp_h
#define tp_h
const int maxVertices;
const int maxWeight;
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
    ～Graphmtx();
};
#endif /* tp_h */
