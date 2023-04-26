#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct ch
{
    char s[35];
    int len;
};
void equal(int n,int num,int a[])
{
    for(int i=0;i<num;i++)
    {
        a[i]+=1;
    }
    n=n-num;
    while(n)
    {
        for(int i=num-1;i>=0;i--)
        {
            a[i]+=1;
            n--;
            if(n==0)break;
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int m,index=0;
        scanf("%d",&m);
        getchar();
        struct ch ans[2000];
        while(1)
        {
            scanf("%s",ans[index].s);
            ans[index].len=strlen(ans[index].s);
            char c=getchar();
            if(c=='\n') break;
            index++;
        }
        printf("case #%d:\n",i);
        for(int j=0;j<=index;j++)
        {
            int k,num=0,Len=0,temp=0,ret[70]={0};
            for(k=j;k<=index;k++)
            {
                Len=Len+ans[k].len;
                num++;
                if(num+Len-1>m)
                {
                    Len-=ans[k].len;
                    num--;
                    temp=1;
                    break;
                }
            }
            if(temp)
            {
            equal(m-Len,num-1,ret);
            printf("%s",ans[j].s);
            for(int l=0;l<num-1;l++)
            {
                for(int p=0;p<ret[l];p++)
                    printf("%c",' ');
                j++;
                printf("%s",ans[j].s);
            }
            printf("\n");
            }
            else
            {
                printf("%s",ans[j].s);
                num--;
                while(num)
                {
                    j++;
                    printf(" %s",ans[j].s);
                    num--;
                }
                printf("\n");
            }

        }

    }
   return 0;
}

