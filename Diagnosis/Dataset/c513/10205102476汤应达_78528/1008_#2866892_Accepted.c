#include<stdio.h>

int main()
{
    int t;scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int x,y,res=0;
        scanf("%d%d",&x,&y);
        while (x!=0 || y!=0)
        {
            if((x&1)!=(y&1)) res++;
            x>>=1,y>>=1;
        }
        printf("%d\n",res);        
    }

    return 0;
}