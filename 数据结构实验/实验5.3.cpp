#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef struct bitnode
{
	char date;
	struct bitnode *lchild,*rchild;
}biNode,*bitree;
typedef bitree elem; 
typedef struct 
{
	elem *base;
    elem *top;
	int stacksize;
 } sqstack;
 void initstack(sqstack *L)
 {
 	L->base=(elem *)malloc(STACK_INIT_SIZE*sizeof(elem));
 	if(!L->base)
 	exit;
 	L->top=L->base;
	L->stacksize=STACK_INIT_SIZE; 
 }
 void gettop(sqstack L,elem *e)
 {
 	if(L.top==L.base)
 	printf("stack is emputy\n");
 	else
 	*e=*(L.top-1);
  } 
  void push(sqstack *L,elem e)
  {
  	if(L->top-L->base>=L->stacksize)
  	{
  	L->base=(elem *)realloc(L->base,(L->stacksize+STACKINCREMENT)*sizeof(elem));
  	if(!L->base)
  	exit;
  	L->top=L->base+L->stacksize;
  	L->stacksize+=STACKINCREMENT;
  }
  *(L->top++)=e;
}
  void pop(sqstack *L,elem *e)
  {
  	if(L->top!=L->base)
  	*e=*(--L->top);
  	
  }
 void CreatebiTree(bitree *T)
 { 
     sqstack L;
     int Flag;
    initstack(&L);
   bitree e,p;
    char ch;
   *T=NULL;
   scanf("%c",&ch);
   while (ch!='#') 
   {    
     switch(ch) 
	 {    
       case '(':{ push(&L,p); Flag =1; 
                       break;}       
       case ',':{ Flag=0; break; }       
       case ')': { pop(&L,&e); break;}
	   default:{ p=(bitree )malloc(sizeof(biNode)) ;
              p->lchild =p->rchild = NULL;
              p->date=ch;  
              if (!(*T))  
                *T = p ; 
              else { gettop(L,&e);
                     if (Flag)
                       e->lchild=p;
                     else 
                       e->rchild=p;
                   }
            }
        }
     scanf("%c",&ch); 
   }
 }
 void perorder(bitree T,int *n) 
	{   
	  if  (T!=NULL)
    	 {
    	printf("%c",T->date);            // 访问T的根结点
         (*n) ++;	
		perorder(T->lchild,n);  // 遍历T的左子树
        perorder(T->rchild,n);  //遍历T的右子树
                
         }
    	
    	
	}
int main()
{
	
	int n=0;
	bitree T;
	printf("输入c(e(i,j),f(,g(k,h)))# \n ") ;
	CreatebiTree(&T);  //输入//c(e(i,j),f(,g(k,h)))# 
	printf("先序遍历结果\n");
	perorder(T,&n);
	printf("\n") ;
    printf("结点数：%d\n",n);
}      
            










