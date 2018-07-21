#include <stdio.h>
//#include<stdbool.h>//bool数据类型的头文件（我的gcc版本好像不支持）
#define MaxSize 50

typedef enum{false,true}bool;//若c库里没有bool类型，则可以自己定义
typedef int ElemType;//定义int数据类型

typedef struct
{
 ElemType data[MaxSize];
 int length;
}SqList;

//函数方法声明
bool ListInsert(SqList *L,int i,int e);//将e元素插入线性表e位置
void printList(SqList *L);//打印线性表
void initList(SqList *L,int n);//初始化线性表
bool listDelete(SqList *L,int i,ElemType *elemType);//删除线性表中某个位置的元素,并返回其值e
bool getElem(SqList L,int i,ElemType *e);//获取线性表某个位置的元素
int locateElem(SqList *L,ElemType elemType);//按值查找位置

/**
 * 初始化顺序表，不设置固定长度
 * 输入-1结束插入
 * @param l
 */
void init(SqList *l);

/**
 * 删除顺序表中最小值的元素,并由函数返回被删元素的值
 * 空出的位置由最后的元素填补
 * 若顺序表为空则显示出错信息并退出运行
 * @param L
 */
bool deleteMinElem(SqList *l,ElemType *elemType);

/**
 * 将线性表中的所有数据逆置，要求算法空间复杂度为O（1）
 * @param l
 * @return
 */
bool reverseList(SqList *l);

/**
 * 删除线性表中所有值为e的数据元素
 * @param l
 * @param e
 * @return
 */
bool deleteElem(SqList *l,ElemType *e);

/**
 * 删除所有在给定值s与t之间的值，并且s<t
 * 思路：保存顺序表中不在s和t范围的个数，边统计边统计k，并将数据保存在k位置上，最后修改顺序表的长度
 * @param l
 * @param s
 * @param t
 * @return
 */
bool deleteAmongElem(SqList *l,ElemType *s,ElemType *t);

/**
 * 删除有序顺序表中相同的值，使所有元素的值都不同
 * 算法思路：这只用于有序的顺序表，若是无序的顺序表则不行
 * 因为是顺序表，所以相同的值会连续的排在一起
 * 初始时将第一个元素看作非重复的数，并且是非重复元素顺序表的第一位，依次与后面元素进行判断
 * 若元素不同则将此不同的元素插入非重复元素顺序表中，若相同则进行下一次循环
 * @param l
 * @return
 */
bool deleteCommonElem(SqList *l);

/**
 * 将两个有序顺序表合并成一个有序顺序表
 * @param list1
 * @param list2
 * @return
 */
SqList merge_list(SqList list1,SqList list2);

int main()
{
 //初始化空的顺序表
 SqList list;
 SqList list1,list2;
 list.length=0;//设置顺序表的长度为0

 //局部变量名
 int e,posit;//数据，位置
 char c='s';
 bool flag=false;
 ElemType s,t;//值范围

    //顺序表的相应的操作方法
 printf("下列有顺序表的一系列操作，请选择一个操作!\n\n");
 printf("a:初始化顺序表（固定长度） b：获取元素位 c：插入元素;\n"
        "d：删除元素 e：查找元素位置 f:删除最小值\n"
        "g:置换所有数据 h:删除所有元素e m:删除给定范围的值\n"
        "s:删除相同的值 n:合并两个顺序表\n"
        "p：输出元素 q:退出操作\n");
 printf("请选择一个操作：");
 //循环选择其他操作
   while (c!='q'&&c!='\0'){

     scanf("%c", &c);
     printf("你选择的是：%c\n",c);

         //用switch语句进行操作选择
         switch (c) {
             case 'a':
                 //初始化一个长度为5的线性表
                 initList(&list, 5);
                 printList(&list);
                 break;
             case 'b':
                 printf("请输入想获取元素的位置：");
                 scanf("%d", &posit);
                 //获得元素
                 flag = getElem(list, posit, &e);
                 if (flag == true) {
                     printf("获取的元素是：%d\n", (e));
                 }
                 break;
             case 'c':
                 printf("请选择在那个位置插入一个数据：\n");
                 scanf("%d %d", &posit, &e);
                 //插入元素
                 flag = ListInsert(&list, posit, e);
                 if (flag == true) {
                     printf("插入成功！\n");
                     printList(&list);
                 }
                 break;
             case 'd':
                 printf("请输入你想要删除的位置：\n");
                 scanf("%d", &posit);
                 flag = listDelete(&list, posit, &e);
                 if (flag == true) {
                     printf("删除成功！删除的元素是:%d\n", (e));
                     printList(&list);
                 }
                 break;
             case 'e':
                 printf("请输入你想要查找的元素：\n");
                 scanf("%d",&e);
                 if (locateElem(&list,e)!=0)
                     printf("存在该元素，位置：%d",locateElem(&list,e));
                 else
                     printf("抱歉，不存在该元素！");
                 break;
             case 'f':
                 printf("删除最小值！\n");
                 if (deleteMinElem(&list,&e)==true)
                     printf("删除成功！删除的最小值是：%d\n",(e));
                 printList(&list);
                 break;
             case 'g':
                 printf("置换所有元素！\n");
                 if(reverseList(&list)==true)
                     printf("置换成功！\n");
                 printList(&list);
                 break;
             case 'h':
                 printf("请输入你要删除的元素：");
                 scanf("%d",&e);
                 if (deleteElem(&list,&e))
                 {
                     printf("删除所有%d数据成功！\n",e);
                 }
                 printList(&list);
                 break;
             case 'm':
                 printf("请输入删除的范围：");
                 scanf("%d %d",&s,&t);
                 if(deleteAmongElem(&list,&s,&t))
                     printf("删除数据成功！\n");
                 printList(&list);
                 break;
             case 'p':
                 printList(&list);
                 break;
             case 's':
                 if (deleteCommonElem(&list))
                     printf("删除重复的数成功\n");
                 printList(&list);
                 break;
             case 'n':

                 //初始化第一个顺序表
                 printf("请输入第一个顺序表：\n");
                 init(&list1);//初始化顺序表
                 printList(&list1);//打印顺序表

                 //初始化第二个顺序表
                 printf("请输入第二个顺序表：\n");
                 init(&list2);//初始化顺序表
                 printList(&list2);//打印顺序表

                 //合并顺序表并打印出来
                 printf("进行合并！\n");
                 list=merge_list(list1,list2);//合并两个顺序表
                 printList(&list);//打印顺序表
                 break;
             case 'q':
                 printf("拜拜！再见啦！\n");
                 break;
         }

     }

 return 0;
}

//初始化长度为n的线性表
void initList(SqList *L,int n)
{
  printf("请输入%d个数：\n",n);
  for(int i=0;i<n;i++)
  {
    scanf("%d",&L->data[i]);
  }
  L->length=n;
}

/**
 * 初始化顺序表，不设置固定长度
 * 输入-1结束插入
 * @param l
 */
void init(SqList *l)
{
    int i=0;//初始化为零，用于指针自增
             int j=0;//保存输入的值
    printf("请输入相应的数字，结束请输入-1\n");
    while(j!=-1)
    {
        scanf("%d",&j);//输入值
        //判断输入的数是否是-1,防止-1保存到顺序表中
        if (j!=-1)
        {
            l->data[i]=j;//将数据保存到顺序表中
            i++;//指针自增1
        }
    }
    l->length=i;//设置顺序表的长度
}

//获取线性表某个位置的元素
bool getElem(SqList L,int i,ElemType *e)
{
    //判断线性表是否为空
    if (L.length==0)
    {
        printf("线性表为空\n");
        return false;
    }
    // 查找的元素是否在范围内
    if (i<1||i>L.length)
    {
        printf("你要查找的位置没有元素！\n");
        return false;
    }

    *e=L.data[i-1];//将数据保存在指针元素中
    return true;
}

//线性表插入操作，将e元素插入i位置
bool ListInsert(SqList *L,int i,int e)
{
 printf("在%d位置，插入e元素:%d\n",i,e);
 //判断i位置是否在线性表范围中
 if(i<1||i>L->length+1)
   return false;
  
 //当前空间已满，不能插入
 if(L->length>=MaxSize)
   return false;

 //将元素e插入i位置，之后的元素后移,并判断不在表尾
    if (i<=L->length)
    {        for(int j=L->length;j>=i;j--)
            L->data[j]=L->data[j-1];
    }
   L->data[i-1]=e;//在位置i处将元素e插入进去
   L->length=L->length+1;//线性表长度增加1
   return true;
}

//线性表删除操作，删除某个位置数据,并用e返回返回其值，L的长度减一
bool listDelete(SqList *L,int s,ElemType *elemType)
{
    //判断线性表是否为空
    if (L->length==0)
        return false;

    //判断i位置是否在线性表范围内
    if(s<1||s>L->length)
        return false;

    *elemType=L->data[s-1];//将删除的元素返回

    //先判断删除的位置是不是在表尾,将位置i后面的元素往前移，覆盖i位置元素
            if (s<L->length)
                for (int j = s; j <=L->length ; ++j)
                    L->data[j-1]=L->data[j];
            L->length--;//线性表长度减少1

    return true;
}

//按值查找线性表元素
int locateElem(SqList *L,ElemType elemType)
{
    for (int i = 0; i <L->length ; ++i) {

        if(L->data[i]==elemType)
        {
            return i+1;
        }
    }
    return 0;

}
/**
 * 删除顺序表中最小值的元素,并由函数返回被删元素的值
 * 空出的位置由最后的元素填补
 * 若顺序表为空则显示出错信息并退出运行
 * @param L
 */
 bool deleteMinElem(SqList *l,ElemType *elemType)
{
    int min=l->data[0];//初始化最小值
            int posit=0;//记录最小值的位置
    if (l->length==0)
    {
        printf("顺序表不能为空！\n");
        return false;
    }

    for (int i = 0; i < l->length; ++i) {
        if (min > l->data[i])
        {
            min = l->data[i];
            posit=i;
        }
    }
    *elemType=min;
    l->data[posit]=l->data[l->length-1];
    l->length--;
    return true;
}

/**
 * 将线性表中的所有数据逆置，要求算法空间复杂度为O（1）
 * @param l
 * @return
 */
bool reverseList(SqList *l)
{
    int temp=0;//设置临时替换变量

    if(l->length==0)
    {
        printf("线性表不能为空！\n");
        return false;
    }

    for (int i = 0; i <l->length/2 ; ++i) {
        temp=l->data[i];
        l->data[i]=l->data[l->length-1-i];
        l->data[l->length-1-i]=temp;
    }

    return true;
}

/**
 * 删除线性表中所有值为e的数据元素
 * 思路：将顺序表中不等于e的数据个数（即需要保存的数据），边扫描顺序表边统计k，
 * 并将不等于e的数据向前放置在k位置上，最后修改顺序表的长度。
 * @param l
 * @param e
 * @return
 */
bool deleteElem(SqList *l,ElemType *e)
{
    ElemType k=0;
    if (l->length==0)
    {
        printf("顺序表不能为空！\n");
        return false;
    }

    for(int i=0;i<l->length;++i)
    {
        if (l->data[i]!=*(e))
        {
            l->data[k]=l->data[i];
            k++;

            //这种方法时间复杂度太大
            //for (int j = i; j < l->length-i; ++j)
              //  l->data[j]=l->data[j+1];
            //l->length--;
            //i--;
        }
    }
    l->length=k;//将顺序表的长度设置成k
    return true;
}

/**
 * 删除所有在给定值s与t之间的值，并且s<t
 * 思路：保存顺序表中不在s和t范围的个数，边统计边统计k，并将数据保存在k位置上，最后修改顺序表的长度
 * @param l
 * @param s
 * @param t
 * @return
 */
bool deleteAmongElem(SqList *l,ElemType *s,ElemType *t)
{
    int k=0;//初始化k的值

    if (l->length==0)
    {
        printf("顺序表为空！\n");
        return false;
    }
    if(s>=t)
    {
        printf("输入的值不规则！\n");
        return false;
    }

    for (int i = 0; i <l->length ; ++i) {
        if (l->data[i]<=*s || l->data[i]>=*t)
        {
            l->data[k]=l->data[i];
            k++;
        }

    }
    l->length=k;
    return true;
}

/**
 * 删除有序顺序表中相同的值，使所有元素的值都不同
 * 算法思路：这只用于有序的顺序表，若是无序的顺序表则不行
 * 因为是顺序表，所以相同的值会连续的排在一起
 * 初始时将第一个元素看作非重复的数，并且是非重复元素顺序表的第一位，依次与后面元素进行判断
 * 若元素不同则将此不同的元素插入非重复元素顺序表中，若相同则进行下一次循环
 * @param l
 * @return
 */
bool deleteCommonElem(SqList *l)
{
    //判断顺序表是否为空
    if (l->length==0)
    {
        printf("顺序表不能为空！\n");
        return false;
    }

    int i,j;//i用于存储第一个不同的值，j用于工作指针
    //遍历有序顺序表，将不同的元素插入非重复顺序表中
    for ( i = 0,j=1; j <l->length; j++)
        if (l->data[i]!=l->data[j])
            l->data[++i]=l->data[j];//将不同的元素插入非重复顺序表中
    l->length=i+1;//最后的表的长度，i需要加1

    //这用于无序顺序表（有bug），对顺序表进行双循环，使每个数能够和其后的所有数对比
//    for (int i = 0; i <l->length ; ++i) {
//        for (int j = i + 1; j < l->length - i; ++j) {
//            printf("进来的i:%d和j:%d\n",i,j);
//            if (l->data[i] == l->data[j]) {
//                printf("进来了\n");
//                //当有共同的值时，删除此值，使此数后面的数逐一取代前一位的数
//                //顺序表长度减少一位
//                for (int k = j; k < l->length - j; ++k) {
//                    l->data[k] = l->data[k + 1];
//                }
//                l->length--;//顺序表长度减少1
//            }
//        }
//    }

    return true;
}
/**
 * 将两个有序顺序表合并成一个有序顺序表
 * @param list1
 * @param list2
 * @return
 */
SqList merge_list(SqList list1,SqList list2)
{

    int len=list1.length;//将list1长度的值赋值给变量len
    int temp;//暂时替换变量

    //进行初合并，不考虑顺序表的顺序，将list2的值合并的list1中，相应的list1的长度随之增加
    for (int i = 0; i <list2.length; ++i) {
       list1.data[len+i]=list2.data[i];
       ++list1.length;
    }
//    printf("初合并后的顺序表:\n");
//    printList(&list1);

    //进行升序排序，即进行双循环，对每一个数与之后续的数进行比较（这是由于此是顺序表，比较数前面的数都与之小），
    //若比较数大于被比较数，则两个值交换位置，再与下一个被比较数进行比较，直至循环结束
    for (int k = 0; k <list1.length; ++k)
        for (int l = k; l <list1.length ; ++l) {
            //进行比较数与比较数判断，大于则交换位置
            if (list1.data[k]>list1.data[l])
            {
                //置换比较数和被比较数
                temp=list1.data[k];
                list1.data[k]=list1.data[l];
                list1.data[l]=temp;
            }
        }

    return list1;
}

//打印线性表表数据
void printList(SqList *L)
{
 printf("打印线性表:\n");
 for(int i=0;i<L->length;i++)
 {
  printf("L->data[%d]=%d\n",i,L->data[i]);
 }

}
