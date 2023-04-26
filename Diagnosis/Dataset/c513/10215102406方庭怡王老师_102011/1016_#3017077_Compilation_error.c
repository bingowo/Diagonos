#include<stdio.h>
#include<string.h>
char c[110];
int n,m,k,sum;
int read()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int main()
{
    n=read(),m=read();
    while(n)
    {
        k=n%m;
        n/=m;
        if(k<0) k-=m,n+=1;
        if(k>9) c[++sum]=char(k-10+'A');
        else c[++sum]=char(k+'0');
    }
    for(int i=sum;i>=1;i--)
     printf("%c",c[i]);
    return 0;
}