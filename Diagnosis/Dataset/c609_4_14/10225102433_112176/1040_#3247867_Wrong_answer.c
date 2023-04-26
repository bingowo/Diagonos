#include<stdio.h>
#include<string.h>
int main(){
    int T;
    scanf("%d", &T);
    char s[201] = {0};
    int nums[26] = {0};
    getchar();
    for(int i=0; i<T; i++){
        memset(nums, 0, sizeof(nums));
        gets(s);
        for(int j=0; j<strlen(s); j++){ //璇诲瓧绗?
            if(s[j]!=' ') nums[(int)s[j]-65]++;
        }
        int p=0;
        printf("case #%d:\n", i);
        for(int j=0; j<26; j++){ //浠嶢鍒癦涓€涓釜濉厖
            printf("%c ",s[0]);
            while(nums[j]!=0){
                if(s[p]>='A' &&s[p]<='Z'){
                    printf("%c", (char)(j+65));
                    nums[j]--;
                }else printf("%c", s[p]);
                p++;
            }
        }
        if(p<strlen(s)) printf("%s\n", s+p);//琛ュ厖杈撳嚭
        else printf("\n");
        memset(s,'\0',sizeof(s));
    }
    return 0;
}