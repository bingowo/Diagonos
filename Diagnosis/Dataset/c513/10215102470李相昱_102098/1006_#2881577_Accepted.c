#include <stdio.h>
#include <string.h>

int main() {
    int t ;
    scanf("%d",&t);
    int i = 0;
    for(;i<t;i++){
        char s[30];
        scanf("%s",s);
        int q,ret = 0;
        for(q= 0;q< strlen(s);q++){
            if(s[q] == '-'){
                ret = ret*3-1;
            }
            else{
                ret = ret*3+s[q]-'0';
            }
        }
        printf("case #%d:\n%d\n",i,ret);

    }

    return 0;
}
