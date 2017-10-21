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
}Arcnode;      /*�ڽӱ�ı���ṹ����ʾ�߻��߻�����Ϣ*/
typedef struct
{
	Elemtype data;
	Arcnode *firstarc;
 }Vernode; // �ڽӱ�Ķ�����
 typedef struct
{
	Vernode vertex[SIZE];
	int vexnum,arcnum;
}Graph_adjlist;/*����ͼ���ڽӱ�*/   

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

int locate_Graph_adjlist(Graph_adjlist G,Elemtype c)/*������ͼ���ڽӱ��в��Ҷ���C��������ڷ������ڴ洢�ṹ�е��±꣬�����ڷ���-1*/
{
	int i;
	for(i=0;i<G.vexnum;i++)
		if(G.vertex[i].data==c)
			return i;
	return -1;
}            
int creat_graph_adjlist(Graph_adjlist *G)   /*��������ͼ���ڽӱ�洢�ṹ*/
{
	int i,j,k,y;
	Arcnode *p,*q;
	Elemtype a,b;
	printf("\ninput vert_num(������) and arc_num(����):\n");
	scanf("%d%d",&(G->vexnum),&(G->arcnum));
	printf("\niput the vertex_(����):\n");
	getchar();
	for(i=0;i<G->vexnum;i++)
		{scanf("%c",&G->vertex[i].data);/*�������ַ��͵Ķ������ݣ����ӷָ���������Իس�����*/
		G->vertex[i].firstarc=NULL;
		}
	getchar();

	printf("\niput the arc_relitivity (sush as:A B):\n");/*����ߵĹ�ϵ����A B���س���B C���س���*/
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
int Firstadj_adjlist(Graph_adjlist G,int v)/*������ͼ���ڽӱ��в��Ҷ���v�ĵ�һ���ڽӵ㣬������ڷ������ڴ洢�ṹ�е��±꣬�����ڷ���-1*/
{

	if(G.vertex[v].firstarc)
		return G.vertex[v].firstarc->adj;
	return -1;

}
int Nextadj_adjlist(Graph_adjlist G,int v,int w)/*������ͼ���ڽӱ��в��Ҷ���v�������w����һ���ڽӵ㣬��w��v���ڽӵ㣬��Ҫ��w�������һ��v���ڽӵ㣬������ڷ������ڴ洢�ṹ�е��±꣬�����ڷ���-1*/
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
		printf("\n�ö������ӵĻ���%c",G.vertex[i].data);
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






