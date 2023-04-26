#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    int n,r;
    for(int i=0;i<T;i++)
    {
        scanf("%d%d",&n,&r);
        int s=0,t=0,k=0;
        while(n)
        {
            s+=n%r;
            n/=r;
        }
        char ans[100];
        while(s)
        {
            t=s%r;
            s/=r;
            if(t>9)t=t-10+'A';
            else t=t+'0';
            ans[k++]=t;
        }
        printf("case #%d:\n",i);
        for(int j=k-1;j>=0;j--)
        printf("%c",ans[j]);
        printf("\n");
    }
    return 0;
}