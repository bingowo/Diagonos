#include <stdio.h>
#include <stdlib.h>

#define maxline 32

int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        int n;
        scanf("%d",&n);
        int binary_n[maxline];
        for(int i=0;i<maxline;i++)binary_n[i]=0;
        int i=maxline-1;
        while(n){
            binary_n[i--]=n%2;
            n/=2;
        }
        int maxlength=1,length=1,flag=-1;
        while(!binary_n[++flag]);
        for(;flag<maxline-1;flag++){
            if(binary_n[flag]!=binary_n[flag+1])length++;
            else length=1;
            if(maxlength<length)maxlength=length;
        }
        printf("%d\n",maxlength);
    }
    return 0;
}


