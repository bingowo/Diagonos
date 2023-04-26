#include<stdio.h>
#include<string.h>
#define MaxSize 110

typedef struct
{
    char s[MaxSize];   // 存储元素的数组
    int topIdx;       //栈顶指针
}SeqStack;
//return 0 为false,1为true(下同)
// 将元素推入栈中
int Push(SeqStack L, char e)
{ // 栈已满
	if(L.topIdx==MaxSize -1)
    {
        return 0;
    }
    // 加入栈中
    L.s[L.topIdx++] = e;
    return 1;
}
// 移除栈顶元素
int Pop(SeqStack L){	// 栈空
     if(L.topIdx == 0)
    {
         //返回失败
         return 0;
    }
    // 打印并返回栈
    else{L.topIdx--;return 1;}
}
//判断栈s是否为空
int isEmpty(SeqStack s)
{
    // 如果下标在0，说明栈中无元素
    if(s.topIdx != 0) return 0;
    return 1;
}
// 判断栈是否已栈.
int isFull(SeqStack s)
{
    // 已满返回true(1)
    if(s.topIdx != MaxSize -1)return 0;//之前的定义数组的最大值的下标
    return 1;
}
char Top(SeqStack L)
{
    if(L.topIdx>0)return L.s[L.topIdx-1];
}

int rule(char a,char b){//优雅规则
    if(a=='('&&b=='{')return 1;
    if(a=='{'&&b=='[')return 1;
    if(a=='['&&b=='(')return 1;
    return 0;
}
int main(){
    int t;
    char c,s;
    scanf("%d\n",&t);
    while(t--){
        SeqStack L;L.topIdx=0;
        c=getchar();Push(L,c);
        c=getchar();
        while(c!='\n'){
            s=Top(L);
        }
        
        
    }
}