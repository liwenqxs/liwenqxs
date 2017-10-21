#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define maxsize 55000
#define ok 1
#define f 40000
typedef struct
{
	int *elem;
	int length;
	int listsize;
}sqlist;
int initsqlist(sqlist *L)
{
	L->elem=(int*)malloc(maxsize*sizeof(int));
	L->length=0;
	L->listsize=maxsize;
	return ok;
}
int creatsqlist(sqlist *L)      //生成随机数 
{
	int i,math; 
	srand(time(NULL));
	printf("please input the sqlist length\n");
	scanf("%d",&L->length);
	for(i=1;i<=L->length;i++)
	L->elem[i]=math=1+(int)rand()%100;	
	 printf("产生的随机数为100以内的###########################\n");
	for(i=1;i<=L->length;i++)
	printf("%8d",L->elem[i]);
	 printf("\n产生的随机数为100以内的###########################\n");
	return ok;
}
void direct(sqlist *L)  //直接插入排序 
{   int i,j;
	for(i=2;i<=L->length;i++) 
	if(L->elem[i]<L->elem[i-1])
    {
    L->elem[0]=L->elem[i];
    L->elem[i]=L->elem[i-1];
	for(j=i-2;L->elem[0]<L->elem[j];j--)
	L->elem[j+1]=L->elem[j];           //记录后移 ，插到正确位置 
	L->elem[j+1]=L->elem[0];
	}

}
void zheban(sqlist *L)
{   
  int high,low,i,m,j; 
  
  for(i=2;i<=L->length;i++)
  {
	L->elem[0]=L->elem[i];
	low=1;high=i-1;
	while(low<=high)
	 {
	  m=(low+high)/2;           //折半 
	  if(L->elem[0]<L->elem[m])	
	  high=m-1;
	  else
	  low=m+1;
	 }
	for(j=i-1;j>=high+1;--j)
	L->elem[j+1]=L->elem[j];
	L->elem[high+1]=L->elem[0];
  }

}
int partition(sqlist *L,int low,int high)
{   int pivotkey;
	L->elem[0]=L->elem[low];
	pivotkey=L->elem[low] ;
	while(low<high)
	{
		while(low<high&&L->elem[high]>=pivotkey)
		--high;
		L->elem[low]=L->elem[high]; 
		while(low<high&&L->elem[low]<=pivotkey)
		++low;
		L->elem[high]=L->elem[low];
	}
	L->elem[low]=L->elem[0];
	return low;
}
void squick(sqlist*L,int low,int high)
{   int pivotloc;
    if(low<high)
    {
    pivotloc=partition(L,low,high);
    squick(L,low,pivotloc-1);
    squick(L,pivotloc+1,high);
    }
}
void squicksort(sqlist *L)
{
	squick(L,1,L->length);
}
void output(sqlist L)
{  
  int i;
  for(i=1;i<=L.length;i++)
  printf("%6d",L.elem[i]);
}
void shellinsert(sqlist *L,int dk)    //对顺序表L做一趟希尔排序 
{    int i,j;                       
	for(i=dk+1;i<=L->length;++i)
	if(L->elem[i]<L->elem[i-dk])
	{
		L->elem[0]=L->elem[i];
		for(j=i-dk;j>0&&(L->elem[0]<L->elem[j]);j=j-dk)
		L->elem[j+dk]=L->elem[j];
		L->elem[j+dk]=L->elem[0];
	}
}
void shellsort(sqlist *L,int data[],int t)
{   int k;
	for(k=0;k<t;++k)
	{
	shellinsert(L,data[k]);
	}
}

void Heapadjust(sqlist*L,int s,int m)
{  
   int rc,j;
  rc=L->elem[s];
  for(j=2*s;j<=m;j=j*2)
  { 
  	if(j<m&&(L->elem[j]<L->elem[j+1]))
  	++j;
  	if(rc>L->elem[j])
  	break;
  	L->elem[s]=L->elem[j];
  	s=j;
  }	
  L->elem[s]=rc;
}
void Heapsort(sqlist *L) 
{    int m,i; 
	for(i=(L->length)/2;i>0;--i)
	Heapadjust(L,i,L->length);
	for(i=L->length;i>1;--i)
	{
	 m=L->elem[1];
	 L->elem[1]=L->elem[i];
	 L->elem[i]=m;	
	 Heapadjust(L,1,i-1); 
	}

} 

int main()
{   
  int low,high,t;
    int data[f];
    clock_t start ,finish,end; 
    sqlist L;
    initsqlist(&L);
	creatsqlist(&L);  //五种排序都是用同一个随机数 
	start=clock();
	direct(&L);
	printf("\n");
	printf("直接排序结果\n");
	output(L);
	finish=clock();
  end=finish-start;
  printf("\n排序时间===============================:%d",end);
	start=clock();
    zheban(&L);
    printf("\n");
    printf("折半排序结果\n");
    output(L);
     finish=clock();
  end=finish-start;
  printf("\n排序时间=================================:%d",end);
    start=clock();
   squicksort(&L); 
     printf("\n");
     printf("快速排序结果\n");
     output(L);
  finish=clock();
  end=finish-start;
  printf("\n排序时间==============================:%d",end);
     start=clock();
     shellsort(&L,data,t);
      printf("\n");
     printf("希尔排序结果\n");
     output(L);
     finish=clock();
  end=finish-start;
  printf("\n排序时间============================:%d",end);
     start=clock();
    Heapsort(&L); 
      printf("\n");
     printf("堆排序结果\n");
     output(L);
    finish=clock();
  end=finish-start;
  printf("\n排序时间============================:%d",end);
}
 
