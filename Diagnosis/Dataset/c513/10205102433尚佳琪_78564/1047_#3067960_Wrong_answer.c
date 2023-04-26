#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char s[1000];
        scanf("%s",s);
        int len=strlen(s);
        int cnt=1;
        printf("case #%d:\n",i);
        for(int i=0;i<len;i++)
        {
            if(s[i]==s[i+1])
            {
                cnt++;
                if(cnt==255)
                {
                    printf("255%c",s[i]);
                    cnt=0;
                }

            }
            else{
                printf("%d%c",cnt,s[i]);
                cnt=1;
            }
        }
        printf("\n");

    }
    return 0;
}
