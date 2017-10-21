#include<stdio.h>
#include<math.h> 
#include<stdlib.h>
#include<string.h> 
#define ok 1
#define MAXSIZE 20
#define f 100
#define OK 1
#define error 0
#define overflow 0

typedef struct BiTNode
  {
	char data;
	struct BiTNode *lchild,*rchild;
  }bitree;
  typedef bitree* Elemtype;
typedef struct
  {
  	int *base;
  	int *top;
  	int stacksize;
  } stack; 
  int Num=0;
  int m=0;
void Initstack(stack *L)         //建立栈 
{
	
	L->base=(int*)malloc(f*sizeof(int)); 
	L->top=L->base;
	L->stacksize=f; 
}

int stackEmpty (stack L)      //判断栈是否为空 
{
	if(L.base==L.top) return error;
	else return OK;
}
int GetTop(stack *L,char *e)      //获得栈顶元素 
{
	if(stackEmpty(*L))  {
	    *e=*(L->top-1);
	    return OK;}
	else return error;                        
}   
int Push (stack *L,char e)     //往栈里面插入元素 
{
	if((L->top-L->base)>=L->stacksize) {
		L->base=(int *)realloc (L->base,(L->stacksize+f)*sizeof(int));
       	L->top=L->base+L->stacksize;
	    L->stacksize+=f;
     }
    *(L->top)=e;
    L->top++;
    return OK;
}        
int Pop(stack *L,char *e)       // 出栈 
{
	if(stackEmpty(*L)) 
	 {
	L->top--;
	*e=*(L->top);
	return OK;}	
	else return error; 	                        
}   
typedef struct QNode
{
	Elemtype data;
	struct QNode *next;
}pre;
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
int enqueue(queue *Q,bitree *e)
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
	if(Q.front==Q.rear)
	return 1;
	else
	return 0;
}
int dequeue(queue *Q, Elemtype  *e)
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
 void creatbitree(bitree * &T)  //先序输入，后序建树 
{   char a;
   scanf("%c",&a);
   if(a=='#') 
   T=NULL;
   else
     {
     	T=(BiTNode *)malloc (sizeof(BiTNode));
        creatbitree(T->lchild);
     	creatbitree(T->rchild);
     	T->data=a;
     }
     
}
void preorder(bitree *T)
{
 if(T)
    {
       printf("%c",T->data);
       preorder(T->lchild);
       preorder(T->rchild);
    }
	
}
void inorder(bitree *T)
{
	if(T)
	 {
       inorder(T->lchild);
       printf("%c",T->data);
       if(T->lchild&&T->rchild)
       Num++;
       else if(T->lchild||T->rchild)
       m++;
       inorder(T->rchild);
    }
		
}
void postorder(bitree *T)
{
	if(T)
	 {
       postorder(T->lchild);
       postorder(T->rchild);
       printf("%c",T->data);
       
    }
	
}
void NRpreorder(bitree *T)  //先序非梯归遍历 
{   
    bitree *stack[f], *p;
    int top = -1;
    if (T != NULL)// 根节点入栈 
    {
       top++;
       stack[top] = T;
        while (top > -1) // 栈不空
        {
            p = stack[top];
            top--;       // 出栈并访问该节点 
            printf("%c ", p->data);
          
           if (p->rchild != NULL)  //右孩子入栈 
            {
                top++;
                stack[top] = p->rchild;
            }
          
           if (p->lchild != NULL) // 左孩子入栈 
            {
                top++;
                stack[top] = p->lchild;
            }
        }
        printf("\n");
    }
}
int max(int a,int b) 
{
	if(a<b)
	return b;
	else
	return a;
	
}

int higth(bitree *T) //求深度 
{  
 if (T==NULL)  
    return 0;
   else 
  return max(higth(T->lchild),higth(T->rchild))+1;
} 
void Leaf(bitree *T, int *count)
{  if (T)
  {
     Leaf(T->lchild,count);   //左子树 递归 
     if (!T->lchild && !T->rchild) 
      (*count)++;
     Leaf(T->rchild,count);  //右子树 
   }
}
void change(bitree *T)   //交换左右子树 
{  bitree *P;
   if (T) 
   {
     change(T->lchild);
     change(T->rchild);
     P=T->lchild; 
     T->lchild=T->rchild;
     T->rchild=P;
   }
}
void leverorder(bitree *T)
{  
  bitree *p;
   queue Q;
   bitree *e;
	if(!T)
	exit;
	initqueue(&Q);
	p=T;
	printf("%c" ,T->data);
	enqueue(&Q,p);
	while(!queueempty(Q))
	 {
	 	dequeue(&Q,&e);
	 	if(e->lchild)
	 	{
	 		printf("%c",e->lchild->data);
	 		enqueue(&Q,e->lchild);
	 	}
	 	if(e->rchild)
	 	{
	 		printf("%c",e->rchild->data);
	 		enqueue(&Q,e->rchild);
	 	}
	 }
   }


int main()
{
    bitree *T; 
	int depth;
	int count=0;
	int flag=1,select;
	printf("please input number(输入树，列如ab##c## )\n"); //输入树，列如ab##c## 
	creatbitree(T);
     int n;
    while(flag) 
	 {
	 	printf("please input the select\n");
	 	printf("1.preorder visit \n");
	 	printf("2.inorder visit \n");
	 	printf("3.postorder visit\n");
	    printf("4.NRpreorder visit \n");//先序非梯归遍历
		printf("5.tree higth \n");
		printf("6.leaf number\n");
		printf("7.change tree\n"); 
		printf("8.leverorder tree\n"); 
		scanf("%d",&select);
		switch(select) 
		{
			case 1: printf("the preorder visit bitree is\n");
			       
			        preorder(T) ;
			        break;
			        
			case 2: Num = 0;
			        m=0;
			        printf("the inorder visit bitree is\n") ;
			         
                    inorder (T)	;
                    printf("\nNode'sshuang Num: %d\n",Num);
                    printf("\nNode's dan Num: %d\n",m);
					break;
		    case 3: printf("the postorder visit bitree is\n") ;
		     
                    postorder (T);
					break;
		
			case 4: printf("the NRpreorder visit bitree is\n") ;
                    NRpreorder (T)	;
					break; 
			case 5:  printf("the tree higth is\n") ;
                     depth=higth(T);
                     printf("%d",depth);
					 break;	
			case 6: printf("the leafnumber is\n");
			        Leaf(T,&count);
                   printf("%d",count);
                   printf("\n");
					break;
		    case 7:printf("the change is\n");
		         change(T);	
			      preorder(T) ;
				   break;
			case 8:printf("the leverorder is\n");
		           leverorder(T);
				   break;	   		
		}
		   printf("\n");
     }
}
	 	
	 	
	 	
	 	
	 	
	 	
	 	
	 	

	
	
	
	 
 
 


