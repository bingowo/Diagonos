#include <stdio.h>
#include <string.h>
int add(int len,int *p){
    int p2[10]={0};
    for(int j=0;j<len;j++){
        p2[j] = p[j];
    }
    int carry=0,i=0;
    for(;i<len;i++){
        p[i] = p2[i]+p2[len-1-i]+carry;
        carry = p[i]/10;
        p[i] = p[i]%10;
    }
    if (carry){
        p[i]=carry;
        len++;
    }
    return len;
}
int main() {
    char s[10];
    int s2[10];
    scanf("%s",s);
    int len= strlen(s);
    for(int i=0;i<len;i++){
        s2[i] = s[len-1-i]-'0';
    }
    int num=0;
    int sign =1;
    while (sign){
        int j=0;
        for(;j<len/2;j++){
            if(s2[j]!=s2[len-1-j]){
                num++;
                len = add(len,s2);
                break;
            }
        }
        if (j==len/2){
            sign=0;
        }
    }
    printf("%d ",num);
    for(int m=0;m<len;m++){
        printf("%d",s2[m]);
    }

    return 0;
}
