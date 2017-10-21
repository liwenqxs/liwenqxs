#include<stdio.h>
#include<math.h> 
#include<stdlib.h>
#include<string.h> 
#define ok 1
#define MAXSIZE 20
#define f 100
#define OK 1
#define error 0
typedef struct BiTNode
  {
	char data;
	struct BiTNode *lchild,*rchild;
  }bitree;
  int flag = 1;
void creatbitree(bitree* &T)
{   char a;
   scanf("%c",&a);
   if(a=='#') 
   T=NULL;
   else
     {
     	T=(BiTNode *)malloc (sizeof(BiTNode));
     	
     	creatbitree(T->lchild);
     	  T->data=a;
     	creatbitree(T->rchild);
     }
     
}
void judge(bitree *T,bitree *M)
{
	if(T&&!M)  
	flag = 0;
	else if(!T&&M)
	flag = 0;
	else if(T&&M)
	{
		judge(T->lchild,M->lchild);
		judge(T->rchild,M->rchild);
	}
		
}

int main ()
{   int m;
	bitree *T,*M;
	printf("ÊäÈëÊ÷\n") ;  //ab##c## 
	creatbitree(T);
   scanf("%c",&m);
	printf("ÊäÈëÊ÷\n") ;  //abd##e##c##
    creatbitree(M);
   judge(T,M);
   if(flag) 
 printf("the tree is same \n");
	else
printf("the tree is different\n");
}
	









