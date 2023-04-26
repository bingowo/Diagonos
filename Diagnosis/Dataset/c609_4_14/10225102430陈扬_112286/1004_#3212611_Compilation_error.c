#include <stdio.h>
#include <string.h>
int main(){
    char *s1="0123456789ABCDEF";
    int A, B;
    int temp=0, count=0;
    long long sum=0;
    char s[35];
    char ans[35];
    scanf("%d %s %d", &A, &s, &B);
    for(int i=0; i<strlen(s); i++){
        if(s[i]>='A' && s[i]<='Z') temp=(int)s[i]-55;
        else if(s[i]>='a' && s[i]<='z') temp=(int)s[i]-87;
        else temp=(int)s[i]-48;
        sum = sum*R1+temp;
    }
    while(sum!=0){
        ans[count++] = s1[sum%B];
        sum /= B;
    }
    if(count==0) printf("%d", 0);
    for(int i=0; i<count; i++){
        printf("%c", ans[count-1-i]);
    }
    return 0;
}