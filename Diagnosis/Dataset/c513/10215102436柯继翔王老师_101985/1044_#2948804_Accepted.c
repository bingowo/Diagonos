#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[100000];
    scanf("%s",s);
    int len = strlen(s);
    int flag = 1;
    for(int i = 0;i < len;i++){
        while(i + 1 < len){
            if(s[i] == '0' && s[i + 1] == 'x'){
                break;
            }
            i++;
        }
        i = i + 2;
        unsigned int ans = 0;
        int f = 0;
        while(i < len){
            if(s[i] >= '0' && s[i] <= '9'){
                flag = 0;
                f = 1;
                ans = ans * 16 + s[i] - '0';
            }else if(s[i] >= 'a' && s[i] <= 'f'){
                flag = 0;
                f = 1;
                ans = ans * 16 + s[i] - 'a' + 10;
            }else{
                if(f)printf("%u ",ans);
                break;
            }
            i++;
        }
        if(i == len)if(f)printf("%u ",ans);
    }
    if(flag)printf("-1");
    return 0;
}
