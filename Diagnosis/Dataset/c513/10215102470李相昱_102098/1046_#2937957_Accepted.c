#include <stdio.h>
#include <string.h>
int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        char s[101];
        char c;
        int cnt = 0;
        while (scanf("%s",s)!=EOF){
            int len = strlen(s);
            for(int j=0;j<len;j++){
                if(s[j]>='A'&&s[j]<='Z'){
                    s[j] = s[j] + 32;
                }
            }
            if(strcmp(s,"the")!=0&&strcmp(s,"a")!=0&&strcmp(s,"an")!=0
            &&strcmp(s,"of")!=0&&strcmp(s,"for")!=0&&strcmp(s,"and")!=0){
                cnt++;
            }
            scanf("%c",&c);
            if(c=='\n'){
                break;
            }
        }
        printf("case #%d:\n%d\n",i,cnt);
    }
    return 0;
}
