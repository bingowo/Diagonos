#include<stdio.h>
int main()
{
    int T;scanf("%d",&T);
    for(int cas=0;cas<T;++cas)
    {
        int cnt=0,x;
        printf("case #%d:\n",cas);
        for(int i=8;i>=0;--i)
        {
            scanf("%d",&x);
            if(x>0)
            {
                if(x==1)
                {
                    if(i!=1&&i!=0)printf("+x^%d",i);
                    else if(i==1)printf("+x");
                    else if(!i)printf("+1");
                }
                else
                {
                    if(i!=1&&i!=0)printf("+%dx^%d",x,i);
                    else if(i==1)printf("+%dx",x);
                    else if(!i)printf("+%d",x);
                }
                cnt++;
            }
            else if(x<0)
            {
                if(x==-1)
                {
                    if(i!=1&&i!=0)printf("-x^%d",i);
                    else if(i==1)printf("-x");
                    else if(i==0)printf("-1");
                }
                else
                {
                    if(i!=1&&i!=0)printf("%dx^%d",x,i);
                    else if(i==1)printf("%dx",x);
                    else if(!i)printf("%d",x);
                }
                cnt++;
            }
        }
        if(!cnt)printf("0");
        printf("\n");
    }
    return 0;
}