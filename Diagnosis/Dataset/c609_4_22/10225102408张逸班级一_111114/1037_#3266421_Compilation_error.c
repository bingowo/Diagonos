#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char s[1000100];
    scanf("%s",s);
    int len=strlen(s);
    char cc[len+1];//逐个扫描并检测，另开字符数组用strchr
    int max=1,begin=0,end=0,mb=0,me=0;
    int n=0;
    for(int i=0;i<len;i++){
        int c=s[i];
        if(!strchr(cc,c))//没重复
            {cc[n]=s[i];end++;n++;}
        else {
            end++;
            begin=end;//重置计数器
            strset(cc,'0');n=0;
        }
        if(end-begin+1>max){
                max=end-begin+1;
                mb=begin;me=end;
            }
    }
    for(int i=mb;i<=me;i++)
    {
        printf("%c",s[i]);
    }
    return 0;
}