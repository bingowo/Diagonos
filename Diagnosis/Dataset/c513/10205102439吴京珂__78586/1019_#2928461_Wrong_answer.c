#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int s1[11]= {0}; //积分
int s2[11]= {0}; //胜场
int s3[11]= {0}; //负场

int f(int a,int b,int c)
{
    if(c==1)
    {
        s1[a]+=3;
        s1[b]-=1;
        s2[a]+=1;
        s3[b]+=1;
    }
    else if(c==-1)
    {
        s1[b]+=3;
        s1[a]-=1;
        s2[b]+=1;
        s3[a]+=1;
    }
    else if(c==0)
    {
        s1[b]+=1;
        s1[a]+=1;
    }
}

int cmp(const void *a1,const void *b1)//比较函数
{
    int a=*(int*)a1;
    int b=*(int*)b1;
    if(s1[a]>s1[b]) return -1;
    else if(s1[a]<s1[b]) return 1;
    else
    {
        if(s2[a]>s2[b]) return -1;
        else if(s2[a]<s2[b]) return 1;
        else
        {
            if(s3[a]<s3[b]) return -1;
            else if(s3[a]>s3[b]) return 1;
            else
            {
                if(a<b) return -1;
                else return 1;
            }
        }
    }
}

int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF)//多组输入
    {
        if(n==0&&m==0) break;
        for(int i=0; i<m; i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            f(a,b,c);

        }
        int ans[10]= {1,2,3,4,5,6,7,8,9,10};
        qsort(ans,n,sizeof(ans[0]),cmp);
        for(int i=0; i<n-1; i++)
        {
            printf("%d ",ans[i]);
        }
        printf("%d\n",ans[n-1]);

    }
    return 0;
}
