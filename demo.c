#include <stdio.h>

const int MAX=3;

int main()
{
  int var[]={23,34,52};
  int *p[MAX];
  
  char *names[]={"xiaonan","xiaoshuai","xiaopan"};

  int *ptr;
  int **pptr;
for(int i=0;i<MAX;i++)
{
 p[i]=&var[i];//将数组中每个元素的地址付给p
}
 
 for(int i=0;i<MAX;i++)
{

   printf("address of p:p[%d]:%p\n",i,p[i]);
   printf("value of p:p[%d]:%d\n",i,*p[i]);
  
}

//遍历names
for(int i=0;i<MAX;i++)
{
 printf("address of names:names[%d]:%p\n",i,names[i]);
 printf("value of names:names[%d]:%s\n",i,names[i]);
}

//指针间接寻址
int var2=300;

ptr=&var2;
pptr=&ptr;

printf("value at var2=%d\n",var2);
printf("value available at *ptr=%d\n",*ptr);
printf("value available at var2=%d\n",**pptr);


return 0;
  
}

