#include<stdio.h>
int main()
{
    int i=0,T,a;//问题编号,问题数,输入的测试数据
    scanf("%d",&T);
    int n;//非重复二进制串的长度
    for(i=0;i<=T;i++){
        scanf("%d",&a);
        f(a,n);
        printf("case #%d\n:",i);
        printf("%d\n",n);

    }
    return 0;
}
void f(int a,int n)
{
    // TODO: your function definition
    int s[100000000]={0};
    int j=0;
    n=1;
    while(a){
           s[j++] = a% 2;//从后往前放
           a = a/2;
    }
    while(j!=0){
        if(s[j]!=s[j-1]){
                n=n+1;
    }
        j--;
    }
    return 0;
}
