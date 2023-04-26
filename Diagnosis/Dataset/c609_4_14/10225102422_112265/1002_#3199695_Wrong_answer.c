#include<stdio.h>
#define N 32
int max(int sum[N],int in)
{
    int max=sum[0];
    int i=0;
    for(i=1;i<in;i++)
    {
        if(max<sum[i])
        max=sum[i];
    }
}
int main()
{
    int T;
    int s[N];
    int sum[N];
    scanf("%d",&T);
    int i=0;
    int n,in;
    for(i=0;i<T;i++)
    {
        scanf("%d",&n);
        int j=0;
        int count=1;
        while(n!=0)
        {
            s[j]=n%2;
            n=n/2;
            j++;
        }
        int index;
        for(index=j-1,in=0;index>0;index--)
        {
            if(s[index]!=s[index-1])
            count=count+1;
            else if(s[index]==s[index-1])
            {
                sum[in]=count;
                count=1;
                in++;
            }
        }
        printf("case #%d:\n",i);
        if(in==0)
        printf("%d\n",count);
        else
        printf("%d\n",max(sum,in));
    }
    return 0;
}