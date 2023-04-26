#include<stdio.h>
#include<string.h>
char num[32];
int change(int a,int b,char c[])
{
    int l,m=0;
    if(a<0)a=-a;
    while(a>0)
    {
        l=a%b;
        if(l<10&&l>=0)c[m]='0'+l;
        if(l>=10)c[m]='A'+l-10;
        a=a/b;
        m++;
    }
    return m;
}
int main()
{
    int T,N,R,i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        int j,k;
        scanf("%d %d",&N,&R);
        k=change(N,R,num);
        if(N<0)printf("-");
        for(j=k-1;j>=0;j--)printf("%c",num[j]);
        printf("\n");
    }
    return 0;
}
