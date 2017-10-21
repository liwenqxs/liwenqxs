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
	printf("����ϵ����ָ����0 0����\n");
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
 void substruct(polyn *La,polyn *Lb,polyn **Lc)  //����ʽ��� 
 {
 polyn *pa,*pb,*pc,*q;
 pa=La->next;
 pb=Lb->next;
 (*Lc)=(polyn *)malloc(sizeof(polyn));
 pc=(*Lc); 
 pc->next=NULL;
 while(pa&&pb)
 {
 	if(pa->expn<pb->expn)   //��A��ָ��С��B��ָ�� 
 	{
      q=(polyn *)malloc(sizeof(polyn));
 	  q->expn=pa->expn; 
 	  q->coef=pa->coef;
 	  q->next=NULL;
      pc->next=q;
      pc=q;
      pa=pa->next;
    }
	 else if(pa->expn>pb->expn)   //��A��ָ������B��ָ�� 
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
void add(polyn *La,polyn *Lb,polyn **Lc)   //����ʽ��� 
{
 polyn *pa,*pb,*pc,*q;
 pa=La->next;
 pb=Lb->next;
 (*Lc)=(polyn *)malloc(sizeof(polyn));
 pc=(*Lc); 
 pc->next=NULL;
 while(pa&&pb)
 {
 	if(pa->expn<pb->expn)     //��a��ָ��С��b��ָ�� ��ֱ�Ӳ������� 
 	{
      q=(polyn *)malloc(sizeof(polyn));
 	  q->expn=pa->expn; 
 	  q->coef=pa->coef;
 	  q->next=NULL;
      pc->next=q;
      pc=q;
      pa=pa->next;
    }
	 else if(pa->expn>pb->expn)  //��a��ָ������b��ָ�� ��ֱ�Ӳ������� 
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
	 	if(pa->coef+pb->coef!=0)  //��a��ָ����b��ָ����Ӳ�����0����ָ�����֮����� 
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
 	printf("����A����ʽ ��\n");
 	input(&La);
 	output(La);
 	printf("����B����ʽ��\n");
 	input(&Lb);
 	output(Lb);
 	printf("A,B����Ľ�� ��\n");
 	substruct(La,Lb,&Ld);
 	output(Ld);
 	printf("A,B��ӵĽ����\n");
 	add(La,Lb,&Lc);
 	output(Lc);
	printf("���֮�����õĽ����\n"); 
 	nizhi(Ld);
 	output(Ld);
    
 }
