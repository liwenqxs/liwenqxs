#include<stdio.h> 
#include<stdlib.h>
typedef struct polyn{
	int coef;
	int expn;
	struct polyn *next;
}polyn;

void input(polyn **L)
{
	polyn  *p,*h;
	int n;
	int m;
	*L=(polyn*)malloc(sizeof(polyn));
	(*L)->coef=0.0;
	(*L)->expn=-1;
	(*L)->next=NULL;
	h=(*L);
	printf("输入系数与指数以0 0结束\n");
	scanf("%d%d",&m,&n);
	while(m!=0)
	{
	    p=(polyn *)malloc(sizeof(polyn));	
	    p->next=NULL;	
		p->coef=m;
		p->expn=n;
		h->next=p;
		h=p;
	    scanf("%d%d",&m,&n);
   }
   h->next=NULL;
 }
 void substruct(polyn *La,polyn *Lb,polyn **Lc)  //多项式相减 
 {
 polyn *pa,*pb,*pc,*q;
 pa=La->next;
 pb=Lb->next;
 (*Lc)=(polyn *)malloc(sizeof(polyn));
 pc=(*Lc); 
 pc->next=NULL;
 while(pa&&pb)
 {
 	if(pa->expn<pb->expn)   //当A的指数小于B的指数 
 	{
      q=(polyn *)malloc(sizeof(polyn));
 	  q->expn=pa->expn; 
 	  q->coef=pa->coef;
 	  q->next=NULL;
      pc->next=q;
      pc=q;
      pa=pa->next;
    }
	 else if(pa->expn>pb->expn)   //当A的指数大于B的指数 
	 {
	  q=(polyn *)malloc(sizeof(polyn));
 	  q->expn=pb->expn;
 	  q->coef=pb->coef;
 	  q->next=NULL;
      pc->next=q;
      pc=q;
      pb=pb->next;
	 }
	 else 
	 {
	 	if(pa->coef-pb->coef!=0)     
	 	{	 	   q=(polyn *)malloc(sizeof(polyn));
 	       q->expn=pa->expn; 
 	       q->coef=pa->coef-pb->coef;
 	       q->next=NULL;
 	        pc->next=q;
            pc=q;
        	pa=pa->next;
		 	pb=pb->next;
		 }
		 else
		 {
		 	pa=pa->next;
		 	pb=pb->next;
		  }
        }
    }
		 
    while(pb)
		 {
          q=(polyn *)malloc(sizeof(polyn));
 	      q->expn=pb->expn;
 	      q->coef=-pb->coef;
 	      q->next=NULL;
          pc->next=q;
          pc=q;
	     pb=pb->next;
         }	
         while(pa)
		 {
           
           q=(polyn *)malloc(sizeof(polyn));
 	       q->expn=pa->expn; 
 	       q->coef=pa->coef;
 	       q->next=NULL;
           pc->next=q;
           pc=q;
           pa=pa->next;
        }
         pc->next=NULL;  
 }
void add(polyn *La,polyn *Lb,polyn **Lc)   //多项式相加 
{
 polyn *pa,*pb,*pc,*q;
 pa=La->next;
 pb=Lb->next;
 (*Lc)=(polyn *)malloc(sizeof(polyn));
 pc=(*Lc); 
 pc->next=NULL;
 while(pa&&pb)
 {
 	if(pa->expn<pb->expn)     //当a的指数小于b的指数 ，直接插入链表 
 	{
      q=(polyn *)malloc(sizeof(polyn));
 	  q->expn=pa->expn; 
 	  q->coef=pa->coef;
 	  q->next=NULL;
      pc->next=q;
      pc=q;
      pa=pa->next;
    }
	 else if(pa->expn>pb->expn)  //当a的指数大于b的指数 ，直接插入链表 
	 {
	  q=(polyn *)malloc(sizeof(polyn));
 	  q->expn=pb->expn;
 	  q->coef=pb->coef;
 	  q->next=NULL;
      pc->next=q;
      pc=q;
      pb=pb->next;
	 }
	 else 
	 {
	 	if(pa->coef+pb->coef!=0)  //当a的指数与b的指数相加不等于0，则指数相加之后插入 
	 	{
	 	   q=(polyn *)malloc(sizeof(polyn));
 	       q->expn=pa->expn; 
 	       q->coef=pa->coef+pb->coef;
 	       q->next=NULL;
 	        pc->next=q;
            pc=q;
        	pa=pa->next;
		 	pb=pb->next;
		 }
		 else
		 {
		 	pa=pa->next;
		 	pb=pb->next;
		  }
        }
    }
		  
          while(pb)
		 {
          q=(polyn *)malloc(sizeof(polyn));
 	      q->expn=pb->expn;
 	      q->coef=pb->coef;
 	      q->next=NULL;
          pc->next=q;
          pc=q;
	     pb=pb->next;
         }	
         while(pa)
		 {
           
           q=(polyn *)malloc(sizeof(polyn));
 	       q->expn=pa->expn; 
 	       q->coef=pa->coef;
 	       q->next=NULL;
           pc->next=q;
           pc=q;
        	pa=pa->next;
        }
         pc->next=NULL;  
 }

void nizhi(polyn *L)
{
    polyn *p,*q;
    p=L->next;
    L->next=NULL;
    q=p;
    while(q)
    {
       p=p->next;
       q->next=L->next;
       L->next=q;
       q=p;
      
    }
}
void output(polyn *h){
    polyn *p;
    p=h->next;
	while(p)
	{
		if(p->coef>0&&p!=h->next)
		printf(" + ");
		printf("%dX^%d",p->coef,p->expn);
		p=p->next;
	}
	printf("\n");
}

int main()
 {
 	polyn *La,*Lb,*Lc,*Ld;
 	printf("创建A多项式 ：\n");
 	input(&La);
 	output(La);
 	printf("创建B多项式：\n");
 	input(&Lb);
 	output(Lb);
 	printf("A,B相减的结果 ：\n");
 	substruct(La,Lb,&Ld);
 	output(Ld);
 	printf("A,B相加的结果：\n");
 	add(La,Lb,&Lc);
 	output(Lc);
	printf("相减之后逆置的结果：\n"); 
 	nizhi(Ld);
 	output(Ld);
    
 }
