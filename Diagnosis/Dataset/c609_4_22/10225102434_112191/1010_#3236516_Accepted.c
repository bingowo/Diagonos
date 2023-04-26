#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void Turn(long long int x,int n)
{
    char s[100],i,j;
    if(x == 0)
    {
        printf("0");
        return ;
    }
    for( i = 0;x!=0;i++)
    {
        if(x%n>=0)
        {
            s[i] = x%n;
            x/=n;
        }
        else
        {
            s[i] = (x%n-n);
            x = 1+x/n;
        }
    }
    for(j =i-1;j>=0;j--)
    {
        if(s[j]>9)
        {
            printf("%c",s[j]+'A'-10);
        }
        else printf("%d",s[j]);
    }
}
int main()
{
    long long int x;
    int n;
    scanf("%ld%d",&x,&n);
    Turn(x,n);
    return 0;
}
