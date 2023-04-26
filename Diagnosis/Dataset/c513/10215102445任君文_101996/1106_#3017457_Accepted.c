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
        if(w[0]==w[1])
            res=1;
        else
            res=4;
        for(i=2;i<L;i++)
        {
            if(w[i-1]==w[i-2])
            {
                if(w[i]==w[i-1])
                {
                    res=res*1;
                }
                else
                {
                    res=res*4;
                }
            }
            else if(w[i-1]!=w[i-2])
            {
                if(w[i-1]==w[i])
                {
                   res=res*1;
                }
                else if(w[i-1]!=w[i])
                {
                    if(w[i]==w[i-2])
                    {
                        res=res*2;
                    }
                    else
                    {
                        res=res*3;
                    }
                }
            }
            while(res>=M)
            {
                res=res-M;
            }
        }
        printf("%llu\n",res);
    }
	return 0;
}