#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int main(){
    char s[100],*s1;
    int n[128]={0},flag;
    while(gets(s)!=NULL){
        s1=s;
        if(*s1=='O'){
            s1=s1+4;
            flag=*s1;
            break;
        }
        if(*s1=='I'){
            char *s2,x[10];
            int i=0,num;
            s2=s1+6;
            s1=s1+3;
            while(isdigit(*s2)){
                x[i++]=*s2;
                s2++;
            }
            x[i]=0;
            num=atoi(x);
            n[*s1]=num;
        }
        else if(*s1=='M'&&*(s1+1)=='O'){
            char *s2;
            s2=s1+4;
            s1=s1+7;
            n[*s2]=n[*s1];
        }
        else if(*s1=='A'){
            char *s2;
            s2=s1+4;
            s1=s1+7;
            n[*s2]+=n[*s1];
        }
        else if(*s1=='S'){
            char *s2;
            s2=s1+4;
            s1=s1+7;
            n[*s2]-=n[*s1];
        }
        else if(*s1=='M'&&*(s1+1)=='U'){
            char *s2;
            s2=s1+4;
            s1=s1+7;
            n[*s2]*=n[*s1];
        }
        else if(*s1=='D'){
            char *s2;
            s2=s1+4;
            s1=s1+7;
            n[*s2]=n[*s2]/n[*s1];
        }
    }
    printf("%d\n",n[flag]);
    return 0;
}