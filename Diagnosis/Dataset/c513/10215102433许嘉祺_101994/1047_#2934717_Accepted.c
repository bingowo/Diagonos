#include <stdio.h>
#include <stdlib.h>
#include<string.h>



int main()
{
    int n;
    scanf("%d",&n);
    char s[502];
    for (int i=0;i<n;i++){
        scanf("%s",s);
        printf("case #%d:\n",i);
        for (int j=0;j<strlen(s);j++){
            int len=1;
            while(len<255&&j<strlen(s)&&s[j]==s[j+1]) {j++;len++;}
            printf("%d%c",len,s[j]);
        }
        printf("\n");

    }
    return 0;
}
