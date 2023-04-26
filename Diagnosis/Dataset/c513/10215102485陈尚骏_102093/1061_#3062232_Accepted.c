#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct
{
    char s[200];
    int s1[200];
    unsigned long long res;
}r;

int cmp(const void*a,const void*b)
{
    r a_=*(r*)a;
    r b_=*(r*)b;
    if(a_.res>b_.res) return 1;
    else if(a_.res==b_.res) return strcmp(a_.s,b_.s);
    else return -1;
}
int main()
{
    int N;
    scanf("%d",&N);
    r* ans=(r*)malloc(sizeof(r)*20000);
    for(int i=0;i<N;i++)
    {
        ans[i].res=0;
        memset(ans[i].s1,0,sizeof(ans[i].s1));
        scanf("%s",ans[i].s);
        int n=0;
        for(int j=0;j<strlen(ans[i].s);j++)
        {
            if(ans[i].s1[ans[i].s[j]]==0)
            {
                n++;
                if(j==0) ans[i].s1[ans[i].s[j]]=1;
                else if(n==2) ans[i].s1[ans[i].s[j]]=-1;
                else if(n>2) ans[i].s1[ans[i].s[j]]=n-1;
            }
        }
        for(int j=0;j<strlen(ans[i].s);j++)
        {
            if(n==1) n=2;
            int m=ans[i].s1[ans[i].s[j]];
            if(m==-1) m+=1;
            ans[i].res=ans[i].res*n+m;
        }
    }
    qsort(ans,N,sizeof(r),cmp);
    for(int i=0;i<N;i++)
    {
        printf("%s\n",ans[i].s);
    }
    free(ans);
    return 0;
}
