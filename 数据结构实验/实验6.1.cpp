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
	Elemtype vertex[SIZE];        //һά����Ŷ�����Ϣ 
	int arcs[SIZE][SIZE];         //��һ����ά�����Ŷ�����ϵ������ 
	int vexnum,arcnum;            //ͼ�ĵ�ǰ����������� 
} Graph_matrix;                 /*����ͼ���ڽӾ���*/
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
int locate_Graph_matrix(Graph_matrix G,Elemtype c)/*������ͼ�в��Ҷ���C��������ڷ������ڴ洢�ṹ�е��±꣬�����ڷ���-1*/
{
	int i;
	for(i=0;i<G.vexnum;i++)
		if(G.vertex[i]==c)
			return i;   //����λ����Ϣ 
	return error;
}
int creat_graph_matrix(Graph_matrix *G) /*��������ͼ���ڽӾ���洢�ṹ*/
{
	int i,j,k; 
	Elemtype a,b;         
	printf("\ninput vert_num(������) and arc_num��������:\n");
	scanf("%d %d",&G->vexnum,&G->arcnum);
	printf("\n���붥��:\n"); //���붥�������  
	getchar();
	for(i=0;i<G->vexnum;i++)
	scanf("%c",&G->vertex[i]);/*�����������ַ��͵Ķ������ݣ����ӷָ���,����Իس�����*/
	getchar();
	for(i=0;i<G->vexnum;i++)
		for(j=0;j<G->vexnum;j++)
			G->arcs[i][j]=0;         //����ֵ 
	printf("\n���붥���ϵ:\n");
	for(k=0;k<G->arcnum;k++)
	{
	    scanf("%c %c",&a,&b);
		getchar();
		i=locate_Graph_matrix(*G,a);
		j=locate_Graph_matrix(*G,b);
		G->arcs[i][j]=G->arcs[j][i]=1;
	}
}
int Firstadj_matrix(Graph_matrix G,int v)//���Ҷ���v�ĵ�һ���ڽӵ㣬������ڷ���λ����Ϣ 
{
	int j;
	for(j=0;j<G.vexnum;j++)
		if(G.arcs[v][j])
			return j;
	return -1;
}
int Nextadj_matrix(Graph_matrix G,int v,int w)//������ͼ���ڽӾ����в��Ҷ���v�������w����һ���ڽӵ�
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
	visite[v]=1;      //v�Ѿ����� 
	for(w=Firstadj_matrix(G,v);w>=0;w=Nextadj_matrix(G,v,w))
		if(!visite[w])
			DFS_Graph_matrix(G,w);
}
void DFSTraverse_Graph_matrix(Graph_matrix G)  //������ȱ��� 
{

	int v;
	for(v=0;v<G.vexnum;v++)
	visite[v]=0;   //���ж��㶼û�з��� 
	for(v=0;v<G.vexnum;v++)
		if(!visite[v])     //�������vû�б����ʣ����������DFS 
		{
			DFS_Graph_matrix(G,v);
		}
}
 void BFSTraverse(Graph_matrix G)  //������ȱ��� 
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
 	  	enqueue(&Q,i);   //��i����������� 
 	  	while(!queueempty)
 	  	 {
			dequeue(&Q,&e);   //�����в���e��������ֵ 
			for(j=0;j<G.vexnum;j++)
			{
				if(G.arcs[i][j]==1&&!visite[j])    //�б���û�б����� 
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
printf("the shen du you xian result(������ȱ������)\n");
DFSTraverse_Graph_matrix( G);
printf("\n");
printf("the guang du you xian result(������ȱ������)\n");
BFSTraverse(G);	
}

