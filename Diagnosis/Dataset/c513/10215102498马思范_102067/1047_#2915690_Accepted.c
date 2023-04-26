#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int t;
    char s[501];
    int a[501];
    int flag=0;
    int b=0;
    for(int k=0;k<501;k++)
    {
        a[k]=0;
    }
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%s",s);
        int len=strlen(s);
        printf("case #%d:\n",i);
        for(int p=0;p<len;p++)
        {
            if(s[p]==s[p+1])
            {
                flag++;
                if(flag==255)
                {
                    printf("%d%c",255,s[p]);
                    flag=0;
                }
            }
            else
            {
                printf("%d%c",flag+1,s[p]);
                flag=0;
            }
        }
        printf("\n");
    }
    return 0;
}