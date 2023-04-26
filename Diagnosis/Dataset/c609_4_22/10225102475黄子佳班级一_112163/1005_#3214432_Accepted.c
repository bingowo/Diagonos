#include <stdio.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        char s[100];
        scanf("%s",s);
        int sum=0;
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i]=='-')sum=sum*3-1;
            if(s[i]=='1')sum=sum*3+1;
            if(s[i]=='0')sum=sum*3;
        }
        printf("case #%d:\n%d\n",cas,sum);
    }
    return 0;
}