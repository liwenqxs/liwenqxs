#include<stdio.h>
#include<stdlib.h>
#define f 100
#define ERROR 0
#define OK 1

int  maze[9][10]= {0,0,0,0,0,0,0,0,0,0,
                  0,1,1,0,1,1,1,0,1,0,
                  0,1,1,0,1,1,1,0,1,0, 
                  0,1,0,0,0,1,1,1,1,0,
                  0,1,1,1,0,1,1,1,1,0,
                  0,1,0,1,1,1,0,1,1,0,
                  0,1,0,0,0,1,0,0,1,0,
                  0,0,1,1,1,1,1,1,1,0,
                  0,0,0,0,0,0,0,0,0,0,
                  };       
typedef struct
{
	int x;   //横坐标 
	int  y;	 
	
}postype;
 
 typedef struct
{
	int curpos;       //通道快序号 
	postype seat;     //坐标位置 
	int di;            //方向 
}Elemtype;

typedef struct 
  {         
	 Elemtype  *base;  
	  Elemtype  *top;
	 int stacksize;
  }stack;                        

void initstack(stack *L)         //建立栈 
{
	
	L->base=( Elemtype *)malloc(f*sizeof( Elemtype )); 
	L->top=L->base;
	L->stacksize=f; 
}

int stackEmpty (stack L)      //判断栈是否为空 
{
	if(L.base==L.top) return ERROR;
	else return OK;
}
int GetTop(stack *L, Elemtype *e)      //获得栈顶元素 
{
	if(stackEmpty(*L))  
	{
	 *e=*(L->top-1);
	  return OK;
	}
	else return ERROR;                        
}   
int Push (stack *L, Elemtype e)     //e加入栈 
{
	
    *(L->top)=e;
    L->top++;
    return OK;
}        
int Pop(stack *L, Elemtype  *e)       // 出栈 
{
	if(stackEmpty(*L))  
	{
	L->top--;
	 *e=*(L->top);
	return OK;
	}	
	else return ERROR; 	                        
} 
postype Nextpos(postype step,int n)
{
	switch(n)
	{
		case 1: step.y++;break;
		case 2: step.x++;break;
		case 3: step.y--;break;
		case 4: step.x--;break;
	}
	return step;
}
int pass(int m)
{
	if(m==1)
	return 1;
	else
	return 0;
}
void footprintf(postype curpos)
{
	maze[curpos.x][curpos.y]=2;
}
int mazepath(stack *S)
{
	int curstep;
	postype curpos,start,end;
	Elemtype e; 
	curpos.x=1;
	curpos.y=1;
	end.x=7;
	end.y=8;
	start=curpos; //设定当前位置为入口位置 
	curstep=1;                  //探索第一步 
	do
	{
	 if(pass(maze[curpos.x][curpos.y]))
	  {
	 	footprintf(curpos);      //留下足迹 
	 	e.seat=curpos;
	 	e.di=1;
	 	Push(S,e);                  //加入路径 
	 	if(curpos.x==end.x&&curpos.y==end.y)      //找到出口 
	 	return true;
	 	curpos=Nextpos(curpos,1);    //下一位置是当前位置的东邻
		  curstep++;            //探索下一步 
	  }	
	  else                     //当前位置不能通过 
	  {
	  	if(S->base!=S->top)
	  	{
	  	Pop(S,&e);
	  	while(e.di==4&&S->base!=S->top)
	  	 {
	  		
	  		Pop(S,&e);
	  		
	  	 }
	  	if(e.di<4)
	  	 {
	  	 e.di++;
	  	 Push(S,e);
	  	 curpos=Nextpos(e.seat,e.di);	
	  	 }
	  
	   }
   	 }
   }while(S->base!=S->top); 
   return(ERROR);
} 
void output(int maze[9][10]) 
{
	int i,j;
  for(i=0;i<9;i++)	
  {
  for(j=0;j<10;j++)	
  if(!maze[i][j])
  printf("#");
  else if(maze[i][j]==2)
  printf("*");
  else
  printf(" ");
  printf("\n");
}
}
void outputstack(stack S)
{
		
	while(S.base!=S.top)
	{
		S.top--;
		printf("\n");
	   printf("(%d,%d) ",S.top->seat.x,S.top->seat.y);
	} 
}
int main()
{   
    stack Path;
	initstack(&Path);
     mazepath(&Path);
     output(maze);
    printf("************迷宫路径************"); 
     outputstack(Path);
}

 














