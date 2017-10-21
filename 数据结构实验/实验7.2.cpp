#include<stdio.h>
#include<stdlib.h>
#define NULLKEY 100
#define f 13
#define SUCCESS 1
#define UNSUCCESS 0
#define DUPLICATE 0

typedef struct
{
	int *elem;
	int count;
	int sizeindex; 
}hashtable;

int inithashtable(hashtable *H)
{  
   int i;
   H->elem=(int*)malloc(f*sizeof(int));
     H->count=0;
     H->sizeindex=f;
   if(!H->elem)
   return -1;
   for(i=0;i<f;i++)
   H->elem[i]=NULLKEY;
   return 0;
}
int Hash(int key)	
{
	return key%f;
}
int searchhash(hashtable H,int k,int *p)	
{
    *p=Hash(k);
	while(H.elem[*p]!=NULLKEY&&k!=H.elem[*p])
	*p=(*p+1)%f;
	 
	 if(k==H.elem[*p])
	 return SUCCESS;
	 else 
	 return UNSUCCESS;
}
int inserthash(hashtable *H,int key)
{   int p; 
    if(searchhash(*H,key,&p))
    return DUPLICATE;
    else
    {
    	H->elem[p]=key;
    	++H->count;
    	return 1;
    }
}
void output(hashtable H)
{
	int i;
	for(i=0;i<f;i++)
	if(H.elem[i]!=NULLKEY)
	printf("%d   address=%d\n",H.elem[i],i);
}
int main()
{
	hashtable H;  
	int key,n,i;
	
    inithashtable(&H);   //36 21 45 17 29 55 35 61 40 78 0 
    printf("please input the number end with 0(36 21 45 17 29 55 35 61 40 78 0 )\n");
    scanf("%d",&n);
	for(i=0;i<f&&n!=0;i++)
	{
	inserthash(&H,n);
	scanf("%d",&n);
    }
	output(H);	
}



















