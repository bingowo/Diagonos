#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define  num 501

long long exa(char *p,long long st,long long fi,char z)//检查在之前的字符中有没有重复的，有则返回位置
{
    for(long long i=st;i<=fi;i++)
    {
        if(p[i]==z)return i;
    }
    return -1;
}

int main()
{
    long long len[2] = {0};
    char *p = (char*)malloc(sizeof(char)*1e7);
    scanf("%s",p);
    long long st = 0,fi = 0;
    while(fi<strlen(p)-1)
    {
        long long mid;
         if((mid = exa(p,st,fi,p[fi+1]))!=-1)
         {
             if(len[1]-len[0]<fi-st)
             {
                 len[0]=st;
                len[1]=fi;
             }
             st = mid+1;
             fi++;
         }
         else
         {
             fi++;
         }
    }
    if(len[1]-len[0]<fi-st)
             {
                 len[0]=st;
                len[1]=fi;
             }
    for(long long k=len[0];k<=len[1];k++)
    {
        printf("%c",p[k]);
    }
    return 0;
    }
