#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int cas;
    scanf("%d",&cas);
    for(int q=0; q<cas; q++)
    {
        printf("case #%d:\n",q);
        char str[1000];
        scanf("%s",str);
        int len=strlen(str), cnt=1;
        for(int j=0; j<len; j++)
        {
            if(str[j]==str[j+1])
            {
                cnt++;
                if(cnt==255)
                {
                    printf("255%c",str[j]);
                    cnt=0;
                    continue;
                }
            }
            else
            {
                printf("%d%c",cnt,str[j]);
                cnt=1;
            }
        }
        printf("\n");
    }
}
