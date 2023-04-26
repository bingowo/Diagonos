#include <stdio.h>
#include <stdlib.h>
void itob(int n,char *s,int r)
{
    const char table[]={"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    int sigh=1,m=0;
    if(n<0)
    {
        sigh=-1;
        n=-n;
    }
    do
    {
        *(s+m)=table[n%r];
        n=n/r;
        m+=1;
    }
    while(n);
    if(sigh==-1)
    {
        *(s+m)='-';
        *(s+m+1)=0;
        for(int i=0;i<m/2+1;i++)
        {
            int temp=*(s+i);*(s+i)=*(s+m-i);*(s+m-i)=temp;
        }
    }
    else
    {
        *(s+m)=0;
        for(int i=0;i<m/2;i++)
        {
            int temp=*(s+i);*(s+i)=*(s+m-i);*(s+m-i)=temp;
        }
    }

}
int main()
{
    int t,n,r;
    char s[100],*ps;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d %d",&n,&r);
        ps=&s[0];
        itob(n,ps,r);
        printf("%s\n",s);
    }
    return 0;
}