#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100
void an(int ans[],int n,int a)
{
    int p,temp=0;
    for(int i=0;i<n;i++)
    {
        for(int k=0;k<N;k++)
        {
            p=ans[k]*a+temp;
            ans[k]=p%10;
            temp=p/10;

        }

    }
}
void print(int a[])
{
    int i;
    for(i=N-1;a[i]==0&&i>=0;i--);
    for(;i>=0;i--)
        printf("%d",a[i]);
    printf("\n");
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int ans[N]={1};
        int a,n;
        scanf("%d %d",&a,&n);
        an(ans,n,a);
        printf("case #%d:\n",i);
        print(ans);


    }
    return 0;
}
