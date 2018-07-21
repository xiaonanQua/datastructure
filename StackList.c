
/**
 * 栈的线性存储结构
 */
#include "stdio.h"
#define MaxSize 50//定义栈的最大存储值

typedef enum{true,false}bool;//定义布尔类型枚举
typedef int ElemType;//定义int类型
//定义栈的结构体
typedef struct{
    ElemType data[MaxSize]; //存放栈中元素
    int top;//栈顶指针
}Stack;

/****声明函数方法*****/
//栈的基本方法
void InitStatck(Stack *stack);//初始化空栈
bool StackEmpty(Stack *stack);//判断栈空
bool Push(Stack *stack,ElemType x);//进栈
bool Pop(Stack *stack,ElemType *x);//出栈
bool GetTop(Stack *stack,ElemType *x);//获得栈顶元素

/****主函数*****/
int main(void)
{
    //定义局部变量
    Stack stack;//栈变量
    ElemType x;//存储栈值元素
    bool flag=false;//布尔类型变量
    char c;//选择变量

    //相关操作
    printf("请选择相应的操作(输入q结束选择)：\n");
    printf("a:初始化栈（栈空）b：判断栈空\n c：进栈 d:出栈 \n "
           "e:获得栈顶元素\n");
    while (c!='q')
    {
        printf("选择你一个选项：");
        scanf("%c",&c);
        switch (c){
            case 'a':
                InitStatck(&stack);//初始化栈（栈空）
                break;
            case 'b':
                flag=StackEmpty(&stack);//判断栈空
                if(flag)
                {
                    printf("栈为空\n");
                } else{
                    printf("栈不为空\n");
                }
                break;
            case 'c':
                printf("请输入进栈的值：");
                scanf("%d",&x);
                flag=Push(&stack,x);//进栈
                if(flag)
                    printf("进栈成功！\n");
                break;
            case 'd':
                flag=Pop(&stack,&x);//出栈
                if(flag)
                printf("出栈成功，元素为%d",x);
                break;
            case 'e':
                flag=GetTop(&stack,&x);//获取栈顶元素
                printf("获取元素成功，栈顶元素为：%d",x);
                break;
        }
    }


}

/******函数方法******/

/**
 * 初始化空栈
 * @param stack
 */
void InitStatck(Stack *stack){
    stack->top=-1;//初始化栈顶指针
    printf("初始化成功\n");
}

/**
 * 判断栈空
 * @param stack
 * @return
 */
bool StackEmpty(Stack *stack){
    if (stack->top==-1)//top=-1表示栈空
    {
        return true;//栈空
    } else{
        return false;//非空
    }
}

/**
 * 进栈
 * 判断栈满，若满发生上溢错误，无法添加，进栈时栈顶指针先自增1,再存储值
 * @param stack
 * @param x
 * @return
 */
bool Push(Stack *stack,ElemType x){
    //判断栈满
    if(stack->top==MaxSize-1){//栈满，再添加就上溢
        printf("栈将上溢\n");
        return false;
    }
    stack->data[++stack->top]=x;//栈顶指针先自增1,再进栈值
    return true;
}

/**
 * 出栈
 * 判断栈是否为空，若为空则提示栈空，若不为空，先出栈，将值赋值给x指针，栈顶指针再自减1
 * @param stack
 * @param x
 * @return
 */
bool Pop(Stack *stack,ElemType *x){

    //判断栈空
    if (StackEmpty(stack)){
        printf("栈空\n");
        return false;
    }
    *x=stack->data[stack->top--];//先出栈，栈顶指针再自减1
    return true;
}

/**
 * 获得栈顶元素
 * @param stack
 * @param x
 * @return
 */
bool GetTop(Stack *stack,ElemType *x){

    //判断栈空
    if(stack->top==-1){
        printf("栈空\n");
        return false;
    }
    *x=stack->data[stack->top];//x保存栈顶元素
    return true;
}

