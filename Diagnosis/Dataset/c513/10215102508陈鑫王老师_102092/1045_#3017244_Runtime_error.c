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
int main()
{
    int n;
    scanf("%d",&n);
    PAIR ans[n][100];
    int ret[100],temp=0;
    for(int i=0;i<n;i++)
    {
        char s[101];
        scanf("%s",s);
        ans[i][0].c=s[0];
        ans[i][0].cnt=1;
        int index=0,count=1;
        for(int j=1;j<strlen(s);j++)
        {
            if(s[j]==s[j-1])
            {
                count++;
            }
            else
            {
                ans[i][index].cnt=count;
                count=1;
                index++;
                ans[i][index].c=s[j];
                ans[i][index].cnt=count;
            }
            if(j==strlen(s)-1)
                ans[i][index].cnt=count;
        }
        ret[temp++]=index;
    }
    int flag=1;
    for(int i=1;i<temp;i++)
    {
        if(ret[i]!=ret[i-1])
        {
            flag=0;
            break;
        }

    }
    if(flag)
    {
            for(int j=0;j<=ret[0];j++)
            {
                for(int i=1;i<n;i++)
                {
                    if(ans[i][j].c!=ans[i-1][j].c)
                    {
                        flag=0;
                        break;
                    }
                }
            }
    }
    if(flag==0)printf("-1\n");
    else
    {
        int sum=0;
        for(int k=0;k<=ret[0];k++)
        {

           int a[n];
        for(int i=0;i<n;i++)
        {
            a[i]=ans[i][k].cnt;
        }
        qsort(a,n,sizeof(a[0]),cmp);
        for(int i=0;i<n;i++)
        {
            sum+=abs(a[i]-a[n/2]);
        }
        }
        printf("%d\n",sum);

    }
    return 0;

}
