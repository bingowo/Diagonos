#include<stdio.h>
#include<string.h>
int main()
{
    int t;//组数
    char s;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int a=0;
        f(s,a);
        printf("%d\n",a);
    }
    return 0;
}

void f(char s,int a)
{
    //转化后的结果
    while((s=getchar())!='\n'){
        if(s=='1'){
            a=a*3+1;
        }
        else if(s=='0'){
            a=a*3;
        }
        else{
            a=a*3-1;
        }
    }
    return a;
}