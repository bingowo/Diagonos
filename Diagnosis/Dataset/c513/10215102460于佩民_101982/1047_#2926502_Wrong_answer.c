#include <stdio.h>
#include <string.h>

int main(){
    int num,now=0,i=0,cnt=1;
    char s[501];
    scanf("%d\n",&num);
    while(now<num){
        gets(s);
        printf("case #");
        printf("%d:\n",now);
        while(i!=strlen(s)-1){
            if(s[i]==s[i+1]) {
                cnt++;
                if(cnt==255){
                    printf("%d",cnt);
                    printf("%c",s[i]);
                    cnt=0;
                }
                i++;}
            else if(s[i]!=s[i+1]){
                printf("%d",cnt);
                printf("%c",s[i]);
                cnt=1;
                i++;
            }
        }
        if(i==strlen(s)-1){
            if(cnt==1) {
                printf("%d",cnt);
                printf("%c\n",s[i]);
            }
            if(cnt!=1){
                printf("%d",cnt);
                printf("%c\n",s[i]);
            }
        }
        for(i=0;i<500;i++) s[i]='\0';
        now++;
        cnt=1;
        i=0;
    }
    return 0;
}