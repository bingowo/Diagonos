#include <stdio.h>
#include <string.h>
int main() {
    char s[101];
    scanf("%s",s);
    int len= strlen(s),sign;
    int ret[101]={0};
    int cnt=0;
    for(int i=0,j=len-1;i<len;i++,j--){
        ret[j]=s[i]-'0';
        cnt = cnt+ret[j];
    }
    do{
        sign=0;
        int add;
        if(cnt%9==8){
            add=2;
        }else{
            add=1;
        }
        cnt = cnt+add;
        int carry=add,p=0;
        for(;p<len;p++){
            ret[p]=ret[p]+carry;
            carry=ret[p]/10;
            ret[p]=ret[p]% 10;
            if(ret[p]==9){
                sign=1;
                break;
            }
        }
        if(sign==0){
            if(carry){
                ret[p]=carry;
                len=p;
            }
        }
    } while (sign);

    for(int t=len-1;t>=0;t--){
        printf("%d",ret[t]);
    }
    return 0;
}
