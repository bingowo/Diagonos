#include<stdio.h>
#include <stdlib.h>
int main()
{
    int i=0,T,a;//问题编号,问题数,输入的测试数据
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",&a);
        int n=1;//非重复二进制串的长度
        f(a,n);
        printf("case #%d:\n",i);
        printf("%d\n",n);

    }
    return 0;
}
void f(int a,int n)
{
    // TODO: your function definition
    int s[100000000]={0};
    int j=0;
    while(a){
           s[j++] = a% 2;//从后往前放
           a = a/2;
    }
    int cnt=1;
    n=1;
    for(int i=1;i<j;i++)
    {
            //for(int j=i+1;j<cnt;j++)
        if(s[i]!=s[i-1]) cnt++;
        else
        {
            if(s[i]==0)
            {
                cnt=0;
                continue;
            }
            else cnt=1;
        }
        if(n<cnt) n=cnt;
        }
