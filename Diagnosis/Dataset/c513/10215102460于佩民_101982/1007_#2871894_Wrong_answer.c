#include <stdio.h>

int main()
{
    int t;scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n,num=0,a[2000]={0};
        scanf("%d",&n);
        while(n!=0)
        {
            a[num++]=(n%2);
            n/=2;
        }
        int cnt=1;
        int max=cnt;
        for(int i=1;i<num;i++)
        {   if(a[i]!=a[i-1]) cnt++;
            else
            {
                if(a[i]==0)
                {
                    cnt=0;continue;
                }
                else cnt=1;
            }
            if(max<cnt) max=cnt;
        }
        printf("case #%d:\n",i);
        printf("%d\n",max);


    }
    return 0;
}