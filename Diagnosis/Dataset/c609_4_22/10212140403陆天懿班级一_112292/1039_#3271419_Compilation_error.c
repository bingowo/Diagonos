#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>

#define N 85

int Min(int a,int b){return a<b?a:b;}
int Max(int a,int b){return a>b?a:b;}

int LFind(char* str, char* key, int ls, int lk){
    for(int i=0,f=1;i<=ls-lk;i++,f=1){
        for(int j=0;j<lk;j++){
            if(str[i+j]!=key[j]){
                f=0;
                break;
            }
        }
        if(f)
            return i;
    }
    return -1;
}

int RFind(char* str, char* key, int ls, int lk){
    for(int i=ls-lk,f=1;i>=0;i--,f=1){
        for(int j=0;j<lk;j++){
            if(str[i+j]!=key[j]){
                f=0;
                break;
            }
        }
        if(f)
            return i;
    return -1;
}

int main(){
    int pros,la,lb,ls,al,bl,ar,br;
    char str[N],a[N],b[N];
    scanf("%d",&pros);
    for(int cnt=0;cnt<pros;cnt++){
        scanf("%s%s%s",a,b,str);
        la=strlen(a);
        lb=strlen(b);
        ls=strlen(str);
        al=LFind(str,a,ls,la);
        bl=LFind(str,b,ls,lb);
        ar=RFind(str,a,ls,la);
        br=RFind(str,b,ls,lb);
        printf("case #%d:\n",cnt);
        if(la<0||lb<0)
            printf("0\n");
        else
            printf("%d\n",Max(ar-bl-lb,br-al-la));
    }

    return 0;
}