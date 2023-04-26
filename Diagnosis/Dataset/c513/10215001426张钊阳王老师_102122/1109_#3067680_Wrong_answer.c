#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);

    for(int i=0;i<T;i++)
    {
        int num[9]={0};
        for(int i=8;i>=0;i--)
        {
            scanf("%d",&num[i]);
        }

        printf("case #%d:\n",i);

        int flag=1;//flag=0时为全0
        int i=0;
        int cnt=0;
        for(int i=0;i<=8;i++)
        {
            if(num[i]==0) cnt++;
        }

        if(cnt==9) flag=0;

        int startflag=0;

        if(flag==0)
        {
            printf("0\n");
        }
        else if(flag==1)
        {
            for(int i=8;i>1;i--)
            {
                if(num[i]==0) continue;
                else {
                    if(num[i]==1)
                    {
                        if(startflag==0)
                        {
                            printf("x^%d",i);
                            startflag=1;
                        }
                        else printf("+x^%d",i);
                    }
                    else if(num[i]==-1)
                    {
                        if(startflag==0)
                        {
                            printf("-x^%d",i);
                            startflag=1;
                        }
                        else printf("-x^%d",i);
                    }
                    else
                    {
                        if(startflag==0)
                        {
                            printf("%dx^%d",num[i],i);
                            startflag=1;
                        }
                        else
                        {
                            if(num[i]>0)
                            {
                                printf("+%dx^%d",num[i],i);
                            }
                            else
                            {
                                printf("%dx^%d",num[i],i);
                            }
                        }
                    }
                    }
            }
            if(num[1]==0);
            else
            {
                if(num[1]>0)
                {
                    if(startflag==0)
                    {
                        if(num[1]==1) printf("x");
                        else printf("%dx",num[1]);
                        startflag=1;
                    }
                    else
                    {
                        if(num[1]==1) printf("+x");
                        else printf("+%dx",num[1]);
                    }
                }
                else printf("%dx",num[1]);
            }
            if(num[0]==0);
            else if(num[0]!=0)
            {
                if(num[0]>0)
                {
                    if(startflag==0)
                    {
                        printf("%d",num[0]);
                        startflag=1;
                    }
                    else
                    {
                        printf("+%d",num[0]);
                    }
                }
                else printf("%d",num[0]);
            }
            printf("\n");
        }
    }

    return 0;
}


void print(int num,int a)
{




}
