#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(){
    char c;
    char s[90];
    gets(s);
    int x=0;
    char s1[90]={'\0'};
    if(s[0]=='-'||s[0]=='+')x=x;
    else {s1[0]='+';x++;}
    int i;
    for(i=0;i<strlen(s);i++){
        if(s[i]=='=')break;
        else{
            s1[x]=s[i];
            x++;
        }
    }
    i=i+1;
    char s2[90]={'\0'};
    int y=0;
    if(s[i]=='-'||s[i]=='+')y=y;
    else {s2[0]='+';y++;}
    for(;i<strlen(s);i++){
        s2[y]=s[i];
        y++;
    }
    int x1=0,y1=0;
    for(int i=0;i<strlen(s1);i++){
        if(s1[i]=='+'){
            int j=i+1;
            int sum=0;
            while(isdigit(s1[j])){
                sum=sum*10+s1[j]-48;
                j=j+1;
            }
            if(islower(s1[j])){
                x1=x1+sum;
                c=s1[j];
            }
            else y1=y1+sum;
        }

        if(s1[i]=='-'){
            int j=i+1;
            int sum=0;
            while(isdigit(s1[j])){
                sum=sum*10+s1[j]-48;
                j=j+1;
            }
            if(islower(s1[j])){
                x1=x1-sum;
                c=s1[j];
            }
            else y1=y1-sum;
        }
    }
    int x2=0,y2=0;
    for(int i=0;i<strlen(s2);i++){
        if(s2[i]=='+'){
            int j=i+1;
            int sum=0;
            while(isdigit(s2[j])){
                sum=sum*10+s2[j]-48;
                j=j+1;
            }
            if(islower(s2[j])){
                x2=x2+sum;
                c=s2[j];
            }
            else y2=y2+sum;
        }

        if(s2[i]=='-'){
            int j=i+1;
            int sum=0;
            while(isdigit(s2[j])){
                sum=sum*10+s2[j]-48;
                j=j+1;
            }
            if(islower(s2[j])){
                x2=x2-sum;
                c=s2[j];
            }
            else y2=y2-sum;
        }
    }
    printf("%c=%.3f",c,(y2-y1)*1.0/(x1-x2));
}
