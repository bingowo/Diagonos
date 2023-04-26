//longlong类型 转化后数字太长。整数形式用那个空格分隔
#include<stdio.h>
int main(){
    int t,i;
    long long int a;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&a);
        long long int s[10000000]={0};
        f(a,s);
        printf("\n");
    }
    return 0;
}
void f(long long int a,long long int s[10000000])
{
    int j=0;
    char b;
    do
    {
        s[j++] = a% 2333;
        a = a/2333;
    }
    while(a);
    {
        for (--j; j >= 1; j--)
            printf("%d ", s[j]);//逆序输出转换的进制数
    }
    printf("%d",s[0]);
}
