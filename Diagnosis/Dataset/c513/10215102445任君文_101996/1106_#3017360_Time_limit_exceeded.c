#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define M 1000000007
int main()
{
    int i,j;
    int L=0;
    long long res=1;
    char w[1000]={0};
    scanf("%s",w);
    L=strlen(w);
    for(i=1;i<L-1;L++)
    {
        res=res*11;
        if(res>=M)
        {
            res=res-M;
        }
    }
    printf("%lld\n",res);
	return 0;
}