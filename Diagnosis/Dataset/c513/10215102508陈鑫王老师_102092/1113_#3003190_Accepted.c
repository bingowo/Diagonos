#include<stdio.h>
#include<stdlib.h>
typedef struct
{
int b[31];
}BIG;
void add(int a[],int b[])
{
    int t;
    for(int i=0;i<30;i++)
    {
        t=a[i]+b[i];
        if(t>9)
        {
            a[i+1]+=t/10;;
        }
        a[i]=t%10;
    }
}
void print(int a[])
{
    int i;
    for(i=30;a[i]==0&&i>=0;i--);
    if(i<0)printf("0");
    else
    {
        for(;i>=0;i--)
        {
            printf("%d",a[i]);
        }
    }

}
int main()
{
    int k,n;
    scanf("%d %d",&k,&n);
    BIG ans[100];
    memset(ans,0,sizeof(ans));
    for(int i=0;i<n;i++)
    {
        if(i==0)ans[i].b[0]=0;
        else if(i==1)ans[i].b[0]=1;
        else
        {
            if(i<k)
            {
                for(int j=i-1;j>=0;j--)
                {
                    add(ans[i].b,ans[j].b);
                }
            }
            else
            {
                for(int j=i-1;j>=i-k;j--)
                {
                    add(ans[i].b,ans[j].b);
                }

            }
        }

    }
    print(ans[n-1].b);
    return 0;
}
