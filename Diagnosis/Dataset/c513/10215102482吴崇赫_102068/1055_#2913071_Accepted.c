#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 1000005


int norepeat(char* s,int left,int right)
// find repeat char  left<=i<=right
{
    int a[128]={0};
    for(int i=left;i<=right;++i){
        a[s[i]]++;
        if(a[s[i]]>1)return 0;
    }
    return 1;
}

int main()
{
    char s[N]={'\0'};
    scanf("%s",s); // input s
    int sign=0;  // record the start index of subs
    int max=0; // record the max length of subs
    int pi=0,pj=0;// pi->s and pj->read the follow char

    while(pi<strlen(s)){
        while(norepeat(s,pi,pj)&&pj<strlen(s))pj++;
        if(pj-pi>max){
            sign=pi;max=pj-pi;
        }
        pi++;
        pj=pi;
    }
    char ret[N]={'\0'};
    int pr=0;
    for(int i=sign;i<sign+max;++i)ret[pr++]=s[i];
    printf("%s",ret);
    return 0;
}
