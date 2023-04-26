#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char s[100000];
    gets(s);char *p=s;
    unsigned int ret[1000];int idx=0;
    while(*p){
        if(*p=='x'&&*(p-1)=='0'){
            unsigned int temp=0;
            p++;int flag=0;
            while((*p>='0'&&*p<='9')||(*p>='a'&&*p<='f')){
                flag=1;
                if(*p>='0'&&*p<='9')temp=temp*16+*p-'0';
                else temp=temp*16+*p-'a'+10;
                p++;
            }
            if(flag){
                ret[idx]=temp;idx++;}
        }
        else p++;
    }
    if(idx==0)printf("-1");
    else{
        for(int i=0;i<idx;i++){
            printf("%u",ret[i]);
            if(i==idx-1)putchar('\n');
            else putchar(' ');
        }
    }
}