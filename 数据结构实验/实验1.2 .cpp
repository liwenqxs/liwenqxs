#include <stdio.h> 
#include <stdlib.h> 
#define f 100 
#define listincrement 10 
 
typedef struct  
{ int *elem; 
  int length; 
  int listsize; 
} sqlist;  

int initsqlist (sqlist *L) 
{
   L->elem=(int *) malloc(f*sizeof(int));
	if(!L->elem) 
		exit(0); 
	L->length=0;  
    L->listsize=f;
	return 0; 
} 

void input(sqlist *L)
{
  int i,k;
  scanf("%d",&k); 
  for(i=0;i< L->listsize&&k!=0;i++)
  {
    L->elem[i]=k; 
         L->length++;  
         scanf("%d",&k); 
  }
}
void output(sqlist L)
{   
    int i;
   for(i=0;i<L.length;i++)
    printf("%d  ",L.elem[i]);
    printf("\n");
}

void add(sqlist  La,sqlist Lb,sqlist *Lc)
{
	int i,j;
	int k;
	i=La.length-1;
	j=Lb.length-1;k=0;
	while(i>=0&&j>=0)
	{
	if(La.elem[i]<Lb.elem[j])	
	{
		Lc->elem[k++]=Lb.elem[j--];
	}
	else
		Lc->elem[k++]=La.elem[i--];
	}
    while(j<0&&i>=0)    // a的长度比b长 
	Lc->elem[k++]=La.elem[i--];
	while(i<0&&j>=0)    // b更长 
		
		Lc->elem[k++]=Lb.elem[j--];
		Lc->length=k;
	}
void deletel(sqlist *L)
{
   int i,j;
   for (i=0,j=1;j<L->length;j++)
   
   	if(L->elem[i]!=L->elem[j])
   	L->elem[++i]=L->elem[j];
   	L->length=i+1;   
}
	int main()
	{
		sqlist La,Lb,Lc;
		initsqlist (&La);
		printf("建立表a以0结束\n"); //表a和b都单调 增加 
		input(&La);
		initsqlist (&Lb);
		printf("建立表b以0结束\n");
		input(&Lb);
	    initsqlist (&Lc);
	    add(La,Lb,&Lc);
	    printf("表a为\n");
	  	output(La);
	  	printf("表b为\n");
	   	output(Lb);
	   	printf("合并的递减的表c为\n");
	   	deletel(&Lc);
	    output(Lc) ;
	   
    }
	
	
	
	
	
	

