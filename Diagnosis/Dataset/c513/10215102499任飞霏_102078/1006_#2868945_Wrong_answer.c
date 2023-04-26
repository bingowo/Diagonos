#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T,i,j,k;
    scanf("%d",&T);
    for(i = 0;i < T;i++){
        char str[100];
        int ans;
        scanf("%s",str);
        for(j = strlen(str) - 1;j >= 0;j--){
            if(str[j] = '-')ans = ans*3 - 1;
            else if(str[j] = '0')ans = ans*3;
            else if(str[j] = '1')ans = ans*3 + 1;
        }
        printf("case #%d:\n%d",i,ans);
        }
    return 0;
}
