#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct file
{
    char data[15];
    char time[10];
    long long data1;
    long long time1;
    long long size;
    int wei;
    char name[64];
};

int cmp1(const void* a,const void* b)
{
    struct file* x;
    struct file* y;
    x=(struct file*) a;
    y=(struct file*) b;
    return (strcmp(x->name,y->name));
}

int cmp2(const void* a,const void* b)
{
    struct file* x;
    struct file* y;
    x=(struct file*) a;
    y=(struct file*) b;
    if(x->size==y->size)
    {
        return (strcmp(x->name,y->name));
    }
    return (x->size-y->size);
}

int cmp3(const void* a,const void* b)
{
    struct file* x;
    struct file* y;
    x=(struct file*) a;
    y=(struct file*) b;
    if(x->data1==y->data1)
    {
        if(x->time1==y->time1)
        {
            return (strcmp(x->name,y->name));
        }
        return (x->time1-y->time1);
    }
    return (x->data1-y->data1);
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
        {
            return 0;
        }
        struct file ans[101];
        for(int i=0;i<n;i++)
        {
            scanf("%s",ans[i].data);
            scanf("%s",ans[i].time);
            scanf("%lld",&ans[i].size);
            scanf("%s\n",ans[i].name);
            /*判断文件大小位数，用于计算输出的空格数
            ans[i].wei=1;
            long long temp=ans[i].size;
            while(temp/10!=0)
            {
                ans[i].wei++;
                temp=temp/10;
            }
            ans[i].wei=16-ans[i].wei;*/

            /*把日期和时间转化成数值，方便比较*/
            ans[i].data1=0;
            ans[i].time1=0;
            for(int j=0;j<10;j++)
            {
                if(ans[i].data[j]!='-')
                {
                    ans[i].data1=ans[i].data1*10+ans[i].data[j]-48;
                }
            }
            for(int j=0;j<5;j++)
            {
                if(ans[i].time[j]!=':')
                {
                    ans[i].time1=ans[i].time1*10+ans[i].time[j]-48;
                }
            }
        }

        /*判断排序标准*/
        char flag[5];
        scanf ("%s",flag);
        scanf ("%s",flag);

        /*分三种情况输出*/
        if(flag[1]=='N')
        {
            qsort(ans,n,sizeof(ans[0]),cmp1);
            for(int i=0;i<n;i++)
            {
                for(int p=0;p<10;p++)
                {
                    printf("%c",ans[i].data[p]);
                }
                printf(" ");
                for(int p=0;p<5;p++)
                {
                    printf("%c",ans[i].time[p]);
                }
                printf("%17lld %s\n",ans[i].size,ans[i].name);
            }
        }
        if(flag[1]=='S')
        {
            qsort(ans,n,sizeof(ans[0]),cmp2);
            for(int i=0;i<n;i++)
            {
                for(int p=0;p<10;p++)
                {
                    printf("%c",ans[i].data[p]);
                }
                printf(" ");
                for(int p=0;p<5;p++)
                {
                    printf("%c",ans[i].time[p]);
                }
                printf("%17lld %s\n",ans[i].size,ans[i].name);
            }
        }
        if(flag[1]=='T')
        {
            qsort(ans,n,sizeof(ans[0]),cmp3);
            for(int i=0;i<n;i++)
            {
                for(int p=0;p<10;p++)
                {
                    printf("%c",ans[i].data[p]);
                }
                printf(" ");
                for(int p=0;p<5;p++)
                {
                    printf("%c",ans[i].time[p]);
                }
                printf("%17lld %s\n",ans[i].size,ans[i].name);
            }
        }
        printf("\n");

    }
    return 0;
}
