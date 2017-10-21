#include<stdio.h> 
#include<stdlib.h> 
#define error -1 
#define SIZE 50
#define ok 1
#define f 20
#define TRUE 1
#define overflow 0
#define FLASE 0
typedef char Elemtype;
int visited[f];
typedef struct arcnode 
{
	int adj;
	int y;
	struct arcnode *nextarc;
}Arcnode;      /*邻接表的表结点结构，表示边或者弧的信息*/
typedef struct
{
	Elemtype data;
	Arcnode *firstarc;
 }Vernode; // 邻接表的顶点结点
 typedef struct
{
	Vernode vertex[SIZE];
	int vexnum,arcnum;
}Graph_adjlist;/*无向图的邻接表*/   

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

int locate_Graph_adjlist(Graph_adjlist G,Elemtype c)/*在无向图（邻接表）中查找顶点C，如果存在返回其在存储结构中的下标，不存在返回-1*/
{
	int i;
	for(i=0;i<G.vexnum;i++)
		if(G.vertex[i].data==c)
			return i;
	return -1;
}            
int creat_graph_adjlist(Graph_adjlist *G)   /*创建无向图的邻接表存储结构*/
{
	int i,j,k,y;
	Arcnode *p,*q;
	Elemtype a,b;
	printf("\ninput vert_num(顶点数) and arc_num(边数):\n");
	scanf("%d%d",&(G->vexnum),&(G->arcnum));
	printf("\niput the vertex_(顶点):\n");
	getchar();
	for(i=0;i<G->vexnum;i++)
		{scanf("%c",&G->vertex[i].data);/*请输入字符型的顶点数据，不加分隔符，最后以回车结束*/
		G->vertex[i].firstarc=NULL;
		}
	getchar();

	printf("\niput the arc_relitivity (sush as:A B):\n");/*输入边的关系，如A B（回车）B C（回车）*/
	for(k=0;k<G->arcnum;k++)
	{
		scanf("%c%c%d",&a,&b,&y);
		
		i=locate_Graph_adjlist(*G,a);j=locate_Graph_adjlist(*G,b);
		p=(Arcnode *)malloc(sizeof(Arcnode));
		p->adj=j;
		p->y=y;
	   p->nextarc=G->vertex[i].firstarc;
		G->vertex[i].firstarc=p;
		q=(Arcnode *)malloc(sizeof(Arcnode));
		q->adj=i;
		q->y=y;
		q->nextarc=G->vertex[j].firstarc;
		G->vertex[j].firstarc=q;
	getchar(); 
	} 
}
int Firstadj_adjlist(Graph_adjlist G,int v)/*在无向图（邻接表）中查找顶点v的第一个邻接点，如果存在返回其在存储结构中的下标，不存在返回-1*/
{

	if(G.vertex[v].firstarc)
		return G.vertex[v].firstarc->adj;
	return -1;

}
int Nextadj_adjlist(Graph_adjlist G,int v,int w)/*在无向图（邻接表）中查找顶点v的相对于w的下一个邻接点，即w是v的邻接点，则要找w后面的下一个v的邻接点，如果存在返回其在存储结构中的下标，不存在返回-1*/
{
	Arcnode *p;
	for(p=G.vertex[v].firstarc;p;p=p->nextarc)
		if(p->adj==w&&p->nextarc)
			return p->nextarc->adj;
	return -1;
}
void DFS_Graph_adjlist(Graph_adjlist G,int v)
{	int w;
	printf("%c",G.vertex[v].data);
	visited[v]=1;
	for(w=Firstadj_adjlist(G,v);w>=0;w=Nextadj_adjlist(G,v,w))
		if(!visited[w])
			DFS_Graph_adjlist(G,w);
}
void DFSTraverse_Graph_adjlist(Graph_adjlist G)
{
	
	int v;
	for(v=0;v<G.vexnum;v++)
		visited[v]=0;
	for(v=0;v<G.vexnum;v++)
		if(!visited[v])
		{
			DFS_Graph_adjlist(G,v);
		}
		printf("\n");
}
void BFSTraverse(Graph_adjlist G)
{
	int v ;
	Arcnode *p;
	queue Q;
    char e; 
	for(v=0;v<G.vexnum;++v)
	visited[v]=FLASE;
	initqueue(&Q);
	for(v=0;v<G.vexnum;++v)
	if(!visited[v])
	{
		visited[v]=TRUE;
	  printf("%c",G.vertex[v].data);
	  enqueue(&Q,v);
	  while(!queueempty(Q))
	   {
	   	dequeue(&Q,&e);
	   	for(p=G.vertex[e].firstarc;p;p=p->nextarc)
	   	if(!visited[p->adj])
	   	 {
	   		visited[p->adj]=TRUE;
	   		printf("%c",G.vertex[p->adj].data);
	   		enqueue(&Q,p->adj);
	   		
	   	 }
	   	
	   }
	
    }
}
void output(Graph_adjlist G)	
{
	int i,m;
	for(i=0;i<G.vexnum;i++)
	{
		printf("\n该顶点连接的弧：%c",G.vertex[i].data);
		while(G.vertex[i].firstarc)
		{
			m=G.vertex[i].firstarc->adj;
			printf("\n %c %d",G.vertex[m].data,G.vertex[i].firstarc->y) ;
			G.vertex[i].firstarc=G.vertex[i].firstarc->nextarc;
		}
	}
}
int main()
{ 
Graph_adjlist G;
    int v,w;
  	creat_graph_adjlist(&G);
  	output(G);
  	printf("\n") ;
	printf("shen du bian li\n"); 
	DFSTraverse_Graph_adjlist( G);
	printf("guang du bian li\n");
	BFSTraverse(G);
}






