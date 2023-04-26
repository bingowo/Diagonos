#include <stdio.h>
#include <string.h>
#include <ctype.h>
void fun1(char s[101],int a[50],int len1){
    int sign = 1;
    int num = 0;
    int p=0;
    int m=0;
    for(int i=0;i<len1;i++){
        while (isdigit(s[i])){
            num = num *10+s[i]-'0';
            i++;
        }
        m = num;
        if(s[i] == '-'){
            sign = -1;
        }
        if(s[i] == '+'){
            sign = 1;
        }
        if(s[i]=='x'){
            i++;
            if(num ==0){
                m =1;
            }
            num = 0;
            if(s[i]=='^'){
                i++;
                while (isdigit(s[i])){
                    num = num *10+s[i]-'0';
                    i++;
                }
                a[num] = m*sign;
                m =0;
                num =0;
                p++;
            }else{
                a[1] = m;
                m =0;
                p++;
            }
        }
    }
    if(m){
        a[0] = m;
    }
}
int main() {
    char s1[101];
    char s2[101];
    int s[101] = {0};
    while (scanf("%s",s1)){
        scanf("%s",s2);
        int len1 = strlen(s1);
        int len2 = strlen(s2);
        int a[50] = {0};
        int b[50] = {0};
        fun1(s1,a,len1);
        fun1(s2,b,len2);
        for(int i=0;i<len1;i++){
            if(a[i]){
                for(int j=0;j<len2;j++){
                    if(b[j]){
                        s[i+j] = a[i]*b[i] +s[i+j];
                    }
                }
            }
        }
        int sign =0;
        for(int q = 100;q>=0&&(s[q]!=0);q--){
            if(sign){
                printf(" ");
            }
            printf("%d",s[q]);
            sign =1;
        }
        printf("\n");
    }
    return 0;
}
