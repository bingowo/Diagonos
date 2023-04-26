#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long ll;


stack<int> myStack；

void getBinary(ll num)//4   1 0 0
{
    while(num)
    {
        myStack.push(num%2);
        num/=2;//除2
    }
}
int main()
{
    int T, cnt;

int a[100];
scanf("%d",&T);
    while(T--){// 1 0 0
        ll num;
        scanf("%d",&num);
        getBinary(num);
        int l=0;
        while(!myStack.empty()){//判断是否为空
            a[l++]=myStack.top();//取顶元素
            myStack.pop();//弹出顶元素
        }
        int len=1;//target
        int maxi=len;//-1 -100 往小取值 minx 往大取值
for(int i=1;i<a.size();++i)// 001 00 0 01/10 2
{
            if(a[i]!=a[i-1]) len++;
            if(maxi<len) maxi=len;
            If(a[i]==a[i-1]){
                if(a[i]==0) {
                    len=0;//去掉前置0
                    continue;//
                }
                else len=1;// 110 000 1  len=1
            }
        }
        printf("case #%d:\n",cnt++);
       
    }
    return 0;
}
