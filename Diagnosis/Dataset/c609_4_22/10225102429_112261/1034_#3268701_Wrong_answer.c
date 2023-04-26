#include <stdio.h>
#include <string.h>
#define N 100001
unsigned int ans[33333];
char s[N];
int main(){
    scanf("%s",s);
    int i = 0,len = strlen(s);
//    int ret = 1;//若读到合法开头，则置为0，否则置1
    for(int j = 0; j<len; j++){
        if(s[j]=='0'){
            if(j!=len-1&&s[j+1]=='x'){
                j+=2;
                int k = j;
                while(k<len){
                    if((s[k]>='0'&&s[k]<='9')||(s[k]>='a'&&s[k]<='f')){
                        k++;
                    }
                    else break;
                }
                k--;
                if(k<j) {
                    ans[i++] = -1;
                    continue;
                }
                unsigned int val = 0;
                int pow = 1;
                for(int t = k; t>=j; t--){
                    if(s[t]<='9'&&s[t]>='0') val+=pow*(s[t]-'0');
                    else val+=pow*(s[t]-'a'+10);
                    pow*=16;
                }
                ans[i++] = val;
            }
        }
    }
    int ret = 1;
    for(int t = 0; t<i; t++){
        if(ans[t]!=-1) {
            ret = 0;
            printf("%u ",ans[t]);
        }
    }
    if(ret) printf("-1");
    return 0;
}