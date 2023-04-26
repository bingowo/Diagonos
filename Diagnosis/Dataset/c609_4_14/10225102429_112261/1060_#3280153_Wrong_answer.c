#include <stdio.h>
#include <string.h>
#define N 222
char ans[N];
int main(){
    char s[101] = {0};
    char Ans[N] = {0};
    scanf("%s",s);
    int len = strlen(s);
    int k = 0;
    for(int i = 0;i<len; i++){
        if(i!=len-1){
            if(s[i]<=s[i+1]){
                strcpy(Ans,ans);
                Ans[k] = s[i];
                Ans[k+1] = s[i];
                int kk = k+2;
                for(int j = i+1; j<len; j++){
                    Ans[kk++] = s[j];
                }
                if(strcmp(Ans,s)<=0){
                    ans[k++] = s[i];
                    ans[k++] = s[i];
                }
                else{
                    ans[k++] = s[i];
                }
            }
            else ans[k++] = s[i];
        }
        else{
            if(s[i]!=s[i-1]) ans[k] = s[i];
        }
    }
    printf("%s",ans);
    return 0;
}