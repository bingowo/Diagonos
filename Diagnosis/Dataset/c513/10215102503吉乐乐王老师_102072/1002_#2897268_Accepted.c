#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct 
{
    char num;
    char cnt;
}node;
int main(){
    int t;scanf("%d",&t);getchar();int cas=0;
    while(t--){
        node albet[128];
        memset(albet,0,256);
        char s[61];
        gets(s);char *p=s;
        albet[*p].num=1,albet[*p].cnt=1;
        p++;int digit=0;
        while(*p){
            if(albet[*p].cnt==0){
                albet[*p].num=digit;
                albet[*p].cnt=1;
                digit=digit?digit+1:2;
            }
            else albet[*p].cnt++;
            p++;
        }
        if(digit<2)digit=2;
        unsigned long long int ret=0;
        p=s;
        while(*p){
            if(albet[*p].cnt){
                ret=ret*digit+albet[*p].num;
                albet[*p].cnt--;
            }
            p++;
        }
        printf("case #%d:\n%lld\n",cas++,ret);
    }
}