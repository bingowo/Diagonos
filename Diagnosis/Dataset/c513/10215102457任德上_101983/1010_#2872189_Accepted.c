#include <stdio.h>
#include <string.h>
#include<stdlib.h>
void binary(int n,int m,char *s){
    while(m-->0){
        *s=n%2+'0';
        n=n/2;
        s++;
    }
    *s=0;
}
int main(){
    char n[501],s[2200],*s1,*s2,c,m1[2],m2[3],m3[4];
    s[0]=0;
    scanf("%s",n);
    s1=n;
    int length,p;
    length=strlen(n);
    while(*s1)s1++;
    if(length%3==1){
        length--;
        char End[11];
        s1--;
        strncpy(m1,s1,1);
        p=atoi(m1);
        binary(p,4,End);
        strcat(s,End);
       }
    else if(length%3==2){
        length-=2;
        char End[11];
        s1=s1-2;
        strncpy(m2,s1,2);
        p=atoi(m2);
        binary(p,7,End);
        strcat(s,End);
    }
    while(length){
        length-=3;
        char End[11];
        s1=s1-3;
        strncpy(m3,s1,3);
        p=atoi(m3);
        binary(p,10,End);
        strcat(s,End);
    }
    char End[11];
    binary(strlen(n),10,End);
    strcat(s,End);
    strcat(s,"1000");
    s1=s,s2=s;
    while(*s1)s1++;
    s1--;
    while(s1-s2>0){
        c=*s1;
        *s1=*s2;
        *s2=c;
        s1--;
        s2++;
    }
    printf("%s",s);
    return 0;
}
