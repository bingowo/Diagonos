#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct
{
    char c;
    int cnt;
}PAIR;
int cmp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}
int stat(char*s,PAIR*r)
{
    int rcnt=0,cnt=0;
    char prev;
    for(prev=*s++;*s;cnt++,prev=*s++)
    {
        if(*s!=prev)
        {
            r[rcnt].c=prev;
            r[rcnt++].cnt=cnt;
            cnt=0;
        }
    }
    r[rcnt].c=prev;
    r[rcnt++].cnt=cnt;
    return rcnt;
}
int allsame(PAIR (*f)[100],int n,int *fn)
{
    int i,j;
    for(i=1;i<n;i++)
    {
        if(fn[i]!=fn[i-1])return 0;
    }
    for(i=0;i<fn[0];i++)
    {
        for(j=1;j<n;j++)
        {
            if(f[j][i].c!=f[0][i].c)return 0;
        }
    }
    return 1;
}
int main()
{
    int n,sum=0;
    scanf("%d",&n);
    PAIR ans[n][100];
    int a[n],fn[n];
    for(int i=0;i<n;i++)
    {
        char s[101];
        scanf("%s",s);
        fn[i]=stat(s,ans[i]);

    }
    if(allsame(ans,n,fn))
    {
        for(int i=0;i<fn[0];i++)
        {
            for(int j=0;j<n;j++)
                a[j]=ans[j][i].cnt;
            qsort(a,n,sizeof(a[0]),cmp);
            for(int j=0;j<n;j++)
            {
                sum+=abs(a[j]-a[n/2]);
            }
        }
        printf("%d\n",sum);

    }
    else
        printf("-1\n");
    return 0;

}
