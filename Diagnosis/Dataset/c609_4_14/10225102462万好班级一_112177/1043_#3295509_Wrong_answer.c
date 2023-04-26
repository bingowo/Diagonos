#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 120

struct Stack {//创建栈
    int datas[STACK_SIZE];
    int top;//栈顶部位置标识，空栈是top = -1;
};
//初始化栈
void initStack(struct Stack* stack){
    stack->top = -1;
}
//清空栈
void Empty(struct Stack* stack){
    stack->top = -1;
}
//判断栈是否为空
int isEmpty(struct Stack* stack){
    return (stack->top == -1)? 1:0;
}
//判断栈是否满
int isFull(struct Stack* stack){
    return(stack->top == STACK_SIZE -1) ? 1:0;
}
//入栈
int push(struct Stack* stack,int value){
    //判断栈是否为空
    if(isFull(stack)){
        return 0;
    }
    stack->datas[++stack->top] = value;
    return 1;
}
//出栈
int pop(struct Stack* stack,int *value){
    //判断栈是否为空
    if(isFull(stack)){
        return 0;
    }
    *value = stack->datas[stack->top--];
    return 1;
}
//读栈操作
int getTop(struct Stack* stack,int* retvalue){
    //判断栈是否为空
    if(isFull(stack)){
        return 0;
    }
    *retvalue = stack->datas[stack->top];
    return 1;
}
//输出栈中的内容
void printStack(struct Stack* stack){
    if(isEmpty(stack)){
        printf("Empty now.");
        return;
    }
    printf("As list above:\n");
    for(int i = stack->top;i>-1;i--){
        printf("[%d]:%d\n",i,stack->datas[i]);
    }
    printf("=======END======");
}
int main(){
    int t;
    scanf("%d",&t);
    for (int z = 0; z < t; ++z) {
        struct Stack stack;
        initStack(&stack);
        char str[120];scanf("%s",str);int len = (int)strlen(str);
        int flag = 1;
        int revalue;
        for (int i = 0; i < len; ++i) {
            if(isEmpty(&stack))
            {
                push(&stack,str[i]);
                continue;
            }
            switch(str[i])
            {
                case '(':
                    getTop(&stack,&revalue);
                    if((char)revalue == '[')
                    {
                        push(&stack,str[i]);
                    }
                    else{
                        flag = 0;
                        goto FLAG;
                    }
                    break;

                case')':
                    getTop(&stack,&revalue);
                    if((char)revalue == '(')
                    {
                        pop(&stack,&revalue);
                    }
                    else{
                        flag = 0;
                        goto FLAG;
                    }
                    break;



                case '[':
                    getTop(&stack,&revalue);
                    if((char)revalue == '{')
                    {
                        push(&stack,str[i]);
                    }
                    else{
                        flag = 0;
                        goto FLAG;
                    }
                    break;


                case']':
                    getTop(&stack,&revalue);
                    if((char)revalue == '[')
                    {
                        pop(&stack,&revalue);
                    }
                    else{
                        flag = 0;
                        goto FLAG;
                    }
                    break;





                case '{':
                    getTop(&stack,&revalue);
                    if((char)revalue == '(')
                    {
                        push(&stack,str[i]);
                    }
                    else{
                        flag = 0;
                        goto FLAG;
                    }
                    break;


                case'}':
                    getTop(&stack,&revalue);
                    if((char)revalue == '{')
                    {
                        pop(&stack,&revalue);
                    }
                    else{
                        flag = 0;
                        goto FLAG;
                    }
                    break;
            }

        }
        FLAG:
        if(flag && isEmpty(&stack))printf("YES\n");
        else printf("NO\n");

    }
    return 0;
}