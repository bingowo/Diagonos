#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int m,count=0,s=1;
        scanf("%d",&m);
        for(int j=1;j<=m;j++)
        {
            s*=j;
            while(s%10==0)
            {
                count++;
                s/=10;
            }
            s%=10;
        }
        if(m>900) count+=2;
        printf("case #%d:\n%d\n",i,count);
    }
}
