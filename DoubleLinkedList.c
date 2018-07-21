
/**
 * description:双向链表（double linked list）是单链表的每个结点中，再设置一个指向其直接前驱结点的指针域
 */
#include <stdio.h>
#include "malloc.h"
typedef enum{true,false}bool;//定义boolean类型的枚举
typedef int ElemType;//定义int类型常量

//构建结点和链表的结构体
typedef struct DNode{
    ElemType data;//数据域
    struct DNode *prior,*next;//前驱和后继指针域
}DNode,*DLinkList;

//函数声明
bool createListByHead(DLinkList *dLinkList);//头插法创建双链表
bool printList(DLinkList *dLinkList);//打印双链表
//主函数
int main() {

    //局部变量声明
    DLinkList dLinkList;//双链表变量
    DNode node;//结点变量
    char p;//循环选择变量
    bool flag=false;//boolean类型

    printf("选择下面一些功能：\n");
    printf("a:头插法创建双链表\n"
           "p:打印双链表\n");
    while (p!='q')
    {
        scanf("%c",&p);//输入选项
        switch (p){
            case 'a':
                printf("请输入存储的值（输入-1结束输入）:\n");
                createListByHead(&dLinkList);//调用创建双链表的函数方法
                printList(&dLinkList);//打印双链表
                break;
            case 'p':
                printList(&dLinkList);//打印双链表
                break;
        }
    }
    createListByHead(&dLinkList);
    return 0;
}

//函数方法

/**
 * 头插法创建双链表
 * 算法思路：
 * @param dLinkList
 * @return
 */
bool createListByHead(DLinkList *dLinkList)
{
    DNode *node,*head;ElemType x;//结点变量，输入值变量
    int len=1;
    *dLinkList=(DLinkList)malloc(sizeof(DNode));//创建头结点，为结点分配内存空间
    (*dLinkList)->prior=NULL;//头指针前驱指针指向NULL
    (*dLinkList)->next=NULL;//头指针指向NULL，初始空链表

    head=malloc(sizeof(DNode));
    head->prior=NULL;
    head->next=NULL;
    scanf("%d",&x);
    while (x!=-1){//x=-1结束循环
        node=malloc(sizeof(DNode));//创建新结点，分配内存空间
        node->data=x;//将输入值保存在数据域中
        node->prior=head;//指向新结点的前驱结点
        node->next=head->next;//指向新结点的后继结点
        //(*dLinkList)->next=node;//前驱结点的指针域指向新结点
        head->next=node;
        (*dLinkList)->next=head;
        printf("测试：%d",(*dLinkList)->data);
        scanf("%d",&x);//输入值
        len++;//统计链表的长度
    }
    //*dLinkList=head;
    (*dLinkList)->data=len;//将链表长度保存在头指针的数据域中
    return true;
}

/**
 * 打印双链表
 * @param dLinkList
 * @return
 */
bool printList(DLinkList *dLinkList)
{
    DNode *node=(*dLinkList)->next;//链表第一个结点（不是头结点）
    DNode *prior,*next;
    int j=1;//统计链表结点
    if(node==NULL)
    {
        printf("链表为空哦，请创建链表\n");
        return false;
    }

    printf("打印双链表:\n");
    while (node!=NULL)
    {
        //输出第几结点，本结点值，前驱结点的值，后继结点的值
        printf("第%d结点，本结点值：%d,前驱结点的值：，后继结点的值：%d\n",j,node->data,node->next->data);
        prior=node->prior;
        next=node->next;
        if(prior!=NULL&&next!=NULL)
        printf("***前驱结点的值：%d，后继结点的值：%d\n",prior->data,next->data);
        node=node->next;//指向下一个结点
        j++;//长度自增1
    }

    return true;
}