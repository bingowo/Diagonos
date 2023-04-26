#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T,N,R;
    char s[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i,j=0,temp=0;
    int res[100]={0};
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d%d",&N,&R);
        if(N<0)
        {
            printf("-");
            N=-N;
        }
        else if(N==0)
        {
            printf("0\n");
            continue;
        }
        while(N>0)
        {
            res[j]=N%R;
            N=N/R;
            j++;
        }
        while(j>0)
        {
            printf("%c",s[res[j]]);
            j--;
        }
        printf("\n");
    }
    return 0;
}