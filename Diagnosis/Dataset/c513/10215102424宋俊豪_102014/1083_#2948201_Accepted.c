#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int cnt,t,n,p;
    scanf("%d",&t);
    for(int i=0; i<t; i++)
    {
        cnt=0;
        scanf("%d",&n);
        for(int j=1; j<=n; j++)
        {
            if(j%10==0)
            {
                cnt++;
                p=j/10;
                 while(p%10==0&&p>0)
                {
                    cnt++;
                    p=p/10;
                }
                while(p%5==0&&p>0)
                {
                    cnt++;
                    p=p/5;
                }
            }
            else if(j%5==0)
            {
                cnt++;
                p=j/5;
                while(p%5==0&&p>0)
                {
                    cnt++;
                    p=p/5;
                }
            }
        }
        printf("case #%d:\n",i);
        printf("%d\n",cnt);
    }
    return 0;
}

