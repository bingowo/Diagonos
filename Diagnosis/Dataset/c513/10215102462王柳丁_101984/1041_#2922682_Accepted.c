#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int i,res=0,count=1;
    char s[51];
    scanf("%s",s);
    int n=strlen(s);
    if(n==1)res=1;
    else
    {
        for(i=1;i<n;i++)
        {
            if(s[i]!=s[i-1])count++;
            else count=1;
            if(count>res)res=count;
        }
    }
    printf("%d\n",res);
    return 0;
}
