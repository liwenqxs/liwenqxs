#include <stdio.h>
#include<stdlib.h> 
#define error -1 
#define SIZE 20
#define ok 1
#define f  20
#define FLASE 0
#define TRUE 1 
#define overflow -1
typedef char Elemtype;
int visite[f];
typedef struct
{
	Elemtype vertex[SIZE];        //一维数组放顶点信息 
	int arcs[SIZE][SIZE];         //用一个二维数组存放顶点间关系的数据 
	int vexnum,arcnum;            //图的当前顶点数与狐数 
} Graph_matrix;                 /*无向图的邻接矩阵*/
typedef struct QNode
{
	Elemtype data;
	struct QNode *next;
}pre ;
typedef struct
{
	pre * front;
	pre * rear;
	
}queue;

int initqueue(queue *Q)
{
	Q->front=Q->rear=(QNode*)malloc(sizeof(QNode));
	if(!Q->front)
	exit(overflow);
	Q->front->next=NULL;
	return ok;
}
int enqueue(queue *Q,Elemtype e)
{    pre *p;
	p=(QNode*)malloc(sizeof(QNode));
	if(!p)
	exit(overflow);
	p->data=e;
	p->next=NULL;
	Q->rear->next=p;
	Q->rear=p;
	return ok;
}
int destroy (queue *Q) 
{
while(Q->front)	
   {
   	Q->rear=Q->front->next;
   	free(Q->front);
   	Q->front=Q->rear;
   }
   return ok;
}
int queueempty(queue Q)
{
	if(Q.front->next==NULL)
	return TRUE;
	else
	return FLASE;
}
int dequeue(queue *Q,Elemtype *e)
{    pre  *p;
	if(Q->front==Q->rear)
	return error;
	p=Q->front->next;
	*e=p->data;
	Q->front->next=p->next;
	if(Q->rear==p)
	Q->rear=Q->front;
	free(p);
	return ok;
}   
int locate_Graph_matrix(Graph_matrix G,Elemtype c)/*在无向图中查找顶点C，如果存在返回其在存储结构中的下标，不存在返回-1*/
{
	int i;
	for(i=0;i<G.vexnum;i++)
		if(G.vertex[i]==c)
			return i;   //返回位置信息 
	return error;
}
int creat_graph_matrix(Graph_matrix *G) /*创建无向图的邻接矩阵存储结构*/
{
	int i,j,k; 
	Elemtype a,b;         
	printf("\ninput vert_num(顶点数) and arc_num（边数）:\n");
	scanf("%d %d",&G->vexnum,&G->arcnum);
	printf("\n输入顶点:\n"); //输入顶点的数据  
	getchar();
	for(i=0;i<G->vexnum;i++)
	scanf("%c",&G->vertex[i]);/*请连续输入字符型的顶点数据，不加分隔符,最后以回车结束*/
	getchar();
	for(i=0;i<G->vexnum;i++)
		for(j=0;j<G->vexnum;j++)
			G->arcs[i][j]=0;         //赋初值 
	printf("\n输入顶点关系:\n");
	for(k=0;k<G->arcnum;k++)
	{
	    scanf("%c %c",&a,&b);
		getchar();
		i=locate_Graph_matrix(*G,a);
		j=locate_Graph_matrix(*G,b);
		G->arcs[i][j]=G->arcs[j][i]=1;
	}
}
int Firstadj_matrix(Graph_matrix G,int v)//查找顶点v的第一个邻接点，如果存在返回位置信息 
{
	int j;
	for(j=0;j<G.vexnum;j++)
		if(G.arcs[v][j])
			return j;
	return -1;
}
int Nextadj_matrix(Graph_matrix G,int v,int w)//在无向图（邻接矩阵）中查找顶点v的相对于w的下一个邻接点
{
	int j;
	for(j=w+1;j<G.vexnum;j++)
		if(G.arcs[v][j])
			return j;
	return -1;
}
void DFS_Graph_matrix(Graph_matrix G,int v)
{	int w;
	printf("%c",G.vertex[v]);
	visite[v]=1;      //v已经访问 
	for(w=Firstadj_matrix(G,v);w>=0;w=Nextadj_matrix(G,v,w))
		if(!visite[w])
			DFS_Graph_matrix(G,w);
}
void DFSTraverse_Graph_matrix(Graph_matrix G)  //深度优先遍历 
{

	int v;
	for(v=0;v<G.vexnum;v++)
	visite[v]=0;   //所有顶点都没有访问 
	for(v=0;v<G.vexnum;v++)
		if(!visite[v])     //如果顶点v没有被访问，调用上面的DFS 
		{
			DFS_Graph_matrix(G,v);
		}
}
 void BFSTraverse(Graph_matrix G)  //广度优先遍历 
 {
 	int i,j;
 	Elemtype e;
 	queue Q;
 	for(i=0;i<G.vexnum;i++)
 	  {
 	  	visite[i]=FLASE;
 	  }
 	  initqueue(&Q);
 	  for(i=0;i<G.vexnum;i++)
 	  {
 	  	if(!visite[i])
 	  	printf("%c",G.vertex[i]);
 	  	visite[i]=TRUE;
 	  	enqueue(&Q,i);   //第i个顶点进队列 
 	  	while(!queueempty)
 	  	 {
			dequeue(&Q,&e);   //出队列并用e返回它的值 
			for(j=0;j<G.vexnum;j++)
			{
				if(G.arcs[i][j]==1&&!visite[j])    //有边且没有被访问 
				   {
				   		printf("%c",G.vertex[j]);
 	  	                visite[j]=TRUE;
 	  	                 enqueue(&Q,j);
				   }
			}
         }
 	  }
 }
int main() 
{  
 Elemtype c;
 int v,w;
 Graph_matrix G	;
creat_graph_matrix(&G);	
printf("the shen du you xian result(深度优先遍历结果)\n");
DFSTraverse_Graph_matrix( G);
printf("\n");
printf("the guang du you xian result(广度优先遍历结果)\n");
BFSTraverse(G);	
}

