#include <stdio.h>
#include <string.h>
#include <math.h>
void numtostr(char *a,int n,int i){
    a[n]='\0';
    int t=0;
    while((n-1-t)!=-1){
        a[n-1-t]=(i&1)+'0';
        t++;
        i=(i>>1);
    }
}//生成n的第i个01串，对n来说它的所有01串是比他小的数的二进制形式d的集合，直接num to str方法
int main(){
    int n=0;
    char a[21]={0};
    while(1){
        scanf("%d",&n);
        if(n==-1) break;
        int cnt=0;
        for(int i=0;i<pow(2,n);i++){
            numtostr(a,n,i);
            if(strstr(a,"101")==NULL) cnt++;
        }
        printf("%d\n",cnt);
    }
}
//brute force算法直接满分没想到