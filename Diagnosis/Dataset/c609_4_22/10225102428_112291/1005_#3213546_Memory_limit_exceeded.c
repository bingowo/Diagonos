#include<stdio.h>
#include<string.h>
int main()
{
    int t;//组数
    char s;
    scanf("%d%s",&t,&s);
    for(int i=0;i<t;i++){
        printf("case #%d:\n",i);
        printf("%d\n",f(s));
    }
    return 0;
}

void f(char s)
{
    int a=0;//转化后的结果
//读取字符串
    while((s=getchar())!=EOF){
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
