#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ans[220],t[220];


int main()
{
    scanf("%s",ans);
    for (int i=0;i<strlen(ans);i++){
        strcpy(t,ans);
        for (int j=strlen(t)+1;j>i;j--)
            t[j]=t[j-1];
        if (strcmp(t,ans)<0) {
            i++;
            strcpy(ans,t);
        }
    }
    printf("%s\n",ans);
    return 0;
}
