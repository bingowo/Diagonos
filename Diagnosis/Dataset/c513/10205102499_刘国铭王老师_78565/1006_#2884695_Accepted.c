#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    char s[1000];
    for(int i=0;i<T;i++)
    {
        scanf("%s",&s);
        int len=strlen(s);
        double flag=1;
        int res=0;
        for(int j=len-1;j>=0;j--)
        {

            if(s[j]=='1')
                res=1*flag+res;
            else if(s[j]=='0')
                res=0*flag+res;
            else
                res=(-1)*flag+res;
            flag*=3;
        }
        printf("case #%d:\n",i);
        printf("%d\n",res);

    }
    return 0;
}
