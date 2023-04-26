#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
    int a[128]={0},k=0,t=0;
    char s[80],*s1,*s2,c;
    scanf("%s",s);
    s1=strchr(s,'=');
    s2=s1+1;
    s1--;
    while(s1>=s){
        if(isalpha(*s1)){
            c=*s1;
            int i=1;
            s1--;
            if(isdigit(*s1))i=0;
            while(isdigit(*s1)&&s1>=s){
                i=10*i+*s1-'0';
                s1--;
            }
            if(s1>=s&&*s1=='-')i=-i;
            a[c]+=i;
        }
        else if(isdigit(*s1)){
            int i=0;
            while(isdigit(*s1)&&s1>=s){
                i=10*i+*s1-'0';
                s1--;
            }
            if(s1>=s&&*s1=='-')i=-i;
            t-=i;
        }
        if(s1<s)break;
        else s1--;
    }
    s1=s+strlen(s)-1;
    while(s1>=s2){
        if(isalpha(*s1)){
            char c=*s1;
            int i=1;
            s1--;
            if(isdigit(*s1))i=0;
            while(isdigit(*s1)&&s1>=s2){
                i=10*i+*s1-'0';
                s1--;
            }
            if(s1>=s&&*s1=='-')i=-i;
            a[c]-=i;
        }
        else if(isdigit(*s1)){
            int i=0;
            while(isdigit(*s1)&&s1>=s2){
                i=10*i+*s1-'0';
                s1--;
            }
            if(s1>=s&&*s1=='-')i=-i;
            t+=i;
        }
        s1--;
    }
    double q=1.0*t/a[c];
    printf("%c=%.3lf",c,q);
    return 0;
}