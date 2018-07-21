#include <stdio.h>
#include <stdlib.h>

//获取随机数
int getRandom(void)
{
 return rand();
}

//回调函数
void populate_array(int *array,size_t arraySize,int (* getRandom)(void))
{
 for(size_t i=0;i<arraySize;i++)
 {
  array[i]=getRandom();
 }
}

int main(void)
{
 int myarray[10];
 populate_array(myarray,10,getRandom);
 for(int i=0;i<10;i++)
 {
  printf("%d\n",myarray[i]);
 }
 
 return 0;

}
