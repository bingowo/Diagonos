#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T,i,j;
    scanf("%d",&T);
    for(i = 0;i < T;i++){
        char str[100];
        long long int ans = 0;
        scanf("%s",str);
        //printf("strlen = %d\n",strlen(str));
        for(j = 0;j < strlen(str);j++){
            if(str[j] == '-')ans = ans*3 - 1;
            else if(str[j] == '0')ans = ans*3;
            else if(str[j] == '1')ans = ans*3 + 1;
            //printf("%lld",ans);
        }
        printf("case #%d:\n%d\n",i,ans);
        }
    return 0;
}
