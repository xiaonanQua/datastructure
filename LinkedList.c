#include <malloc.h>
#include "stdio.h"

typedef enum{true,false}bool;//定义布尔类型（我的gcc中不支持bool的头文件引入）
typedef int ElemType;//定义int数据类型

//定义单链表结点类型
typedef struct LNode{
    ElemType data;//数据域
    struct LNode *next;//指针域
}LNode,*LinkList;

//函数方法声明
void CreateListByHead(LinkList *list);//用头插法建立单链表
bool CreateListByTail(LinkList *list);//用尾插法建立单链表（生成的链表次序与输入的相同）
LNode * getNodeByPosit(LinkList list,int posit);//按序号查找结点值
LNode* getNodeByValue(LinkList linkList,ElemType e);//根据值查找位置
bool insertNode(LinkList *linkList,ElemType e,ElemType posit);//插入结点操作
bool deleteNode(LinkList linkList,ElemType posit);//删除结点操作
bool deleteLinkList(LinkList *linkList);//删除单链表
bool CreateCircularList(LinkList *list);//创建循环单链表
bool PrintLinkList(LinkList list);//打印单链表数据
bool PrintCircularList(LinkList list);//打印循环链表

//主函数
int main(){

    //局部变量声明
    LinkList linkList;//单链表变量
    LNode *lNode;//结点变量
    int posit;//查找位置的变量
    ElemType e;//查找元素的变量
    char p;//选择循环判断变量
    bool flag;

    printf("单链表功能如下：\n");
    printf("a：头插法创建单链表 b:尾插法创建单链表 c:按序号查找结点值\n"
           "d:根据值查找位置 e:插入结点（按位置） f:删除结点操作\n"
           "g:删除单链表 m：创建循环单链表\n"
           "p:打印单链表\n");

    //选择循环使用
    while(p!='q')
    {
        printf("请选择一项操作：");
        scanf("%c",&p);
        //操作选择开关
        switch (p){
            case 'a':
                //头插法创建单链表
                printf("请输入你要存储的值(输入-1结束输入)：");
                CreateListByHead(&linkList);//头插法建立单链表
                //判断是否插入成功
                if(linkList->data!=0)
                printf("单链表创建成功\n");
                PrintLinkList(linkList);
                break;
            case 'b':
                //尾插法创建单链表
                printf("请输入你要存储的值(输入-1结束输入)：");
                flag=CreateListByTail(&linkList);//尾插法建立单链表
                if (flag)
                    printf("单链表创建成功\n");
                PrintLinkList(linkList);
                break;
            case 'c':
                //按序号查找结点值
                printf("请输入你要查找的位置：");
                scanf("%d",&posit);
                lNode=getNodeByPosit(linkList,posit);
                printf("第%d位置的值是：%d\n",posit,lNode->data);
                break;
            case 'd':
                //根据值查找位置
                printf("请输入查找的元素：\n");
                scanf("%d",&e);
                lNode=getNodeByValue(linkList,e);
                if (lNode->next==NULL)
                    printf("你输入的值不存在！\n");
                else
                    printf("存在该结点\n");
                break;
            case 'e':
                //插入操作
                printf("请输入插入的位置和值：");
                scanf("%d %d",&posit,&e);
                flag=insertNode(&linkList,e,posit);//调用插入方法
                //判断插入是否成功
                if (flag==true)
                {
                    printf("插入成功！\n");
                    PrintLinkList(linkList);
                }
                break;
            case 'f':
                //删除结点
                printf("请输入你要删除的位置：");
                scanf("%d",&posit);
                flag=deleteNode(linkList,posit);//调用删除方法
                if(flag==true)
                {
                    printf("删除成功！\n");
                    PrintLinkList(linkList);
                }
                break;
            case 'g':
                //删除单链表
                flag=deleteLinkList(&linkList);//调用删除单链表方法
                if(flag==true)
                    printf("删除成功！\n");
                break;
            case 'm':
                //创建循环单链表
                flag=CreateCircularList(&linkList);
                if(flag==true)
                {
                    printf("创建成功！\n");
                    PrintCircularList(linkList);
                }
                break;
            case 'p':
                //打印单链表
                PrintLinkList(linkList);//打印单链表
                break;
        }

    }



}

/**
 *用头插法建立单链表（生成的链表次序与输入的相反）
 * 算法思路：从空表开始，生成新结点，并将输入的数据保存到新结点的数据域中
 * 然后将新结点插入到当前链表的表头，即头结点之后，始终让新结点在第一的位置
 * @param list
 * @return
 */
void CreateListByHead(LinkList *list)
{
    LNode *s;int x;//结点变量，输入值变量
    int len=0;//统计链表的长度
    *list=(LinkList)malloc(sizeof(LNode));//创建头结点，分配内存空间
    (*list)->next=NULL;//初始为空链表
    scanf("%d",&x);//输入结点的值
    while(x!=-1){//输入9999表示结束
        s=(LNode*)malloc(sizeof(LNode));//创建新的结点
        s->data=x;//将输入的值保存到s结点的数据域中
        s->next=(*list)->next;//将头结点的后继结点的地址保存在s结点的后继结点指针中
        (*list)->next=s;//将s结点保存在头结点的后继指针中
        scanf("%d",&x);//继续输入下一个值
        len++;//链表长度自增1
    }
    (*list)->data=len;//将链表长度插入头结点数据域中

}
/**
 * 创建循环单链表
 * 和下述用尾插法建立链表很相似
 * 只需修改一处，在输入结束后，尾指针的指向不是指向为空而是指向头指针
 * @param list
 * @return
 */
bool CreateCircularList(LinkList *list)
{
    LNode *p,*tail;int x;//新结点变量,表尾结点变量，输入值变量
    *list=(LinkList)malloc(sizeof(LNode));//创建单链表
    tail=*list;//tail为指向表尾的结点
    scanf("%d",&x);//输入结点的数据
    while(x!=-1){//输入9999结束循环
        p=(LNode*)malloc(sizeof(LNode));//创建新结点
        p->data=x;//将输入的值保存到新结点的数据域中
        tail->next=p;//表尾终端结点的指针指向新结点
        tail=p;//原先的tail已不是尾结点了，需将p结点赋值给tail成为新的尾结点
        scanf("%d",&x);//继续输入下一个值
    }
    tail->next=(*list)->next;//循环结束，尾结点指向头指针，实现循环单链表
    return true;
}

/**
 * 用尾插法建立单链表（生成的链表次序与输入的相同）
 * 算法思路：
 * 1.新建新结点、表尾结点变量，输入值变量
 * 2.创建空的链表，并赋值给表尾结点
 * 3.进行输入循环，创建新结点，保存输入值到新结点的数据域中
 * 4.此时尾结点为新创建的新结点，所以将表尾结点的指针指向新结点，更新表尾结点
 * 5.循环结束，将尾结点的指针置为空，以便以后遍历确认此为尾部
 * @param list
 */
bool CreateListByTail(LinkList *list)
{
    LNode *p,*tail;int x;//新结点变量,表尾结点变量，输入值变量
    *list=(LinkList)malloc(sizeof(LNode));//创建单链表
    tail=*list;//tail为指向表尾的结点
    scanf("%d",&x);//输入结点的数据
    while(x!=-1){//输入9999结束循环
        p=(LNode*)malloc(sizeof(LNode));//创建新结点
        p->data=x;//将输入的值保存到新结点的数据域中
        tail->next=p;//表尾终端结点的指针指向新结点
        tail=p;//原先的tail已不是尾结点了，需将p结点赋值给tail成为新的尾结点
        scanf("%d",&x);//继续输入下一个值
    }
    tail->next=NULL;//循环结束，结点的指针域应置为空，以便以后遍历时确认这为尾部
    return true;
}

/**
 * 按序号查找结点值
 * @param list
 * @param posit
 * @return
 */
LNode* getNodeByPosit(LinkList list,int posit)
{
    int j=1;//结点起始变量
    LNode *p=list->next;//将头指针赋给p
            if (posit==0)
                return list;
            if (posit<1)
                return NULL;
            while(p&&j<posit)
            {
                p=p->next;//将下一个结点赋值给p，p就是下一个结点
                j++;
            }
    return  p;

}

/**
 * 根据值查找位置
 * @param linkList
 * @param e
 * @return
 */
LNode* getNodeByValue(LinkList linkList,ElemType e)
{
    if (linkList==NULL)
    {
        printf("请创建链表\n");
        return NULL;
    }

    LNode *p=linkList->next;//将头结点指针赋值给p结点
    while(p->data!=e)
        p=p->next;//将p指针域中下一个结点赋值给p
    return p;
}

/**
 * 插入结点操作
 * 算法思路：
 * 1.申请新结点，将输入的值保存到结点的数据域中
 * 2.查找要插入位置的前驱结点，判断输入的位置是否合法
 * 3.若合法，则将前驱结点的后继结点指针赋值给新结点的后继结点指针
 * 4.再将新结点赋值给前驱结点的后继结点指针域中
 * 3,4这两个步骤不能颠倒顺序，否则后继结点则不存在了.
 * 若给定了结点位置则时间复杂度O(1),因为要对要插入的位置进行查找，故时间复杂度O(n)
 * @param linkList
 * @param e
 * @param posit
 * @return
 */
bool insertNode(LinkList *linkList,ElemType e,ElemType posit)
{
    LNode *node=malloc(sizeof(LNode));//创建新结点，为新结点分配内存空间（不分配的话会异常结束，一直折磨我的错误->->）
    node->data=e;//将e赋值给结点的数据域中
    LNode *p=getNodeByPosit(*linkList,posit-1);//查找posit位置的前驱结点
    if(p==NULL)
    {
        printf("插入的位置不合法\n");
        return false;
    }
    node->next=p->next;//将前驱结点的后继结点指针赋值给node新结点的指针域中
    p->next=node;//将新结点node赋值给p的后继结点指针中
    return true;

}

/**
 * 删除结点操作
 * 算法思路：
 * 1.通过删除的位置，查找被删结点的前驱结点，并判断删除位置的合法性
 * 2.通过前驱结点的指针域获得被删结点
 * 3.将被删结点指针域中的后继结点赋值给前驱结点指针域中
 * 4.释放被删结点的内存空间
 * @param linkList
 * @param posit
 * @return
 */
bool deleteNode(LinkList linkList,ElemType posit)
{
    /*******前插法********/
//    LNode *node=getNodeByPosit(linkList,posit-1);//通过调用位置查找结点的方法，查找前驱结点
//    if(node==NULL)
//    {
//        printf("输入的位置不合法!\n");
//        return false;
//    }
//    LNode *delNode=node->next;//通过被删结点的前驱结点指针域，获取被删结点
//    node->next=delNode->next;//将被删除结点指针域中的后继结点赋值给前驱结点指针域中
//    free(delNode);//释放被删结点的内存空间
//    return true;
    /*******后插法*********/
    LNode *delNode=getNodeByPosit(linkList,posit);//查找被删除的结点
    if(delNode==NULL)
    {
        printf("输入的位置不合法！\n");
        return false;
    }
    if (delNode->next!=NULL) {
        LNode *nextNode = delNode->next;//将被删结点的后继结点赋给nextNode
        delNode->data = nextNode->data;//将后继结点的数据赋给被删结点
        delNode->next = nextNode->next;//将后继结点从链表中断开，被删结点变成后继结点，原先的后继结点要被删除
        free(nextNode);//释放后继结点的内存空间
    } else
    {
        LNode *preNode=getNodeByPosit(linkList,posit-1);//查找被删结点的前驱结点
        preNode->next=NULL;//将被删结点从链表中断开
        free(delNode);//释放被删结点内存空间
    }

    return true;

}

/**
 * 删除单链表
 * 算法思路：
 * 1定义两个链表变量
 * 2.将删除的链表中的第一格结点赋值给一个链表变量p
 * 3.进行循环，当p为空时结束循环。把p的后继结点指向给q，然后p就从此链表中掉了出来，
 * 释放内存空间，再次把后继结点q赋值给p，进行下一轮结点的删除。
 * 4.将链表中头结点指针域设置为空
 * @param linkList
 * @return
 */
bool deleteLinkList(LinkList *linkList)
{
    LinkList p,q;//定义两个链表变量
    p=(*linkList)->next;//指向第一个结点
    while(p)
    {
        q=p->next;//指向p的后继结点
        free(p);//释放p结点的内存空间
        p=q;//将后继结点赋值给p
    }
    (*linkList)->next=NULL;//头结点指针域设置为空
    return true;
}

/**
 * 打印单链表数据
 * @param list
 */
bool PrintLinkList(LinkList list)
{
    LNode *p=list->next;//将头结点指针赋值给结点p,即第一个指针
    int j=1;//记录结点长度
    if(p==NULL) {
        printf("单链表为空\n");
        return false;
    }
    //对单链表进行循环输出，若结点指针为空的话，则结束循环
    printf("打印单链表！\n");
    while(p)
    {
        printf("链表结点%d:%d\n",j,p->data);//输出此结点的数据
        p=p->next;//将下一个结点的结点指针赋值给结点p
        j++;//长度自增1
    }
    return true;
}

bool PrintCircularList(LinkList list)
{
    LNode *p=list->next;//将头结点指针赋值给结点p,即第一个指针
    LNode *s=malloc(sizeof(LNode));//创建用于判断的结点
    s->next=NULL;
    int j=1;//记录结点长度
    if(p==NULL) {
        printf("单链表为空\n");
        return false;
    }
    //对单链表进行循环输出，若结点指针为空的话，则结束循环
    printf("打印循环单链表！\n");
    while(s!=p)
    {
        if (s->next==NULL)
        s=p;//将下一个结点的结点指针赋值给结点p
        printf("链表结点%d:%d\n",j,s->data);//输出此结点的数据
        s=s->next;
        j++;//长度自增1
    }
    return true;

}