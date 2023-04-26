#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int a,b,a1[1000]={0},b1[1000]={0};
        scanf("%d %d",&a,&b);
        int cnt=0,c=a^b;
        while(c!=0)
        {
            cnt+=c%2;
            c=c>>1;
        }
        printf("%d\n",cnt);
    }
    return 0;
}



