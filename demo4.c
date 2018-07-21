#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//要生成和返回随机数的函数
int * getRandom()
{
 static int r[10];
 int i;
 
 //初始化随机数发生器,以时间来播种
 srand((unsigned)time(NULL));

 //生出随机数
 for(i=0;i<10;i++)
 {
  r[i]=rand();
  printf("the number of random:r[%d]\n",r[i]);
 }

 return r;

}

//调用上面定义函数的主函数
int main()
{
 //一个指向整数的指针
 int *p;
 int i;

 p=getRandom();
 for(i=0;i<10;i++)
 {
  printf("*(p+[%d]:%d\n",i,*p);
  p++;
 }

 return 0;

}
