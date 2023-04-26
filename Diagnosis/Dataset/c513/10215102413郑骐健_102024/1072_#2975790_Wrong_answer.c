#include <stdio.h>
#include <stdlib.h>


int main()
{
    int E =-1,W=1,N = -1,S=1;
    char s[200]={0};
    long long x,y;
    scanf("%lld%lld",&x,&y);
    int n=0;
    if(!((x+y)%2))printf("-1");
    else
    {

        while(x!=0||y!=0)
        {

            if(x%2)
            {

                if((y/2)%2)
                {
                    if(((x+W)/2)%2==0)
                    {
                        s[n] = 'W';
                        x+=W;
                    }
                    else
                    {
                        s[n]='E';
                        x+=E;
                    }
                }
                else
                {
                    if(y==0&&x==1)
                    {s[n]='E';
                        x+=E;
                    }
                    if(y==0&&x==-1)
                    {s[n]='W';
                        x+=W;
                    }
                    else if(((x+W)/2)%2)
                    {
                        s[n] ='W';
                        x+=W;
                    }
                    else
                    {
                        s[n]='E';
                        x+=E;
                    }
                }
            }
            else
            {
                if((x/2)%2)
                {
                    if(((y+N)/2)%2==0)
                    {
                        s[n] = 'N';
                        y+=N;
                    }
                    else
                    {
                        s[n]='S';
                        y+=S;
                    }
                }
                else
                {
                    if(x==0&&y==1)
                    {
                        s[n]='N';
                        y+=N;
                    }
                    else if(x==0&&y==-1)
                    {
                        s[n]='S';
                        y+=S;
                    }
                    else if(((y+N)/2)%2)
                    {
                        s[n] ='N';
                        y+=N;
                    }
                    else
                    {
                        s[n]='S';
                        x+=S;
                    }
                }
            }
            n++;

            x/=2;y/=2;
        }
    }
        printf("%d\n",n);
        for(int i =0;i<n;i++)
        {
            printf("%c",s[i]);
        }

    return 0;
}
