#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define f 100
#define OK 1
#define error 0
typedef struct {
	 char *base;  
	 char *top;
	 int stacksize;
}stack;   
void initStack(stack *L)         //����ջ 
{
	L->base=(char*)malloc(f*sizeof(char)); 
	L->top=L->base;
	L->stacksize=f; 
}

int stackEmpty (stack L)      //�ж�ջ�Ƿ�Ϊ�� 
{
	if(L.base==L.top) return error;
	else return OK;
}
int GetTop(stack *L,char *e)      //���ջ��Ԫ�� ����e���� 
{
	if(stackEmpty(*L))  {
	    *e=*(L->top-1);
	    return OK;}
	else return error;                        
}   
int Push (stack *L,char e)     //��ջ�������Ԫ�� 
{
 *(L->top)=e;
    L->top++;
    return OK;
}        
int Pop(stack *L,char *e)       // ��ջ 
{
	if(stackEmpty(*L)) 
	 {
	L->top--;
	*e=*(L->top);
	return OK;}	
	else return error; 	                        
}   
     char Prior[7][7]= {'>','>','<','<','<','>','>',
	                  '>','>','<','<','<','>','>',
	                  '>','>','>','>','<','>','>',
	                  '>','>','>','>','<','>','>',
	                  '<','<','<','<','<','=',' ',
	                  '>','>','>','>',' ','>','>',
	                  '<','<','<','<','<',' ','=', }; 
					              
char ope[7]={'+','-','*','/','(',')','#'};
int main()
{
}






























