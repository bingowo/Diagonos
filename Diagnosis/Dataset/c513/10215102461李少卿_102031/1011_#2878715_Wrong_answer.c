#include<stdio.h>
#include<string.h>
int main(){
    char s[40],s1[30],s2[30],*c1,*c2;
    int i=0,p=0,k;
    long long int A=0,B=0,C=1;
    scanf("%s",s);
    c1=s,c2=s;
    while(*c1!='.'&&*c1)c1++;
    while(*c2)c2++;
    if(c1<c2){
    while(c1>s){
        s1[i]=s[i];
        i++,c1--;
    }
    s1[i]=0;
    while(c2>c1){
        i++;
        s2[p++]=s[i];
        c2--;
    }
    s2[i]=0;
    c1=s1,c2=s2;
    while(*c1){
        if(*c1=='2')A=-1+A*3;
        else if(*c1=='1')A=1+A*3;
        else A=A*3;
        c1++;
    }
    k=strlen(s2);
    while(k-->0)C=C*3;
    while(*c2){
        if(*c2=='2')B=-1+B*3;
        else if(*c2=='1')B=1+B*3;
        else B=B*3;
        c2++;
    }
    if(A<0&&B>0)B=C-B,A++;
    if(B<0&&A!=0)A--,B+=C;
    if(A!=0)printf("%lld %lld %lld",A,B,C);
    else printf("%lld %lld",B,C);
    }
    else{
        c1=s;
        while(*c1){
        if(*c1=='2')A=-1+A*3;
        else if(*c1=='1')A=1+A*3;
        else A=A*3;
        c1++;
        }
    printf("%lld",A);
    }
    return 0;
}