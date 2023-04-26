#include<stdio.h>
#include<stdlib.h>
int main()
{
    int T,n;
    scanf("%d",&T);
    for(int i=0; i<T; i++)
    {
        scanf("%d",&n);
        int flag,t,m=1,l=1;
        flag=n%2;
        n=n>>1;
        while(n)
        {
            t=n%2;
            if(flag==t)l=1;
            else l++;
            m=l>m?l:m;
            flag=t;
            n=n>>1;
        }
        printf("case #%d:\n%d\n",i,m);
    }
    return 0;
}