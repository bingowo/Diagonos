#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        char s[501]={'\0'};
        scanf("%s",s);
        int l=strlen(s);
        int cnt=1;
        int j;
        for(j=1;j<l;j++)
        {
            if(s[j]==s[j-1])
            {
                cnt++;
                if(cnt==255)
                {
                    printf("255%c",s[j]);
                    cnt=1;
                }
            }
            else
            {
                printf("%d%c",cnt,s[j-1]);
                cnt=1;
            }
        }
        printf("%d%c\n",cnt,s[j-1]);
    }
    return 0;
}
