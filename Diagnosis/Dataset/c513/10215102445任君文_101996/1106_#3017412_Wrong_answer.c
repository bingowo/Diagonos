#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define M 1000000007
int main()
{
    int i,j;
    int L=0;
    unsigned long long res=1;
    char w[1000]={0};
    scanf("%s",w);
    L=strlen(w);
    if(L==1)
        printf("1\n");
    else if(L==2)
    {
        if(w[1]==w[0])
        {
            printf("1\n");
        }
        else
        {
            printf("4\n");
        }
    }
    else
    {
        for(i=1;i<L-1;i++)
        {
            if(w[i-1]==w[i])
            {
                if(w[i]==w[i+1])
                {
                    res=res*1;
                }
                else
                {
                    res=res*4;
                }
            }
            else if(w[i-1]!=w[i])
            {
                if(w[i-1]==w[i+1])
                {
                   res=res*8;
                }
                else if(w[i-1]!=w[i+1])
                {
                    if(w[i]==w[i+1])
                    {
                        res=res*4;
                    }
                    else
                    {
                        res=res*12;
                    }
                }
            }
            if(res>=M)
            {
                res=res-M;
            }
        }
        printf("%llu\n",res);
    }
	return 0;
}