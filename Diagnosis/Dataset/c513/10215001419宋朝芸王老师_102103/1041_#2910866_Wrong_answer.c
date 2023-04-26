#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[51] = {'\0'};
    scanf("%s",a);

    int len = strlen(a);
    int ans = 0, i = 0;
    while(i < len){
        while(a[i] == '|') i++;
        while(a[i] == '-'){
            if(i > 0 && i+1 < len &&
            a[i-1] == '|' && a[i+1] == '|'){
                ans++;
                i++;
            }
            else i++;
        }
    }

    printf("%d",ans);


    return 0;
}
