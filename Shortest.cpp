#include"tp.h"
#include<iostream>
using namespace std;

void Graphmtx::Shortest(int v) { 
<<<<<<< HEAD
	cout << "ËïÞ±" << endl;
=======
	if(v==-1){
             cout<<"²éÎÞ´ËÂ·ÓÉ±í"<<endl;
             return;
        }
>>>>>>> 24bfb4511e508028772f36f631fe5bf3a97cf050
	int dist[numVertices];
	int path[numVertices];
	if(v==-1)
	{
		cout<<"²»´æÔÚ¸ÃÂ·ÓÉÆ÷"<<endl;
		return;
	}
	int n = numVertices;
	bool *S = new bool[n];
	int i, j, k;
	int w, min;
	for (i = 0; i<n; i++)
	{
		dist[i] = Edge[v][i];
		S[i] = false;
		if (i != v && dist[i] <maxWeight)   //Èç¹ûµãv²»ÔÚpathÊý×éÖÐ£¬¶øÇÒÓÐ´Ë±ß£¬Ôò½«µãv¼ÓÈëpathÊý×é£¬·ñÔò²»¼ÓÈë
			path[i] = v;
		else
		{
			path[i] = -1;
		}
	}
	S[v] = true;      //±íÊ¾´Ë±ß´¦ÀíÍê±Ï
	dist[v] = 0;      //ÏÈ½«´Ë±ßµÄ¾àÀëÖÃÁã£¬Ïàµ±ÓÚ³õÊ¼»¯
	for (i = 0; i<n - 1; i++)
	{
		min = maxWeight;   //ÏÈÄ¬ÈÏ×î¶Ì¾àÀëÎªmaxWeight
		int u = v;
		for (j = 0; j<n; j++)
		{
			if (S[j] == false && dist[j] < min)   //Èç¹ûµã»¹Î´´¦Àí£¬ÇÒ´æÔÚ¸ü¶Ì¾àÀë
			{
				u = j;
				min = dist[j];     //´æ´Ë×î¶Ì¾àÀë
			}
		}
		S[u] = true;    //ÈÃ´Ëµã´¦ÀíÍê±Ï
		for (k = 0; k<n; k++)
		{
			w = Edge[u][k];
			if (S[k] == false && w <maxWeight && dist[u] + w<dist[k])   //Èç¹ûµã»¹Î´´¦Àí£¬ÇÒ´æÔÚÐÂÔöÂ·¾¶£¨Í¨¹ý¶à¸öµã£©Ð¡ÓÚÔ­À´Â·¾¶
			{
				dist[k] = dist[u] + w;   //ÔòÓÃ¸üÐ¡µÄ±ßÖµ´úÌæÔ­À´µÄÖµ
				path[k] = u;
			}
		}
	}
	printPath(v, dist, path);   //µ÷ÓÃÊä³öº¯Êý
}
void Graphmtx::printPath(int v, int dist[], int path[])
{
    cout << "| è·¯ç”±å™¨" << p[v] <<"è·¯ç”±è¡¨ï¼š" <<"           |"<< endl;
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
            cout <<"| ç›®çš„è·¯ç”±"<<p[i]<<" ";
            cout <<"ä¸‹ä¸€è·³ï¼š"<<p[d[--k]]<<" ";
            cout << "æƒå€¼ï¼š" << dist[i] <<" |"<< endl;
        }
    }
    delete[] d;
}
