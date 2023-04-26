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
    int j=0;//读取字符串
    while(j<strlen(s)){
        if(s[j]=='1'){
            a=a*3+1;
        }
        else if(s[j]=='0'){
            a=a*3;
        }
        else{
            a=a*3-1;
        }
        j++;
    }
    return a;
}
