#include <stdio.h> 
#include <stdlib.h> 
#define f 100 
typedef struct list 
{ int *elem; 
  int length; 
  int listsize; 
} sqlist;  
 
 int initsqlist (sqlist *L)
{ 
    L->elem=(int *)malloc(f*sizeof(int));
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
  for(i=0;i<L->listsize&&k!=0;i++)  //������0���� 
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

void deletel(sqlist *L)
{
   int i,j;
   for (i=0,j=1;j<L->length;j++)
   
   	if(L->elem[i]!=L->elem[j])
   	L->elem[++i]=L->elem[j];
   	L->length=i+1;   
   
}
 void inverse(sqlist *L)   //ת�� 
{
   int i,j,temp;
   for(i=0,j=L->length-1;i<j;i++,j--)
   {
   		temp = L->elem[i];
   		L->elem[i] = L->elem[j];
   		L->elem[j] = temp;
   }
}
int main()
{
  sqlist L;
initsqlist (& L); 
printf("�����������������ݣ���0����\n") ;
   input(&L);
   printf("���������Ϊ\n");
  output(L);
  printf("ɾ��ֵ��ͬ�ģ�Ȼ�����\n") ;
  deletel(&L);
  output(L);
  printf("���ú����\n");
  inverse(&L);
  output(L);
return 0;
}
	
	
  






	

