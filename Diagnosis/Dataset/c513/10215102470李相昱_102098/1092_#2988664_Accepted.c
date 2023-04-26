#include <stdio.h>
#include <string.h>
int main() {
    long long int a=1;
    char s[1001];
    scanf("%s",s);
    int len= strlen(s);
    int num;
    int ret[500]={1},len1=1;
    for(int i=0;i<len;i++){
        num=1;
        if(i-1>=0&&s[i]!=s[i-1]){
            num++;
        }if((i+1<len)&&(s[i]!=s[i+1])&&(s[i-1]!=s[i+1])){
            num++;
        }
        if(num!=1){
            for(int j=0;j<len1;j++){
                ret[j]=ret[j]*num;
            }
            int carry=0, j=0;
            for(;j<len1;j++){
                ret[j]=ret[j]+carry;
                carry = ret[j]/10;
                ret[j]=ret[j]%10;
            }
            if(carry){
                ret[j]=carry;
                len1++;
            }
        }
    }
    for(int p=len1-1;p>=0;p--){
        printf("%d",ret[p]);
    }
    printf("\n");
    return 0;
}