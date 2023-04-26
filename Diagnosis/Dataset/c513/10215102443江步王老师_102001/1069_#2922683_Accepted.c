#include<stdio.h>

int reverse(int n);
int judge(int n);
int main()
{
    int n,m,s;
    int i=0;
    scanf("%d",&n);
    m=reverse(n);
    s=n+m;
    i++;
    //printf("s=%d\ni=%d\n",s,i);
    while (!judge(s)){
        n=s;
        m=reverse(n);
        s=m+n;
        i++;
        //printf("s=%d\ni=%d\n",s,i);
    }
    printf("%d ",i);
    printf("%d",s);
    return 0;
}

int reverse(int n)//倒转n
{
    int t[10]={0};
    int i=0,j=0;
    int res=0;
    while (n>0){
        t[i]=n%10;
        n=n/10;
        i++;
    }
    while (i>0){
        res=res*10+t[j];
        j++;
        i--;
    }
    return res;
}

int judge(int n)//判断是否为回文数
{
    int t[10]={0};
    int flag=0;
    int len;
    int i=0;
    while (n>0){
        t[i]=n%10;
        n=n/10;
        i++;
    }
    len=i;//len保存该数的长度
    i=0;
    while (i<len/2){
        if (t[i] != t[len-1-i]){
            return flag;
        }
        i++;
    }
    flag=1;
    return flag;
}