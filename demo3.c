#include <stdio.h>

double getAverage(int *arr,int size);

int main()
{
 //初始化带五个参数的数组
 int balance[5]={23,4,52,5,6};
 double avg;

 //传递一个指向数组的指针作为参数
 avg=getAverage(balance,5);

 //输出返回值
 printf ("Average value is:%f\n ",avg);

 return 0;
}

double getAverage(int *arr,int size)
{
 int i,sum=0;
 double avg;
 
 for(i=0;i<size;++i)
 {
  sum+=arr[i];
 }
 
 avg=(double)sum/size;
 
 return avg;

}

