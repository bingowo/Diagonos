#include <stdio.h>
#include <stdlib.h>
void jisuan(int h)
{
    char s[100];
    char a[100];
    int i;
    long long m=0,k=0;
    int t[128];memset(t,-1,sizeof(t));
    scanf("%s",s);
    t[s[0]]=1;
    for(i=1;s[i];i++)
    {
        if(t[s[i]]==-1)
        {
            t[s[i]]=k;
            if(k==0)k=2;else k++;
        }
    }
    for(i=0;s[i];i++)
    {
        m=m*k+t[s[i]];
    }
    printf("case #%d:\n",h);
    printf("%lld\n",m);
}
int main()
{
    int N,h;
    scanf("%d",&N);
    for(h=0;h<N;h++)jisuan(h);
    return 0;
}
