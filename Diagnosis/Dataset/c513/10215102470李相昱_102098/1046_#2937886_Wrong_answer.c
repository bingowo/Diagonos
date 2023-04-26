#include <stdio.h>
#include <string.h>
int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        char s[101];
        char c;
        int cnt = 0;
        while (scanf("%s",s)!=EOF&& scanf("%c",&c)&&c!='\n'){
            if(strcmp(s,"the")!=0&&strcmp(s,"a")!=0&&strcmp(s,"an")!=0
            &&strcmp(s,"of")!=0&&strcmp(s,"for")!=0&&strcmp(s,"and")!=0){
                cnt++;
            }
        }
        printf("case #%d:\n%d\n",i,cnt);
    }
    return 0;
}
