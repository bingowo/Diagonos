#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[50];
    scanf("%s",s);
    int ans = 0;
    for(int i = 0;i < strlen(s);i++){
        int num = 1;
        for(int j = i + 1;j < strlen(s);j++){
            if(s[j] != s[j - 1]){
                num++;
            }else{
                break;
            }
        }
        if(num > ans)ans = num;
    }
    printf("%d",ans);
}
