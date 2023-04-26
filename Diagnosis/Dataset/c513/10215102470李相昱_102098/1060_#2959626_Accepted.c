#include <stdio.h>
#include <ctype.h>
int main() {
    char c;
    int sign =0;
    int cnt=0,cnt1=0;
    while ((c = getchar())&&(c!='\n')){
        if(isdigit(c)){
            if(sign){
                cnt1++;
            }else{
                if(c!='0'){
                    sign =1;
                    cnt1++;
                }
            }
        }else{
            cnt = cnt1>cnt?cnt1:cnt;
            cnt1 =0;
            sign=0;
        }
    }
    if(cnt1){
        cnt = cnt1>cnt?cnt1:cnt;
    }
    printf("%d",cnt);
    return 0;
}
