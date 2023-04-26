#include <stdio.h>
#include <string.h>
#define N 222
char ans[N];
int main(){
//    char ans[N];
    char s[101] = {0};
    scanf("%s",s);
    int len = strlen(s);
    int k = 0;
    for(int i = 0;i<len; i++){
        if(i!=len-1){
            if(s[i]<s[i+1]){
                ans[k++] = s[i];
                ans[k++] = s[i];
            }
            else if(s[i]>s[i+1]){
                ans[k++] = s[i];
            }
            else{
                char c = s[i];
                int ret = 1;
                int j = i+1;
                for(; j<len; j++){
                    if(s[j]<c){
                        ret = 0;//保持不变
                        break;
                    }
                    else if(s[j]>c){
                        //复制
                        break;
                    }
                    else if(j==len-1) ret = 0;
                }
                if(ret){
                    while(i<j){
                        ans[k++] = s[i];
                        ans[k++] = s[i++];
                    }
                    i--;
                }
                else{
                    while(i<j){
                        ans[k++] = s[i++];
                    }
                    i--;
                }
            }
        }
        else{
            ans[k] = s[i];
        }
    }
    printf("%s",ans);
    return 0;
}