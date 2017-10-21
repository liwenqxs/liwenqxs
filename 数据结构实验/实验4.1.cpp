
#include<stdio.h> 
#include<stdlib.h> 
#include<time.h>
#define MAXSIZE 100
#define ok 1
#define error 0 
typedef struct 
{
	int i,j;
	int  e; //非零元 
}triple; //三元组 
typedef struct
{
	triple data[MAXSIZE+1] ;
	int mu,nu,tu; //行数 列数 非零元个数 
}tsmatrix; //希疏矩阵 
void createtsmatrix(tsmatrix *M)  //生成希疏矩阵 
{
		printf("please input  ju zhen line number list number(输入矩阵行数与列数)\n ") ;//输入矩阵行数与列数
	scanf("%d  %d",&M->mu,&M->nu) ;
	M->tu=0;
	srand(time(NULL));//初始化 
	int i ,j,math;
	for(i=1;i<=M->mu;i++)
	{
		for(j=1;j<M->nu;j++)
		{
			math=1+(int)rand()%100;
			if(math>=5&&math<=35)
			{
				M->data[M->tu].e=1+(int)rand()%9;
				M->data[M->tu].i=i;
				M->data[M->tu++].j=j;
			}
		}
	}
	
}
void output(tsmatrix M) //输出矩阵 
{
	int i,j,k=0;
	printf("tsmatrix\n");
	for(i=1;i<=M.mu;i++)
	{
		for(j=1;j<=M.nu;j++)
		{
			if(i==M.data[k].i&&j==M.data[k].j)
			{
				printf("%d ",M.data[k++].e);
			}
			else
			printf("0 ");
		}
		printf("\n");
			
	} 
}
void printtsmatrix(tsmatrix M) //输出三元组矩阵 
{
int n;
printf("printf the triple\n");
printf("line    list    value\n");
for(n=0;n<M.tu;n++)
printf("%d  %d  %d\n",M.data[n].i,M.data[n].j,M.data[n].e);	
}

void change(tsmatrix M,tsmatrix *T)
{
	int i;
	T->mu=M.nu;
	T->nu=M.mu;
	T->tu=M.tu;
	for(i=0;i<M.tu;i++)
	{
		T->data[i].i = M.data[i].j;
		T->data[i].j = M.data[i].i;
		T->data[i].e = M.data[i].e;
	}
	
}

  
int addtsmatrix(tsmatrix M,tsmatrix N,tsmatrix *Q)//三元组形式相加 
{
	int m=0,n=0,q=0;
	Q->mu=M.mu;
	Q->nu=M.nu;
	while(m<M.tu&&n<N.tu)
	{
		if(M.data[m].i<N.data[n].i)	
		Q->data[q++]=M.data[m++];
		else if(M.data[m].i>N.data[n].i)
		Q->data[q++]=N.data[n++];
		else
		{
			if(M.data[m].j<N.data[n].j)
			Q->data[q++]=M.data[m++];
			else if(M.data[m].j>N.data[n].j)
			Q->data[q++]=N.data[n++];
			else
			{
				Q->data[q] = M.data[m];
				Q->data[q++].e=M.data[m++].e+N.data[n++].e;
			}
		}
	}
	while(m<M.tu)
	Q->data[q++]=M.data[m++];
	while(n<N.tu)
	Q->data[q++]=N.data[n++];
	Q->tu=q;
}

int main()
{
tsmatrix  M,N,T,Q;
createtsmatrix(&M);
createtsmatrix(&N) ;
output(M);
output(N);

printtsmatrix(M);
 printtsmatrix(N);
 
 change( M,&T);
  printf("the change ");
  printtsmatrix(T);
 
  addtsmatrix( M, N, &Q);
   printf("the add");
   printtsmatrix(Q);
   printf("the add result juzhen is \n");
   output(Q) ;
}










 


