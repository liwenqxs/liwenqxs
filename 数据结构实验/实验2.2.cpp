#include<stdio.h> 
#include<stdlib.h>
 typedef struct LNode
{
     int date;
	struct LNode *next;
}LinkList;
 void input(LinkList *L)
{
 int a;
LinkList  *p,*q;
 
L->next=NULL;
p=q=L;
scanf("%d",&a);
while(a!=0) 
{
p=(LinkList *)malloc( sizeof(LNode));
p->date=a;
q->next=p;	
q=p;
scanf("%d",&a);
}
p->next=NULL;
}
int judge(LinkList *L)
{
	LinkList *p;
	p=L->next;
	int flag = 1;
	while(p->next)
	{	
		if(	(p->date)<(p->next->date))
		{
		flag = 0;
		break;
}
		p=p->next;
	
}
	return flag;

}
void output(LinkList *L)
 {
	 LinkList *p;
	p=L->next;
	
	while(p!=NULL)
	
	{
        printf("%d ",p->date);
		p=p->next;
	}

printf("\n");

}
 void delectsame(LinkList *L)

{ 
   LinkList *p,*q;
	p=L->next;
	while(p->next)
	{
		if((p->date)==(p->next->date)) 
		{
			q=p->next;
	    	p->next=p->next->next;
	    	free(q);
		}
		else
			p=p->next;	
	}
}

void inver(LinkList *L) 
{

LinkList *p=L->next,*q=L->next;

q=q->next;

p->next=NULL;

p=q;

while(p!=NULL)

{

q=q->next;

p->next=L->next;

L->next=p;

p=q;

}

}
main()
{
int flag;	
LinkList *L;
L=(LinkList *)malloc( sizeof(LNode));
printf("输入数据以0结束\n") ;
 input(L) ; 
 if(judge(L))
 {
 output(L);
delectsame(L);

inver(L);

output(L);
}
else 
printf("请输入递减的数\n");
}
	
 



	



 



	






