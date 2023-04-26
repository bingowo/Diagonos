#include<stdio.h>
int main()
{
    int T,n,m,i,j,t,cnt,max;
    int num[50];
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&n);
        t=0;
        cnt=1;
        max=1;
        while(n!=0)
        {
            num[t++]=n%2;
            n=n/2;
        }
        for(j=0;j<t-1;j++)
        {
            if(num[j]!=num[j+1])
            {
                cnt++;
            }
            else
            {
                if(cnt>max)  max=cnt;
                cnt=1;
            }
        }
        if(cnt>max)  max=cnt;
        printf("case #%d:\n%d\n",i,max);
    }
    return 0;
}