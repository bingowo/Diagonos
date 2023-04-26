#include <stdio.h>
#include <stdlib.h>

void f1();
void f2();
void f3();
int sign=0;

void f()
{
   char ch;
   while((ch=getchar())!=EOF&&ch!='\n')
    {
        if(ch=='(') f1();
        else if(ch=='{') f2();
        else f3();
    }
    if(sign==1) return;
    printf("Yes\n");
    return;
}

void f1()
{
    char ch;
    while((ch=getchar())!=EOF&&ch!='\n')
    {
        if(ch=='['||ch==']'||ch=='}')
        {
            if(sign==0) {printf("No\n");sign=1;return;}
         }
        else if(ch=='{') f2();
        else return;
    }
    return;
}

void f2()
{
    char ch;
    while((ch=getchar())!=EOF&&ch!='\n')
    {
        if(ch=='('||ch==')'||ch==']')
        {
            if(sign==0) {printf("No\n");sign=1;return;}
        }
        else if(ch=='[') f3();
        else return;
    }
    return;
}
void f3()
{
    char ch;
    while((ch=getchar())!=EOF&&ch!='\n')
    {
        if(ch=='{'||ch=='}'||ch==')')
        {
            if(sign==0){printf("No\n");sign=1;return;}
        }
        else if(ch=='(') f1();
        else return;
    }
    return;
}



int main()
{
    int T=0;
    scanf("%d",&T);
    getchar();
    for(int i=0;i<T;i++)
    {
       f();
       sign=0;
    }
    return 0;
}