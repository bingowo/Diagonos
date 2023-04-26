#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char s[106];
        scanf("%s",s);
        int len=strlen(s);
        int R=0,B=0,Y=0,G=0;
        while(len%4!=0) len--;
        int n=len/4;
        for(int j=0;j<len;j++)
        {
            if(s[j]=='R') R++;
            if(s[j]=='B') B++;
            if(s[j]=='Y') Y++;
            if(s[j]=='G') G++;
        }
        printf("case #%d:\n",i);
        printf("%d %d %d %d\n",n-R,n-B,n-Y,n-G);
    }
    return 0;
}
