#include<stdio.h>
#include<string.h>
int main()
{
    int t;//组数
    char s[1000];
    scanf("%d%s",&t,&s);
    for(int i=0;i<t;i++){
        printf("case #%d:\n",i);
        printf("%d\n",f(s));
    }
    return 0;
}

void f(char s[1000])
{
    int a=0;//转化后的结果
    int i=0;//读取字符串
    while((s=getchar())!='\n'){
        if(s[i]=='1'){
            a=a*3+1;
        }
        else if(s[i]=='0'){
            a=a*3;
        }
        else{
            a=a*3-1;
        }
        i++;
    }
    return a;
}