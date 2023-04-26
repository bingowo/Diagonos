#include <stdio.h>
#include <string.h>
int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        char s[501];
        scanf("%s",s);
        printf("case #%d:\n",i);
        for(int j =1;j< strlen(s);j++){
            int cnt =1;
            while(s[j] == s[j-1]){
                cnt ++;
                if(cnt >255){
                    printf("255%c",s[j]);
                    cnt = cnt-255;
                }
                j++;
            }
            printf("%d%c",cnt,s[j-1]);
        }
        if(s[strlen(s)-1]!=s[strlen(s)-2]){
            printf("1%c",s[strlen(s)-1]);
        }
        
        printf("\n");
    }
    return 0;
}