#include <string.h>
#include<stdlib.h>

char s[50]={"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
int number(char c)
{
    for(int i=0;i<34;i++)
    {
        if(c==s[i])
            return i;
    }
}
int main()
{
    int n,m=0;
    scanf("%d",&n);
    char a[30];
    char d,G;
    G=getchar();
    while((d=getchar())!=' ')
    {
        a[m++]=d;
    }
    a[m]='\0';
    int x;
    scanf("%d",&x);
    int p=0;
    long long num=0;
    for(;p<m;p++)
    {
        if(a[p]>='a'&&a[p]<='z') a[p]-=32;
        num+=number(a[p]);
        if(p<m-1)num*=n;
    }
    int q=0;
    char b[10000];
    if(num==0) b[0]='0';
    else {for(int j=x;num>0;num/=j)
        {
            int next;
            next=num%j;
            b[q++]=s[next];
        }
    b[q]='\0';
    for(int o=0,u=--q;o<u;o++,u--)
        {
            char c;
            c=b[u];
            b[u]=b[o];
            b[o]=c;
        }}
    printf("%s\n",b);
    return 0;

}

