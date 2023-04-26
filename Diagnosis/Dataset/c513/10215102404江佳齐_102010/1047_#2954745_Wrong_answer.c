#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        printf("case #%d:\n",i);
        char s[500];
        int count=0;
        scanf("%s",s);
        int len=strlen(s),j=0;
        while(j<len)
        {
            int temp=s[j];
            while(s[j]==temp)
            {
                if(count==255) break;
                j++;count++;
            }
            printf("%d%c",count,s[j-1]);
            count=0;
        }
    }
    return 0;
}
