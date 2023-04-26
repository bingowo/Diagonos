#include <stdio.h>
#include <stdlib.h>

void jisuan(int h)
{
    char s[150]={0};
    scanf("%s",s);
     int i=0,j=strlen(s);
     int t[4],cnt[4],a[4];memset(t,0,sizeof(int)*4);memset(cnt,0,sizeof(int)*4);memset(a,0,sizeof(int)*4);
    for(i=0;s[i];i++)
    {   t[i%4]++;
        switch(s[i])
        {
            case 'R':cnt[0]++;a[0]=i%4;break;
            case 'B':cnt[1]++;a[1]=i%4;break;
            case 'Y':cnt[2]++;a[2]=i%4;break;
            case 'G':cnt[3]++;a[3]=i%4;break;
            default:break;
        }
    }
    printf("case #%d:\n",h);
    printf("%d %d %d %d\n",t[a[0]]-cnt[0],t[a[1]]-cnt[1],t[a[2]]-cnt[2],t[a[3]]-cnt[3]);
}
int main()
{
    int N,h;
    scanf("%d",&N);
    for(h=0;h<N;h++)jisuan(h);
}
