#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int main(){
    char s[100],*s1;
    int n[128]={0};
    while(gets(s)!=NULL){
        s1=s;
        if(*s1=='O'&&*(s1+1)=='U'){
            s1=s1+4;
            printf("%d\n",n[*s1]);
        }
        else if(*s1=='I'){
            char *s2;
            int i=0,num;
            s2=s1+6;
            s1=s1+3;
            num=atoi(s2);
            n[*s1]=num;
        }
        else if(*s1=='M'&&*(s1+1)=='O'&&*(s1+2)=='V'){
            char *s2;
            s2=s1+4;
            s1=s1+7;
            n[*s2]=n[*s1];
        }
        else if(*s1=='A'){
            char *s2;
            s2=s1+4;
            s1=s1+7;
            if(strlen(s1)==2)n[*s2]+=n[*s1];
            else{
                char *s3=s1+3;
                n[*s2]=n[*s1]+n[*s3];
            }
        }
        else if(*s1=='S'){
            char *s2;
            s2=s1+4;
            s1=s1+7;
            if(strlen(s1)==2)n[*s2]-=n[*s1];
            else{
                char *s3=s1+3;
                n[*s2]=n[*s1]-n[*s3];
            }
        }
        else if(*s1=='M'&&*(s1+1)=='U'){
            char *s2;
            s2=s1+4;
            s1=s1+7;
            if(strlen(s1)==2)n[*s2]*=n[*s1];
            else{
                char *s3=s1+3;
                n[*s2]=n[*s1]*n[*s3];
            }
        }
        else if(*s1=='D'){
            char *s2;
            s2=s1+4;
            s1=s1+7;
            if(strlen(s1)==2)n[*s2]=n[*s2]/n[*s1];
            else{
                char *s3=s1+3;
                n[*s2]=n[*s1]/n[*s3];
            }
        }
        else if(*s1=='X'&&*(s1+1)=='C'){
            char *s2;
            s2=s1+5;
            s1=s1+8;
            int q=n[*s1];
            n[*s1]=n[*s2];
            n[*s2]=q;
        }
        else if(*s1=='X'&&*(s1+1)=='0'){
            char *s2;
            s2=s1+4;
            s1=s1+7;
            if(strlen(s1)==2)n[*s2]=n[*s2]^n[*s1];
            else{
                char *s3=s1+3;
                n[*s2]=n[*s1]^n[*s3];
            }
        }
        else if(*s1=='O'&&*(s1+1)=='R'){
            char *s2;
            s2=s1+3;
            s1=s1+6;
            if(strlen(s1)==2)n[*s2]=n[*s2]|n[*s1];
            else{
                char *s3=s1+3;
                n[*s2]=n[*s1]|n[*s3];
            }

        }
        else if(*s1=='M'&&*(s1+1)=='O'&&*(s1+2)=='D'){
            char *s2;
            s2=s1+4;
            s1=s1+7;
            if(strlen(s1)==2)n[*s2]=n[*s2]%n[*s1];
            else{
                char *s3=s1+3;
                n[*s2]=n[*s1]%n[*s3];
            }
        }
    }
    return 0;
}