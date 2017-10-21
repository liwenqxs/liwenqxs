#include<stdio.h> 
#include<stdlib.h>
#define FALSE 0
#define TRUE 1
typedef struct Node
{
	int data;
	struct Node *lchild,*rchild;
}bitNode,*bitree;
int search(bitree T,int key,bitree f,bitree *p) 
//ָ��fָ��T��˫�ף���ֵΪNULL�������ҳɹ�pָ������ڵ㣬���ɹ���ָ��·�������һ���ڵ� 
{
	if(!T) 
	{
	 *p=f;
	return FALSE;
    }
    else if(key==T->data)
    {
      *p=T;
      return TRUE;
    }
    else if(key<T->data)
    {
    	return search(T->lchild, key, T, p) ;
    }
    else
    {
    return search(T->rchild, key, T, p) ;	
    }
	
} 
int insertbitree(bitree *T,int key)
{
	bitree p,s;
	if(!search(*T,key,NULL,&p))
  { 
		s=(bitree)malloc(sizeof(bitNode));
		s->data=key;
		s->lchild=s->rchild=NULL;
	  if(!p)
	  {
		*T=s;
	  }
	else if(key<p->data)
	  {
		p->lchild=s;
	  }
	else
	  {
	p->rchild=s;	
	  }
	return TRUE;
 }
   else  //�������Ѿ��иýڵ㣬�����ٲ��� 
 return FALSE;
 
}

             
int deletel(bitree *p,bitree g) 
{
	bitree q,s;
	if((*p)->lchild==NULL&&(*p)->rchild==NULL)
	{
		if(g->lchild==*p)
		g->lchild=NULL;
		else
		g->rchild=NULL;
		free(*p);
		*p=NULL;
	}
	else
	{
	
    	if((*p)->rchild==NULL)    //���ֻ�������� 
    	{
	 	s=(*p)->lchild;
		(*p)->data=s->data;
		(*p)->lchild=s->lchild;
		(*p)->rchild=s->rchild;
		free(s);
		s=NULL;
	}
	else if((*p)->lchild==NULL)   //���ֻ�������� 
	{ 
	  	s=(*p)->rchild;
		(*p)->data=s->data;
		(*p)->lchild=s->lchild;
		(*p)->rchild=s->rchild;
		free(s);
		s=NULL;
	} 
    else
	 {
	  q=*p;
	  s=(*p)->lchild;
	  while(s->rchild)
	  {
	  	q=s;
	   s=s->rchild;	
	  }
	  (*p)->data=s->data;
	   if(q!=(*p))
	  q->rchild=s->lchild;
	  else
	  q->lchild=s->lchild;
	  free(s);
	  s=NULL;
    }
}
  return TRUE;
}
int deletebitree(bitree *T,int key,bitree *p)
{
	
	if(!*T)
	{
		return FALSE;
	}
	else
	{
		*p=*T;
		if(key==(*T)->data)
		return deletel(T,*p);
		else if(key<(*T)->data)
		return deletebitree(&(*T)->lchild,key,p); //���������ݹ���� 
		else if(key>(*T)->data)
		return deletebitree(&(*T)->rchild,key,p); //���������ݹ���� 	
	}
}
int deleteyouput(bitree *T)
{   
    int key;
    bitree p;
    	printf("\n");
	printf("please input the key you want delete\n");
	scanf("%d",&key);
	deletebitree(T,key,&p);
}
void creatbitree(bitree *T)
{
	printf("\n");
	int key;
	*T=NULL;
	printf("please input num end with 0\n");
	scanf("%d",&key);
	while(key!=0)
	{
		insertbitree(T,key);
		scanf("%d",&key);
	}
}
void inorder(bitree T)
{
	if(T)
	 {
       inorder(T->lchild);
       printf("%3d",T->data);
       inorder(T->rchild);
    }
		
}

int main()         //���� 1 3 2 5 4 7 6 8 0 
{
	bitree T,p;
    int key;
    creatbitree(&T)	;
    printf("\n");
    inorder(T);
    deleteyouput(&T);
    printf("\n");
    inorder(T); 
}


	
	
	
	


