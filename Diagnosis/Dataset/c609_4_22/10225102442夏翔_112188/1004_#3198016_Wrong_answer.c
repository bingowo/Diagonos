#include<stdio.h>
#include<string.h>
int main(){
    const char *s1="0123456789ABCDEf";
    int R1, R2;
    int temp, count=0;
    long long sum=0;
    char s[33];
    char ans[33];
    scanf("%d %s %d", &R1, &s, &R2);
    for(int i=0; i<strlen(s); i++){
        if(s[i]>='a' && s[i]<='z') temp=(int)s[i]-87;
        else if(s[i]>='A' && s[i]<='Z') temp=(int)s[i]-55;
        else temp=(int)s[i]-48;
        sum = sum*R1+temp;
    }
    while(sum!=0){
        ans[count++] = s1[sum%R2];
        sum /= R2;
    }
    if(count==0) printf("%d", 0);
    for(int i=0; i<count; i++){
        printf("%c", ans[count-1-i]);
    }
    return 0;
}