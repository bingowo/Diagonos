#include <stdio.h>
#define N 100
void main(void)
{
    int t,n,r,remainder,j=0;
    char s[N];
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d %d",&n,&r);
        j=0;
        while (n!=0)
        {
            remainder=n%r;
            n=n/r;
            s[j]=remainder>10?'A'+remainder-10:'0'+remainder;
            j++;
            
        }
        j--;
        for (j;j>-1;j--)
        {
            printf("%c",s[j]);
            if(j==0)    printf("\n");
        }
    }
}