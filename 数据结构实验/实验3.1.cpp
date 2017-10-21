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
void initStack(stack *L)         //建立栈 
{
	L->base=(char*)malloc(f*sizeof(char)); 
	L->top=L->base;
	L->stacksize=f; 
}

int stackEmpty (stack L)      //判断栈是否为空 
{
	if(L.base==L.top) return error;
	else return OK;
}
int GetTop(stack *L,char *e)      //获得栈顶元素 ，用e返回 
{
	if(stackEmpty(*L))  {
	    *e=*(L->top-1);
	    return OK;}
	else return error;                        
}   
int Push (stack *L,char e)     //往栈里面插入元素 
{
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






























