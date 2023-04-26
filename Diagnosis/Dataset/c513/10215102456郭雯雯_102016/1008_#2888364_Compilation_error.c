#include<stdio.h>
int num(long long int a)//判断数据a中1的个数
{
    int n=0,i=64;
    long long int m=1;
    while(i>0){
        if(a&m)n++;
        m=m<<1;
        i--;
    }
    return n;
}
int main()
{
    int t,m=0;
    long long int x,y,z;
    scanf("%d",&t);
    while(m<t){
        int n;#include<stdio.h>
int num(long long int a)//判断数据a中1的个数
{
    int n=0,i=64;
    long long int m=1;
    while(i>0){
        if(a&m)n++;
        m=m<<1;
        i--;
    }
    return n;
}
int main()
{
    int t,m=0;
    long long int x,y,z;
    scanf("%d",&t);
    while(m<t){
        int n;
        scanf("%d %d",&x,&y);
        z=x^y;
        n=num(z);
        printf("%d\n",n);
        m++;
    }
}

        scanf("%d %d",&x,&y);
        z=x^y;
        n=num(z);
        printf("%d\n",n);
        m++;
    }
    return 0;
}