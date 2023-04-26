#include <stdio.h>
#include <stdlib.h>
#define N 100000
typedef struct{char c; int cnt; } P;
//表示某个位置的字符c连续出现的次数cnt
P f[N][100];

int stat(char* s, P *r)
{
    int rcnt=0,cnt =0;
    char c;
    for(c=*s++;*s!='\0';cnt++,c=*s++)
        if(c!=*s)
            r[rcnt].c=c,r[rcnt++].cnt=cnt,cnt=0;
    r[rcnt].c=c,r[rcnt++].cnt=cnt;
    return rcnt;//返回值rcnt表示位置总数。
}
int cmp(const void *a,const void *b)//递增
 {
     return *(int*)a-*(int*)b;
}

int allsamelength_char(P (*f)[100],int n,int *fn)
{
    int i,j;
    for(i=1;i<n;i++)
        if(fn[i]!=fn[0])//不同字符的个数是否相同
            return 0;
    for(i=0;i<fn[0];i++)
        for(j=1;j<n;j++)
            if(f[j][i].c!=f[0][i].c)//同一位置字符是否相同
                return 0;
    return 1;
}
int main()
{
    int n,ans=0;
    scanf("%d",&n);
    int a[N]={0},len[N]={0};
    for(int i=0;i<n;i++)
    {
        char s[101]={0};
        scanf("%s",s);
        len[i]=stat(s,f[i]);
    }
    if ( allsamelength_char(f,n,len) )
    {
        for (int i=0;i<len[0];i++)
        {
            for (int j=0;j<n;j++)
                a[j]=f[j][i].cnt;
            qsort(a,n,sizeof(a[0]),cmp);//a[n/2]即为中位数
            for (int j=0;j<n;j++)
                ans+=abs(a[j]-a[n/2]);//差的绝对值总和即为最少变换次数
        }
        printf("%d\n",ans);
    }
    else
        printf("-1\n");
    return 0;
}
