#include<stdio.h>
#include<string.h>

int main(){
    char s[110];
    gets(s);
    int max=0,m=0,l=strlen(s),i;
    for(i=0;i<l;i++){
        int t=s[i]-'0';
        if(t>=1&&t<=9)m++;
        else if(t==0&&s[i-1]-'0'>0&&s[i-1]-'0'<10)m++;
        else{
            if(m>max)max=m;
            m=0;
        }
    }
    if(i==l-1)max=m;
    printf("%d",max);
}